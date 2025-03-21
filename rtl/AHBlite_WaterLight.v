module AHBlite_USER(
    input  wire          HCLK,    
    input  wire          HRESETn, 
    input  wire          HSEL,    
    input  wire   [31:0] HADDR,   
    input  wire    [1:0] HTRANS,  
    input  wire    [2:0] HSIZE,   
    input  wire    [3:0] HPROT,   
    input  wire          HWRITE,  
    input  wire   [31:0] HWDATA,  
    input  wire          HREADY,  
    output wire          HREADYOUT, 
    output wire   [31:0] HRDATA,  
    output wire          HRESP,
    output reg     [31:0] LED,
    output reg     [31:0] DLED,
    output reg     [31:0] MUSIC,
    output reg     [31:0] LCD
     
);

assign HRESP = 1'b0;
assign HREADYOUT = 1'b1;

wire write_en;
assign write_en = HSEL & HTRANS[1] & HWRITE & HREADY;

reg [1:0] addr_reg;
always@(posedge HCLK or negedge HRESETn) begin
  if(~HRESETn) addr_reg <= 2'd0;
  else if(write_en) addr_reg <= HADDR[3:2];
end

reg wr_en_reg;
always@(posedge HCLK or negedge HRESETn) begin
  if(~HRESETn) wr_en_reg <= 1'b0;
  else if(write_en) wr_en_reg <= 1'b1;
  else wr_en_reg <= 1'b0;
end

always@(posedge HCLK) begin
    if(~HRESETn) begin
        LED <= 32'hFFFFFFFF;
        DLED <= 32'h00000000;
        MUSIC <= 32'd0;
        LCD <= 32'd0;

    end else if(wr_en_reg && HREADY) begin
        if(addr_reg==2'b00)
            LED <= HWDATA;
        if(addr_reg==2'b01)   
            DLED <= HWDATA;
        if(addr_reg==2'b10)
            MUSIC <= HWDATA;  
        if(addr_reg==2'b11)
            LCD <= HWDATA; 
    end
end



endmodule


