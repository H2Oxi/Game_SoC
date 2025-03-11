module LCD_RUN(
    input              clk,
    input              rstn,
    input              data_en,
    input              position_en,
    input     [30:0]   LCD_CRTL,
    input              sel,
    output             Initial_finish,
    output             position_finish,
    output             LCD_CS,
    output             LCD_RST,
    output             LCD_RS,
    output             LCD_WR,
    output             LCD_RD,
    output    [15:0]   LCD_DATA,
    output             LCD_BL_CTR
);

localparam  ADDR_WIDTH = 17;

assign LCD_RST    = rstn;
assign LCD_RD     = 1'b1;
assign LCD_BL_CTR = 1'b1;
//get position and data_width->addrbrgin to end
wire [7:0] x_position_start;
wire [8:0] y_position_start;
wire [13:0] picture;
reg [16:0] addr_begin;
reg [16:0] addr_end;
reg [7:0] x_position_finish;
reg [8:0] y_position_finish;

assign x_position_start=LCD_CRTL[30:23];
assign y_position_start=LCD_CRTL[22:14]; 
assign picture=LCD_CRTL[13:0]; 

always@(picture)
begin
case(picture)//jian ge 4 FFFF
14'd0:begin//◊Û ‹…À2808
addr_begin=17'd0;
addr_end=17'd2807;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;

end
14'd1:begin//”“ ‹…À2808
addr_begin=17'd2812;
addr_end=17'd5619;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;
end
14'd2:begin//◊Û“∆2808
addr_begin=17'd5624;
addr_end=17'd8431;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;
end

14'd3:begin//”““∆2808
addr_begin=17'd8436;
addr_end=17'd11243;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;
end

14'd4:begin//zhengchang

addr_begin=17'd11248;
addr_end=17'd14055;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;
end

14'd5:begin//”“ ‹…À

addr_begin=17'd14060;
addr_end=17'd16867;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;
end

14'd6:begin//◊Û∂◊

addr_begin=17'd16872;
addr_end=17'd19406;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd64;
end

14'd7:begin//”“∂◊

addr_begin=17'd19411;
addr_end=17'd21945;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd64;
end

14'd8:begin//◊Û≥§»≠

addr_begin=17'd21950;
addr_end=17'd22117;
x_position_finish=x_position_start+8'd23;
y_position_finish=y_position_start+9'd6;
end

14'd9:begin//”“≥§»≠

addr_begin=17'd22122;
addr_end=17'd22289;
x_position_finish=x_position_start+8'd23;
y_position_finish=y_position_start+9'd6;
end

14'd10:begin//◊Û∂Ã»≠

addr_begin=17'd22294;
addr_end=17'd22384;
x_position_finish=x_position_start+8'd12;
y_position_finish=y_position_start+9'd6;
end

14'd11:begin//”“∂Ã»≠

addr_begin=17'd22389;
addr_end=17'd22479;
x_position_finish=x_position_start+8'd12;
y_position_finish=y_position_start+9'd6;
end

14'd12:begin//zuo shang tiao

addr_begin=17'd22484;
addr_end=17'd25291;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;
end

14'd13:begin//you sshangtiao

addr_begin=17'd25296;
addr_end=17'd28103;
x_position_finish=x_position_start+8'd38;
y_position_finish=y_position_start+9'd71;
end

14'd14:begin//HUO

addr_begin=17'd28108;
addr_end=17'd28507;
x_position_finish=x_position_start+8'd19;
y_position_finish=y_position_start+9'd19;
end

14'd15:begin//BING

addr_begin=17'd28512;
addr_end=17'd28911;
x_position_finish=x_position_start+8'd19;
y_position_finish=y_position_start+9'd19;
end

14'd16:begin//LOADING

addr_begin=17'd28916;
addr_end=17'd28999;
x_position_finish=x_position_start+8'd11;
y_position_finish=y_position_start+9'd6;
end

14'd17:begin//gameover

addr_begin=17'd29004;
addr_end=17'd29087;
x_position_finish=x_position_start+8'd11;
y_position_finish=y_position_start+9'd6;
end

14'd18:begin//gameover

addr_begin=17'd29092;
addr_end=17'd29116;
x_position_finish=x_position_start+8'd4;
y_position_finish=y_position_start+9'd4;
end

14'd19:begin//gameover

addr_begin=17'd29121;
addr_end=17'd29600;
x_position_finish=x_position_start+8'd239;
y_position_finish=y_position_start+9'd1;
end

14'd20:begin//ª§∂‹

addr_begin=17'd29605;
addr_end=17'd30054;
x_position_finish=x_position_start+9'd49;
y_position_finish=y_position_start+8'd8;
end

14'd21:begin//GAMEOVER

addr_begin=17'd30059;
addr_end=17'd30706;
x_position_finish=x_position_start+9'd53;
y_position_finish=y_position_start+8'd11;
end

14'd22:begin//LOADING

addr_begin=17'd30711;
addr_end=17'd31274;
x_position_finish=x_position_start+9'd46;
y_position_finish=y_position_start+8'd11;
end 

default:begin

end
endcase
end

//
wire addr_en;
wire [15:0] LCD_DATA_position;
wire LCD_RS_position;
wire [15:0] LCD_DATA_data;
wire LCD_RS_data;
wire LCD_CS_position;
wire LCD_WR_position;
wire LCD_CS_data;
wire LCD_WR_data;
wire position_finish;

//get sel//




//

assign LCD_DATA=sel ? LCD_DATA_position:LCD_DATA_data;
assign LCD_RS=sel ? LCD_RS_position:LCD_RS_data;
assign LCD_WR=sel ? LCD_WR_position:LCD_WR_data;
assign LCD_CS=sel ? LCD_CS_position:LCD_CS_data;

wire addr_rstn;

WriteCtrl_RUN WriteCtrl_RUN(
     .clk               (clk)
    ,.rstn              (rstn)
    ,.en                (data_en)
    ,.data_stop         (Initial_finish)
    ,.addr_en           (addr_en)
    ,.LCD_CS            (LCD_CS_data)
    ,.LCD_WR            (LCD_WR_data)
    ,.LCD_RS            (LCD_RS_data)
    ,.addr_rstn         (addr_rstn)
);

/*****************************************/
//addr
/*****************************************/
wire [ADDR_WIDTH-1:0] addr;
AddrIni_RUN # (
     .ADDR_WIDTH  (ADDR_WIDTH)
)     AddrIni (
     .clk             (clk)
    ,.rstn            (addr_rstn)
    ,.sel             (sel)
    ,.addr_begin      (addr_begin)
    ,.addr_end        (addr_end)
    ,.cnt_en          (addr_en)
    ,.Initial_finish  (Initial_finish)
    ,.addr            (addr)
);


/*****************************************/
//BROM
/*****************************************/
BlockROM17 # (
     .ADDR_WIDTH  (ADDR_WIDTH) 
    ,.DATA_WIDTH  (16)
)     BlockROM_Data (
     .clk         (clk)
    ,.addr        (addr)
    ,.data        (LCD_DATA_data)
);


SET_position SET_position(
    .clk(clk),
    .rstn(rstn),
    
    .x_position_start(x_position_start),
    .y_position_start(y_position_start),
    .x_position_finish(x_position_finish),
    .y_position_finish(y_position_finish),
    .position_en(position_en),
    .LCD_DATA_position(LCD_DATA_position),
    .LCD_RS_position(LCD_RS_position),
    .LCD_CS_position(LCD_CS_position),
    .LCD_WR_position(LCD_WR_position),
    .data_stop(position_finish)
    
    );

endmodule
