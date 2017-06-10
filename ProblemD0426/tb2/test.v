module test;
parameter input_len =7, input_depth = 10000000, output_len = 19;

reg clk = 0 ;
reg rst = 0 ;
reg [input_len-1:0] in;
integer i ;
wire [output_len-1:0]out;
reg [input_len:0] mem[0:input_depth-1];

 fsm f1(clk, rst, in, out);


always #10 clk ++;

initial begin
   $readmemb("input_sequence", mem);
   # 1;
   for (i= 0 ; i < input_depth; i = i + 1) begin
     #20  {rst, in} = mem[i];
   end
  #20 $finish;
end
endmodule
