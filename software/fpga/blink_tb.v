// Verilog 测试平台：验证 blink 模块能翻转 led
`timescale 1ns / 1ps

module blink_tb;
    reg clk;
    reg rst_n;
    wire led;

    // 实例化被测模块（COUNT_MAX 在仿真里改小以便快速看到翻转）
    blink #(.COUNT_MAX(10)) dut (
        .clk(clk),
        .rst_n(rst_n),
        .led(led)
    );

    // 50MHz 时钟 = 10ns 周期
    always #5 clk = ~clk;

    initial begin
        $dumpfile("blink_tb.vcd");
        $dumpvars(0, blink_tb);

        clk = 0;
        rst_n = 0;
        #20 rst_n = 1;

        // 跑足够长时间观察至少一次翻转
        #200;
        $finish;
    end
endmodule
