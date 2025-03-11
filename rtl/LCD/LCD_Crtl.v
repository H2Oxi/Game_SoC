`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/22 11:40:38
// Design Name: 
// Module Name: LCD_Crtl
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


module LCD_Crtl (
        input       wire            clk,
        input       wire            RSTn,
        input       wire    [31:0]  LCD_REG,
        input       wire            rstn_LCD_en,
        // input       wire   [15:0]  key_pluse,
        //input       wire            LCD_INI_FINISH,
        output      wire            LCD_CS,
        output      wire            LCD_RS,
        output      wire            LCD_WR,
        output      wire            LCD_RD,
        output      wire            LCD_RST,
        output      wire    [15:0]  LCD_DATA,
        output      wire            LCD_BL_CTR,
        output      wire            LCD_Flag,
        output      wire            LCD_RUN_FINISH
    
    );
    reg en;
    LCDtopHARDWARE (
        .clk(clk),
        .RSTn(RSTn),
        .LCDcrtl_en(en),
        // input       wire   [15:0]  key_pluse,
        //input       wire            LCD_INI_FINISH,
        .LCD_CRTL(LCD_REG[31:1]),
        .LCD_CS(LCD_CS),
        .LCD_RS(LCD_RS),
        .LCD_WR(LCD_WR),
        .LCD_RD(LCD_RD),
        .LCD_RST(LCD_RST),
        .LCD_DATA(LCD_DATA),
        .LCD_BL_CTR(LCD_BL_CTR),
        .LCD_RUN_FINISH(LCD_RUN_FINISH)
              
);

wire en1;

  assign en1=LCD_REG[0]|| LCD_RUN_FINISH;//cpu¿ØÖÆreg¡¾0¡¿ÊÇ¶ÌÂö³å
  always@(posedge en1 or negedge rstn_LCD_en)
    begin
    if(rstn_LCD_en==0)
    en=0;
    else
    en<=LCD_REG[0];
    end
   
   assign LCD_Flag=en;
   
endmodule
