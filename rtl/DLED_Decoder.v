`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/22 10:54:25
// Design Name: 
// Module Name: DLED_Decoder
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


module DLED_Decoder(
    input [3:0] num,
    input rstn,
    output reg [7:0] num_led
    );
    
    always@(*)
    begin
    if(rstn==0)
    begin
    num_led<=8'b00000000;
    end
    else
    begin
    case(num)
    0:num_led<=8'b01111110;
    1:num_led<=8'b00110000;
    2:num_led<=8'b01101101;
    3:num_led<=8'b01111001;
    4:num_led<=8'b00110011;
    5:num_led<=8'b01011011;
    6:num_led<=8'b01011111;
    7:num_led<=8'b01110000;
    8:num_led<=8'b01111111;
    9:num_led<=8'b01111011;
    10:num_led<=8'b01110111;
    11:num_led<=8'b00011111;
    12:num_led<=8'b01001110;
    13:num_led<=8'b00111101;
    14:num_led<=8'b01001111;
    15:num_led<=8'b01000111;
    endcase
    end
    end
    
endmodule
