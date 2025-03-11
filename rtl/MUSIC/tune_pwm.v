module tune_pwm (
    input                clk,
    input                en,
    input                rstn,
    input        [19:0]  pwm_parameter,
    output               clk_pwm
);

wire  [19:0]   cnt;
wire  [19:0]   cnt_nxt = (cnt == pwm_parameter) ? 20'd0 : cnt + 1'b1;

register #(
     .WIDTH (20)
) pwm_cnt_register(
     .clk        (clk)
    ,.en         (en)
    ,.rstn       (rstn)
    ,.data_in    (cnt_nxt)
    ,.data_out   (cnt)
);

assign clk_pwm = (cnt > pwm_parameter>>1) ? 1'b1: 1'b0;

endmodule