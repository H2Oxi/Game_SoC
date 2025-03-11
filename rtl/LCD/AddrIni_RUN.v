module AddrIni_RUN # (
    parameter ADDR_WIDTH = 17
)(
    input                       clk,
    input                       rstn,
    input                       cnt_en,
    input  [16:0]               addr_begin,
    input  [16:0]               addr_end,
    input                       sel,                         
    output                      Initial_finish,
    output [ADDR_WIDTH-1 : 0]   addr
);

reg [ADDR_WIDTH-1 : 0] cnt;
wire[ADDR_WIDTH-1 : 0] cnt_nxt = cnt + 1'b1;

always @ (posedge clk or negedge rstn) begin
    if (~rstn) begin 
        cnt <= addr_begin;
    end else begin
        if (cnt_en)    cnt <= cnt_nxt; 
        else             cnt <= cnt;
    end
end

assign addr =sel ? addr_begin:(( cnt <= (addr_end-17'd3) ) ? cnt : (cnt < (addr_end-17'd1) ? (addr_end-17'd3) : cnt - 17'd1 ));

assign Initial_finish = addr == addr_end-17'd1;

endmodule