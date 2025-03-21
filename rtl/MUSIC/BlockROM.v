module BlockROM2 # (
    parameter ADDR_WIDTH = 10,
    parameter DATA_WIDTH = 12
)(
    input                               clk,
    input        [ADDR_WIDTH-1 : 0]     addr_i,
    output  reg  [DATA_WIDTH-1 : 0]     data_o
);

(* ramstyle = "AUTO" *) reg [DATA_WIDTH-1 : 0] mem[(2**ADDR_WIDTH-1) : 0];

initial begin
     $readmemh("F:/vivado_assignments/wholemusic.txt", mem);
end
always @ (posedge clk) begin
    data_o <= mem[addr_i];
end

endmodule