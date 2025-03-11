`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/19 14:46:47
// Design Name: 
// Module Name: SET_position
// Project Name: 
// Target Devices: 
// Tool Versions: 
// Description: 
// 
// Dependencies: 
// 
// Revision:
// Revision 0.01 - File Created
// Additional Comments:
// 
//////////////////////////////////////////////////////////////////////////////////


module SET_position(
    input              clk,
    input              rstn,
    
    input [7:0] x_position_start,
    input [8:0] y_position_start,
    input [7:0] x_position_finish,
    input [8:0] y_position_finish,
    input position_en,
    output reg [15:0] LCD_DATA_position,
    output reg LCD_RS_position,
    output reg LCD_CS_position,
    output reg LCD_WR_position,
    output reg data_stop
    );
    
localparam  IDLE  = 6'b000001;
localparam  WAIT  = 6'b000010;
localparam  WR_L  = 6'b000100;
localparam  WR_H  = 6'b001000;
localparam  ADDR  = 6'b010000;


reg [10:0] cur_state, nxt_state;
reg [3:0]  trans_times;
reg rs_reg;
reg [15:0] data_reg;
always @(*)
begin
if((trans_times==4'd0)||(trans_times==4'd5)||(trans_times==4'd10))
begin
rs_reg=0;end
else rs_reg=1;
end

always @(*)
begin
case(trans_times)
4'd0:data_reg=16'h002A;
4'd1:data_reg=16'd0;
4'd2:data_reg={8'd0,x_position_start[7:0]};
4'd3:data_reg=16'd0;
4'd4:data_reg={8'd0,x_position_finish[7:0]};
4'd5:data_reg=16'h002B;
4'd6:data_reg={15'd0,y_position_start[8]};
4'd7:data_reg={8'd0,y_position_start[7:0]};
4'd8:data_reg={15'd0,y_position_finish[8]};
4'd9:data_reg={8'd0,y_position_finish[7:0]};
4'd10:data_reg=16'h002C;
default:data_reg=16'd0;
endcase
end


always @ (*) begin
    if (cur_state[0])
        nxt_state = position_en ? WAIT : IDLE;
    else if (cur_state[1]) 
        nxt_state = WR_L;
    else if (cur_state[2])
        nxt_state = WR_H;
    else if (cur_state[3])
        nxt_state = ADDR;
    else if (cur_state[4])
        nxt_state = data_stop ? IDLE : WAIT ;   
    else nxt_state = IDLE;
end

always @ (posedge clk or negedge rstn) begin
    if (~rstn) cur_state <= IDLE;
    else cur_state <= nxt_state;
end

always @(posedge clk or negedge rstn) begin
    if (~rstn) begin
        LCD_CS_position<=1'b1;
        LCD_WR_position<=1'b1;
        data_stop<=1'b0;
        trans_times<=4'd0;
        LCD_DATA_position<=16'd0;
        LCD_RS_position<=1'd0;
        
    end else begin
    if(position_en) begin
        case (nxt_state)
            IDLE: begin 
                LCD_CS_position<=1'b1;
                LCD_WR_position<=1'b1;
                data_stop<=1'b0;
                trans_times<=4'd0;
                LCD_DATA_position<=16'd0;
                LCD_RS_position<=1'd0;
            end
            WAIT: begin 
                LCD_CS_position<=1'b0;
                LCD_WR_position<=1'b1;
                
                
            end
            WR_L: begin 
                LCD_CS_position<=1'b0;
                LCD_WR_position<=1'b0;
                LCD_DATA_position<=data_reg;
                LCD_RS_position<=rs_reg;
            end
            WR_H: begin 
                LCD_CS_position<=1'b0;
                LCD_WR_position<=1'b1;
                
            end
            ADDR: begin 
                LCD_CS_position<=1'b0;
                LCD_WR_position<=1'b1;
                if(trans_times<10) begin
                trans_times<=trans_times+4'd1; data_stop<=1'b0;end
                else begin
                trans_times<=4'd0;data_stop<=1'd1;end
                
            end
            default: begin 
                LCD_CS_position<=1'b1;
                LCD_WR_position<=1'b1;
                
            end
        endcase
        end
    end
end
endmodule
