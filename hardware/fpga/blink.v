// Verilog 最小示例：50MHz 时钟下每 0.5s 翻转一次 LED 的计数器
// 综合工具：Vivado / Quartus / IceStorm，按 FPGA 型号改引脚约束。

module blink (
    input  wire clk,      // 50 MHz 系统时钟
    input  wire rst_n,    // 低有效复位
    output reg  led       // LED 输出
);

    // 0.5s @ 50MHz -> 25_000_000 个周期，需要 25 位计数器
    localparam COUNT_MAX = 25_000_000;
    reg [24:0] cnt;

    always @(posedge clk or negedge rst_n) begin
        if (!rst_n) begin
            cnt <= 25'd0;
            led <= 1'b0;
        end else if (cnt >= COUNT_MAX - 1) begin
            cnt <= 25'd0;
            led <= ~led;
        end else begin
            cnt <= cnt + 25'd1;
        end
    end

endmodule
