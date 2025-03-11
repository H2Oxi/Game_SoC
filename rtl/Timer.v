`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/25 18:20:21
// Design Name: 
// Module Name: Timer
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


module Timer(
    input clk,
    input rstn,
    output  Timer_Flag
    );
    
    reg [22:0] count;
    always@(negedge rstn or posedge clk)
    begin
    if(rstn==0)
    count=0;
    else begin
    if(count<=23'd4999998)
    
    count=count+1;
    else 
    count=0;
    
    end
    end
    assign Timer_Flag=(count==23'd4999999);
    
endmodule
