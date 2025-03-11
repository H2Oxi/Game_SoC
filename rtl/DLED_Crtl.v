`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/22 10:41:49
// Design Name: 
// Module Name: DLED_Crtl
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


module DLED_Crtl(
    input clk,
    input rstn,
    input [31:0] DLED_reg,
    output reg [7:0] digitalled,
    output reg [5:0] digitalled_sel
    );
    wire [7:0] reg_led1,reg_led2,reg_led3,reg_led4,reg_led5,reg_led6;
    
    DLED_Decoder decoder1(
    .num(DLED_reg[24:21]),
    .rstn(rstn),
    .num_led(reg_led1)
    );
    DLED_Decoder decoder2(
    .num(DLED_reg[20:17]),
    .rstn(rstn),
    .num_led(reg_led2)
    );
    DLED_Decoder decoder3(
    .num(DLED_reg[16:13]),
    .rstn(rstn),
    .num_led(reg_led3)
    );
    DLED_Decoder decoder4(
    .num(DLED_reg[12:9]),
    .rstn(rstn),
    .num_led(reg_led4)
    );
    DLED_Decoder decoder5(
    .num(DLED_reg[8:5]),
    .rstn(rstn),
    .num_led(reg_led5)
    );
    DLED_Decoder decoder6(
    .num(DLED_reg[4:1]),
    .rstn(rstn),
    .num_led(reg_led6)
    );
    
    
    reg [19:0] cnt_10ms;
    reg clk_10ms;
    reg [2:0] count2;
    always@(posedge clk) begin
    if(rstn==0)
    begin
    cnt_10ms=20'b00000000000000000000;
    clk_10ms=0;
    end
    else
    begin
    if(cnt_10ms<=24999)
    begin
    cnt_10ms=cnt_10ms+21'b1;clk_10ms=0;
    end
    else 
    begin
    cnt_10ms=cnt_10ms+21'b1;
    clk_10ms=1;
    end
    if(cnt_10ms==50000)
    cnt_10ms=0;
    end
    end
    
    always@(posedge clk_10ms) begin
    if(rstn==0)
    begin
    count2 <= 3'b000;
    end
    else if(DLED_reg[0]==1)
    begin
    if(count2==3'b101)
    count2 <= 3'b000;
    else count2<=count2+3'b1;
    end end
    
    always@(count2) begin
    if(rstn==0)
    begin
    digitalled_sel<=0;
    end
    else
    begin
    case(count2)
    3'b000:begin digitalled_sel<=6'b011111; digitalled<=reg_led1; end
    3'b001:begin digitalled_sel<=6'b101111; digitalled<=reg_led2; end
    3'b010:begin digitalled_sel<=6'b110111;  digitalled<=reg_led3;end
    3'b011:begin digitalled_sel<=6'b111011; digitalled<=reg_led4; end
    3'b100:begin digitalled_sel<=6'b111101;  digitalled<=reg_led5;end
    3'b101:begin digitalled_sel<=6'b111110; digitalled<=reg_led6; end
    default:begin digitalled_sel<=6'b111111;  digitalled<=8'b00000000;end
    endcase
    end end
    
    
endmodule
