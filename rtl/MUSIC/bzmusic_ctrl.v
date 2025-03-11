module bzmusic_ctrl(
    input   clk,
    input   en,
    input   rstn,
    input   addr_finish,
    input   beat_finish,
    output  reg addr_en,
    output  reg addr_rstn,
    output  reg tune_pwm_en,
    output  reg tune_pwm_rstn,
    output  reg beat_cnt_en,
    output  reg beat_cnt_rstn
);

parameter IDLE  = 2'b00;
parameter ADD   = 2'b01;
parameter DELAY = 2'b10;
parameter EX    = 2'b11;


reg  [3:0]  state;
reg  [3:0]  state_nxt;

always @(en or beat_finish or addr_finish or state) begin
    case (state)
        IDLE :begin
            if (en) begin
                state_nxt = ADD;
            end else begin
                state_nxt = IDLE;
            end
        end
        ADD  :begin
            if (addr_finish) begin
                state_nxt = IDLE;
            end else begin
                state_nxt = DELAY;
            end
        end
        DELAY:state_nxt = EX;
        EX   :begin
            if (beat_finish) begin
                state_nxt = ADD;
            end else begin
                state_nxt = EX;
            end
        end
        default: state_nxt = IDLE;
    endcase
end

always @(posedge clk or negedge rstn) begin
    if (!rstn) begin
        state <= IDLE;
    end else begin
        state <= state_nxt;
    end
end

always @(posedge clk) begin
    case (state_nxt)
        IDLE:begin
            addr_rstn<=0;
            beat_cnt_rstn<=0;
            tune_pwm_rstn<=0;
            addr_en<=0;
            tune_pwm_en<=0;
            beat_cnt_en<=0;
            
        end
        ADD:begin
            addr_rstn<=1;
            addr_en<=1;
            tune_pwm_rstn<=0;
            beat_cnt_rstn<=0;
            beat_cnt_en<=0;
            tune_pwm_en<=0;
        end
        DELAY:begin
            tune_pwm_rstn<=1;
            beat_cnt_rstn<=1;
            tune_pwm_en<=1;
            beat_cnt_en<=1;
            addr_en<=0;
        end      
        EX:begin
            
            addr_en<=0;
            
        end                 
        default:begin
            
        end
    endcase
end



endmodule