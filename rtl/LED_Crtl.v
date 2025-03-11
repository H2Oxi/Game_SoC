`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/22 02:50:49
// Design Name: 
// Module Name: LED_Crtl
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


module LED_Crtl(
    input       clk,
    input       rstn,
    input [31:0] LED_reg,
    output reg [11:0] LED_O
    );
    always@(negedge rstn or posedge clk)
    begin
    if(rstn==0)
    LED_O<=12'b111111111111;
    else if(LED_reg[0]==1)
    LED_O<=LED_reg[12:1]; end
    
endmodule
