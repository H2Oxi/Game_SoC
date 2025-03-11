module addr_cnt (
    input          clk,
    input          en,
    input          rstn,
    input   [30:0] mode,
    
    output  [9:0]  addr,
    output         addr_finish
);

reg [9:0] addr_end;
reg [9:0] addr_begin;
always @(posedge clk or negedge rstn) begin
    if (!rstn) begin
        addr_begin <= 10'd1;
        
    end else begin
        if (en) begin
            case(mode[2:0])
            3'b000:begin
            addr_begin <= 10'd1;
            addr_end <=10'd33;
            end
            3'b001:
            begin
            addr_begin <= 10'd35;
            addr_end <=10'd370;
            end
            3'b010:
            begin
            addr_begin <= 10'd372;
            addr_end <=10'd412;
            end
            3'b011:
            begin
            addr_begin <= 10'd414;
            addr_end <=10'd579;
            end
            default: 
            begin
            addr_begin <= addr_begin;
            addr_end <=addr_end;
        end
        endcase
    end
end
end


wire [9:0] addr_nxt = (addr >= addr_end || addr < addr_begin) ? addr_begin : addr + 1'b1 ;
register # (
    .WIDTH(10)
) beat_cnt_register (
     .clk(clk)
    ,.en(en)
    ,.rstn(rstn)
    ,.data_in(addr_nxt)
    ,.data_out(addr)
);

assign  addr_finish = (addr == (addr_end-10'd1)) ? 1'b1 : 1'b0;


endmodule