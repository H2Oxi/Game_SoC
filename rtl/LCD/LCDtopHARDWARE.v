`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date: 2022/05/19 07:02:33
// Design Name: 
// Module Name: LCDtopHARDWARE
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



module LCDtopHARDWARE (
        input       wire            clk,
        input       wire            RSTn,
        input       wire            LCDcrtl_en,
        // input       wire   [15:0]  key_pluse,
        //input       wire            LCD_INI_FINISH,
        input       wire   [30:0]   LCD_CRTL,
        output      wire            LCD_CS,
        output      wire            LCD_RS,
        output      wire            LCD_WR,
        output      wire            LCD_RD,
        output      wire            LCD_RST,
        output      wire    [15:0]  LCD_DATA,
        output      wire            LCD_BL_CTR,
        output      wire            LCD_RUN_FINISH
              
);

//------------------------------------------------------------------------------
// DEBUG IOBUF 
//------------------------------------------------------------------------------



wire            LCD_CS_run;
wire            LCD_RS_run;
wire            LCD_WR_run;
wire            LCD_RD_run;
wire            LCD_RST_run;
wire   [15:0]   LCD_DATA_run;
wire            LCD_BL_CTR_run;

wire     LCD_INI_en;
wire     LCD_MODE;

wire sel;


//------------------------------------------------------------------------------
// LCD
//------------------------------------------------------------------------------

wire            LCD_CS_INI;
wire            LCD_RS_INI;
wire            LCD_WR_INI;
wire            LCD_RD_INI;
wire            LCD_RST_INI;
wire   [15:0]   LCD_DATA_INI;
wire            LCD_BL_CTR_INI;

wire data_en;
wire position_en;
wire LCD_RUN_FINISH_reg;
assign LCD_RUN_FINISH=LCD_RUN_FINISH_reg;
wire POSITION_FINISH;

LCD_RUN LCD_RUN(
         .clk             (clk)
        ,.rstn            (RSTn)
        ,.data_en         (data_en)
        ,.position_en     (position_en)
        ,.LCD_CRTL        (LCD_CRTL)
        ,.sel             (sel)
        ,.Initial_finish  (LCD_RUN_FINISH_reg)
        ,.position_finish (POSITION_FINISH)
        ,.LCD_CS          (LCD_CS_run)
        ,.LCD_RST         (LCD_RST_run)
        ,.LCD_RS          (LCD_RS_run)
        ,.LCD_WR          (LCD_WR_run)
        ,.LCD_RD          (LCD_RD_run)
        ,.LCD_DATA        (LCD_DATA_run)
        ,.LCD_BL_CTR      (LCD_BL_CTR_run)
);
wire   LCD_INI_FINISH;
LCD_INI LCD_INI(
         .clk             (clk)
        ,.rstn            (RSTn)
        ,.en              (LCD_INI_en)
        ,.Initial_finish  (LCD_INI_FINISH)
       ,.LCD_CS          (LCD_CS_INI)
        ,.LCD_RST         (LCD_RST_INI)
        ,.LCD_RS          (LCD_RS_INI)
        ,.LCD_WR          (LCD_WR_INI)
        ,.LCD_RD          (LCD_RD_INI)
        ,.LCD_DATA        (LCD_DATA_INI)
       ,.LCD_BL_CTR      (LCD_BL_CTR_INI)
);

wire [7:0] run_addr_begin;
wire [7:0] run_addr_end;
//wire LCDcrtl_en;

LCDcrtl LCDcrtl(
    .clk(clk),
    .rstn(RSTn),
    .LCD_CRTL(LCD_CRTL),
    .run_finish(LCD_RUN_FINISH_reg),
    .POSITION_FINISH(POSITION_FINISH),
    .ini_finish(LCD_INI_FINISH),
    .LCDcrtl_en(LCDcrtl_en),
    .data_en(data_en),
    .ini_en(LCD_INI_en),
    //对LCD寄存器译码得到，防止数据冲突，从这里把软件导入，再导出给run模块
    
    .LCD_MODE(LCD_MODE),
    .sel(sel),
    .position_en(position_en)
    );
assign LCD_CS      = ( LCD_MODE == 1'b1 ) ? LCD_CS_run     : LCD_CS_INI     ;
assign LCD_RST     = ( LCD_MODE == 1'b1 ) ? LCD_RST_run    : LCD_RST_INI    ;
assign LCD_RS      = ( LCD_MODE == 1'b1 ) ? LCD_RS_run     : LCD_RS_INI     ;
assign LCD_WR      = ( LCD_MODE == 1'b1 ) ? LCD_WR_run     : LCD_WR_INI     ;
assign LCD_RD      = ( LCD_MODE == 1'b1 ) ? LCD_RD_run     : LCD_RD_INI     ;
assign LCD_DATA    = ( LCD_MODE == 1'b1 ) ? LCD_DATA_run   : LCD_DATA_INI   ;
assign LCD_BL_CTR  = ( LCD_MODE == 1'b1 ) ? LCD_BL_CTR_run : LCD_BL_CTR_INI ;

endmodule
