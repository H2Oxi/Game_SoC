module BlockROM17 # (
    parameter ADDR_WIDTH = 17,
    parameter DATA_WIDTH = 16
)(
    input                         clk,
    input  [ADDR_WIDTH-1 : 0]     addr,
    output reg [DATA_WIDTH-1 : 0] data
);

(* ramstyle = "AUTO" *) reg [DATA_WIDTH-1 : 0] mem[(2**ADDR_WIDTH-1) : 0];

initial begin
    $readmemh("G:/game_yjx/FcGame1.5/rtl/data1.txt", mem);
end

always @ (posedge clk) begin
    data <= mem[addr];
end

endmodule