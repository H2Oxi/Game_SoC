module buzzermusic(
    input           clk,
    input           rstn,
    input           en,
    input       [30:0] mode,
    
    output          beep
);

wire addr_finish;
wire beat_finish;
wire addr_en;
wire addr_rstn;
wire tune_pwm_en;
wire tune_pwm_rstn;
wire beat_cnt_en;
wire beat_cnt_rstn;
reg ctrl_en;
bzmusic_ctrl bzmusic_ctrl(
    .clk             (clk)
    ,.en             (ctrl_en)
    ,.rstn           (rstn)
    ,.addr_finish    (addr_finish)
    ,.beat_finish    (beat_finish)
    ,.addr_en        (addr_en)
    ,.addr_rstn      (addr_rstn)
    ,.tune_pwm_en    (tune_pwm_en)
    ,.tune_pwm_rstn  (tune_pwm_rstn)
    ,.beat_cnt_en    (beat_cnt_en)
    ,.beat_cnt_rstn  (beat_cnt_rstn) 
);

wire [9:0] addr;
addr_cnt addr_cnt(
     .clk          (clk)
    ,.en           (addr_en)
    ,.rstn         (addr_rstn)
    ,.addr         (addr)
    ,.mode(mode)
    ,.addr_finish  (addr_finish)
);

wire [11:0] data;
BlockROM2 #(
     .ADDR_WIDTH(10)
    ,.DATA_WIDTH(12)
) BlockROM2 (
     .clk(clk)
    ,.addr_i(addr)
    ,.data_o(data)
);

wire [19:0] tune_pwm_parameter;
tune_decoder tune_decoder(
     .tune                (data[11:4])
    ,.tune_pwm_parameter  (tune_pwm_parameter)
);

tune_pwm tune_pwm(     
     .clk            (clk)
    ,.en             (tune_pwm_en)
    ,.rstn           (tune_pwm_rstn)
    ,.pwm_parameter  (tune_pwm_parameter)
    ,.clk_pwm        (beep)
);


wire  [27:0]  beat_cnt_parameter;
beat_decoder beat_decoder(
     .beat                (data[3:0])
    ,.beat_cnt_parameter  (beat_cnt_parameter)
);

beat_cnt beat_cnt(
     .clk                 (clk)
    ,.en                  (beat_cnt_en)
    ,.rstn                (beat_cnt_rstn)
    ,.mode    (mode)
    ,.beat_cnt_parameter  (beat_cnt_parameter)
    ,.beat_finish         (beat_finish)   
);
wire en1;

  assign en1=en|| addr_finish;//cpu¿ØÖÆreg¡¾0¡¿ÊÇ¶ÌÂö³å
  always@(posedge en1 or negedge rstn)
    begin
    if(rstn==0)
    ctrl_en=0;
    else
    ctrl_en<=~ctrl_en;
    end
endmodule