`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/18 09:39:23
// Design Name: 
// Module Name: LCDcrtl
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


module LCDcrtl(
    input clk,
    input rstn,
    input [30:0] LCD_CRTL,
    input run_finish,
    input ini_finish,
    input LCDcrtl_en,
    input POSITION_FINISH,
    output reg data_en,
    output reg position_en,
    output reg ini_en,
    output [7:0] run_addr_begin,
    output [7:0] run_addr_end,
    output reg LCD_MODE,
    output reg sel
    
    );
    
localparam  IDLE  = 4'd1;

localparam  WAIT_INI  = 4'd2;
localparam  INI  = 4'd3;
localparam  WAIT_CRTL  = 4'd4;
localparam  CRTL_POSITION  = 4'd5;
localparam  RUN  = 4'd6;



reg [3:0] cur_state, nxt_state;

always @ (*) begin
    case(cur_state)
    IDLE:nxt_state=WAIT_INI;
    WAIT_INI:nxt_state=INI;
    INI:nxt_state=ini_finish ? WAIT_CRTL:INI;
    WAIT_CRTL:nxt_state=LCDcrtl_en ? CRTL_POSITION:WAIT_CRTL;
    CRTL_POSITION:nxt_state=POSITION_FINISH ? RUN:CRTL_POSITION;
    RUN:nxt_state=run_finish ? WAIT_CRTL:RUN;
    default:nxt_state=IDLE;
    
    endcase
end

always @ (posedge clk or negedge rstn) begin
    if (~rstn) cur_state <= IDLE;
    else cur_state <= nxt_state;
end

always @(posedge clk or negedge rstn) begin
    if (~rstn) begin
        
        ini_en<=0;
        LCD_MODE<=0;
        sel<=1;
        data_en<=0;
        position_en<=0;
    end else begin
        case (nxt_state)
            IDLE: begin 
                
                ini_en<=0;
                LCD_MODE<=0;
                sel<=1;
                data_en<=0;
                position_en<=0;
            end
            WAIT_INI: begin 
                
            end
            INI: begin 
                
                ini_en<=1;
            end
            WAIT_CRTL: begin 
                data_en<=0;
                position_en<=0;
                ini_en<=0;
                LCD_MODE<=1;
            end
            CRTL_POSITION:begin
                data_en<=0;
                ini_en<=0;
                
                sel<=1;
                position_en<=1;
            end
            RUN: begin 
                position_en<=0;
                ini_en<=0;
                sel<=0;
                data_en<=1;
            end
            default: begin 
                
            end
        endcase
    end
end
    
    
endmodule
