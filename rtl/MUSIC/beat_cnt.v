module beat_cnt (
    input            clk,
    input            en,
    input            rstn,
    input   [27:0]   beat_cnt_parameter,
    input [30:0] mode,
    output           beat_finish
);
wire  speed;
assign speed=mode[3]; 
wire [27:0] cnt;
wire [27:0] cnt_nxt = ( cnt == (beat_cnt_parameter>>speed )) ? cnt : cnt +1'b1 ;
register # (
    .WIDTH(28)
) beat_cnt_reg (
     .clk       (clk)
    ,.en        (en)
    ,.rstn      (rstn)
    ,.data_in   (cnt_nxt)
    ,.data_out  (cnt)
); 

assign  beat_finish = (cnt == (beat_cnt_parameter>>speed)) ? 1'b1 : 1'b0;

endmodule