module fsm(clk, rst, in, out);
input clk, rst;
input [6:0] in;
output [18:0] out;
reg [18:0] out;
reg [7:0] pstate, nstate;
parameter S0=8'd0, S1=8'd1, S2=8'd2, S3=8'd3, S4=8'd4,
S5=8'd5, S6=8'd6, S7=8'd7, S8=8'd8, S9=8'd9,
S10=8'd10, S11=8'd11, S12=8'd12, S13=8'd13, S14=8'd14,
S15=8'd15, S16=8'd16, S17=8'd17, S18=8'd18, S19=8'd19,
S20=8'd20, S21=8'd21, S22=8'd22, S23=8'd23, S24=8'd24,
S25=8'd25, S26=8'd26, S27=8'd27, S28=8'd28, S29=8'd29,
S30=8'd30, S31=8'd31, S32=8'd32, S33=8'd33, S34=8'd34,
S35=8'd35, S36=8'd36, S37=8'd37, S38=8'd38, S39=8'd39,
S40=8'd40, S41=8'd41, S42=8'd42, S43=8'd43, S44=8'd44,
S45=8'd45, S46=8'd46, S47=8'd47, S48=8'd48, S49=8'd49,
S50=8'd50, S51=8'd51, S52=8'd52, S53=8'd53, S54=8'd54,
S55=8'd55, S56=8'd56, S57=8'd57, S58=8'd58, S59=8'd59,
S60=8'd60, S61=8'd61, S62=8'd62, S63=8'd63, S64=8'd64,
S65=8'd65, S66=8'd66, S67=8'd67, S68=8'd68, S69=8'd69,
S70=8'd70, S71=8'd71, S72=8'd72, S73=8'd73, S74=8'd74,
S75=8'd75, S76=8'd76, S77=8'd77, S78=8'd78, S79=8'd79,
S80=8'd80, S81=8'd81, S82=8'd82, S83=8'd83, S84=8'd84,
S85=8'd85, S86=8'd86, S87=8'd87, S88=8'd88, S89=8'd89,
S90=8'd90, S91=8'd91, S92=8'd92, S93=8'd93, S94=8'd94,
S95=8'd95;

always @(posedge clk or posedge rst) begin
 if (rst) pstate <= S0; 
 else pstate <= nstate;
end

always @(in or pstate) begin
case (pstate)
S0: casex(in)
  7'bxxxxxxx: begin nstate=S1; out =19'b0010111010000000000; end
  endcase
S1: casex(in)
  7'bxxxx01x: begin nstate=S1; out =19'b0000000000000000000; end
  7'bxxxx10x: begin nstate=S1; out =19'b0000000001000000001; end
  7'bxxxx00x: begin nstate=S1; out =19'b1000000010000000001; end
  7'bxxxx11x: begin nstate=S2; out =19'b1000111110011001000; end
  endcase
S2: casex(in)
  7'bxxxxxx0: begin nstate=S3; out =19'b1010010010000000000; end
  7'bxxx0xxx: begin nstate=S3; out =19'b1010010010000000000; end
  7'bxxx1xx1: begin nstate=S0; out =19'b1010000010100100001; end
  endcase
S3: casex(in)
  7'b11xxxxx: begin nstate=S4; out =19'b0011111010000000000; end
  7'b10xxxxx: begin nstate=S4; out =19'b0011111110000000000; end
  7'b0x0x01x: begin nstate=S4; out =19'b0000000000001000000; end
  7'b0x0x10x: begin nstate=S4; out =19'b0000000001001000001; end
  7'b0x0x11x: begin nstate=S42; out =19'b0110110110001000000; end
  7'b0x0x00x: begin nstate=S4; out =19'b0110000010000000001; end
  7'b0x1x01x: begin nstate=S4; out =19'b0000000000011000000; end
  7'b0x1x10x: begin nstate=S4; out =19'b0000000001011000001; end
  7'b0x1x11x: begin nstate=S42; out =19'b0110110110011000000; end
  7'b0x1x00x: begin nstate=S4; out =19'b0110000010010000001; end
  endcase
S4: casex(in)
  7'bxxxxxxx: begin nstate=S5; out =19'b1010010010000000000; end
  endcase
S5: casex(in)
  7'bxx0xxxx: begin nstate=S6; out =19'b1000011110000000001; end
  7'bxx1xxxx: begin nstate=S6; out =19'b1000011110010000001; end
  endcase
S6: casex(in)
  7'bx1xxxx0: begin nstate=S7; out =19'b1010010010000000000; end
  7'bx110xx1: begin nstate=S7; out =19'b1010010010000000000; end
  7'bx10xxx1: begin nstate=S41; out =19'b1010010010000000000; end
  7'bx111xx1: begin nstate=S38; out =19'b1010010010000000000; end
  7'bx0xxxxx: begin nstate=S7; out =19'b1010010010000000000; end
  endcase
S7: casex(in)
  7'bxx1xxxx: begin nstate=S8; out =19'b0001101010010000000; end
  7'bxx0xxxx: begin nstate=S8; out =19'b0001101010000000000; end
  endcase
S8: casex(in)
  7'bxx0xxxx: begin nstate=S10; out =19'b1010010010000000000; end
  7'bxx1xxxx: begin nstate=S9; out =19'b1010010010000000000; end
  endcase
S9: casex(in)
  7'bx11xxxx: begin nstate=S11; out =19'b0010111010010000000; end
  7'bx01xxxx: begin nstate=S11; out =19'b0010111110010000000; end
  7'bx10xxxx: begin nstate=S11; out =19'b0010111010000000000; end
  7'bx00xxxx: begin nstate=S11; out =19'b0010111110000000000; end
  endcase
S10: casex(in)
  7'bxx1xxxx: begin nstate=S12; out =19'b0010000010010000001; end
  7'bxx0xxxx: begin nstate=S12; out =19'b0010000010000000001; end
  endcase
S11: casex(in)
  7'bxxxxxxx: begin nstate=S13; out =19'b1010010010000000000; end
  endcase
S12: casex(in)
  7'bxxxxxxx: begin nstate=S14; out =19'b1010010010000000000; end
  endcase
S13: casex(in)
  7'bx11xxxx: begin nstate=S15; out =19'b0101100110010000000; end
  7'bx10xxxx: begin nstate=S15; out =19'b0101100110000000000; end
  7'bx01xxxx: begin nstate=S15; out =19'b0101100010010000000; end
  7'bx00xxxx: begin nstate=S15; out =19'b0101100010000000000; end
  endcase
S14: casex(in)
  7'bxx1xxxx: begin nstate=S15; out =19'b0101000010010000001; end
  7'bxx0xxxx: begin nstate=S15; out =19'b0101000010000000001; end
  endcase
S15: casex(in)
  7'bxxxxxxx: begin nstate=S16; out =19'b1010010010000000000; end
  endcase
S16: casex(in)
  7'bxx1xxxx: begin nstate=S17; out =19'b0110010110010000001; end
  7'bxx0xxxx: begin nstate=S17; out =19'b0110010110000000001; end
  endcase
S17: casex(in)
  7'bxxx0xxx: begin nstate=S18; out =19'b1010010010000000000; end
  7'b01x1xxx: begin nstate=S19; out =19'b1010010010000010000; end
  7'b00x1xx0: begin nstate=S19; out =19'b1010010010000010000; end
  7'b00x1xx1: begin nstate=S46; out =19'b1010010010000000000; end
  7'b11x1xxx: begin nstate=S24; out =19'b1010010010000010000; end
  7'b10x1xx0: begin nstate=S24; out =19'b1010010010000010000; end
  7'b10x1xx1: begin nstate=S18; out =19'b1010010010000000000; end
  endcase
S18: casex(in)
  7'bxx1xxxx: begin nstate=S83; out =19'b1000111110010000000; end
  7'b0x0xxxx: begin nstate=S2; out =19'b1000000010000000001; end
  7'b1x0xxxx: begin nstate=S2; out =19'b1000111110000000000; end
  endcase
S19: casex(in)
  7'bx10xxxx: begin nstate=S20; out =19'b1001010010000000000; end
  7'bx00xxxx: begin nstate=S20; out =19'b1001010110000000000; end
  7'bxx1xxxx: begin nstate=S25; out =19'b1000111110010000000; end
  endcase
S20: casex(in)
  7'bx10xxxx: begin nstate=S19; out =19'b1010010010000000000; end
  7'bx11xxxx: begin nstate=S21; out =19'b1010010010000000000; end
  7'bx01xxxx: begin nstate=S19; out =19'b1010010010000000000; end
  7'bx00xxxx: begin nstate=S21; out =19'b1010010010000000000; end
  endcase
S21: casex(in)
  7'bx10xxxx: begin nstate=S22; out =19'b0011111110000000000; end
  7'bx11xxxx: begin nstate=S23; out =19'b0011111110010000000; end
  7'bx00xxxx: begin nstate=S67; out =19'b0011111010000000000; end
  7'bx01xxxx: begin nstate=S23; out =19'b0011111010010000000; end
  endcase
S22: casex(in)
  7'bxxxxxxx: begin nstate=S19; out =19'b1010010010000000000; end
  endcase
S23: casex(in)
  7'bxxxxxxx: begin nstate=S24; out =19'b1010010010000000000; end
  endcase
S24: casex(in)
  7'bxxxxxxx: begin nstate=S25; out =19'b1000111110000000000; end
  endcase
S25: casex(in)
  7'bxxx0xx0: begin nstate=S26; out =19'b1010010010000110000; end
  7'bxxx1xx0: begin nstate=S28; out =19'b1010010010000100000; end
  7'bxxxxxx1: begin nstate=S30; out =19'b1010010010000100000; end
  endcase
S26: casex(in)
  7'bxx0x01x: begin nstate=S67; out =19'b0000000000001010000; end
  7'bxx0x10x: begin nstate=S27; out =19'b0000000001001110001; end
  7'bxx0x00x: begin nstate=S27; out =19'b0110000010000110001; end
  7'bxx0x11x: begin nstate=S42; out =19'b0110110110001010000; end
  7'bxx1xxxx: begin nstate=S25; out =19'b1000111110010010000; end
  endcase
S27: casex(in)
  7'bxxxxxxx: begin nstate=S26; out =19'b1010010010000000000; end
  endcase
S28: casex(in)
  7'bxxxxxxx: begin nstate=S29; out =19'b0110010110000000001; end
  endcase
S29: casex(in)
  7'bxxx1xxx: begin nstate=S26; out =19'b1010010010000000000; end
  7'bxx10xxx: begin nstate=S3; out =19'b1010010010000001000; end
  7'bxx00xxx: begin nstate=S3; out =19'b1010010010000000000; end
  endcase
S30: casex(in)
  7'bxxxxxxx: begin nstate=S31; out =19'b1000011110000010001; end
  endcase
S31: casex(in)
  7'bxxx0xxx: begin nstate=S26; out =19'b1010010010000000100; end
  7'bxxx1xxx: begin nstate=S32; out =19'b1010010010000000000; end
  endcase
S32: casex(in)
  7'bxx0xxxx: begin nstate=S33; out =19'b1001010110000010000; end
  7'bxx1xxxx: begin nstate=S35; out =19'b0110110110010010000; end
  endcase
S33: casex(in)
  7'bxx10xxx: begin nstate=S48; out =19'b1010010010000000000; end
  7'bxx0xxxx: begin nstate=S48; out =19'b1010010010000000000; end
  7'bxxx1xxx: begin nstate=S34; out =19'b1010010010000000000; end
  endcase
S34: casex(in)
  7'bxx1xxxx: begin nstate=S35; out =19'b0110110110010000000; end
  7'bxx0xxxx: begin nstate=S83; out =19'b0110110110000000000; end
  endcase
S35: casex(in)
  7'bxxxxxxx: begin nstate=S36; out =19'b1010010010000000000; end
  endcase
S36: casex(in)
  7'bxx0xxxx: begin nstate=S37; out =19'b0110111010000000000; end
  7'bxx1xxxx: begin nstate=S37; out =19'b0110111010010000000; end
  endcase
S37: casex(in)
  7'bxxxxxxx: begin nstate=S9; out =19'b1010010010000000000; end
  endcase
S38: casex(in)
  7'bxx0x01x: begin nstate=S39; out =19'b0000000000001000000; end
  7'bxx0x10x: begin nstate=S39; out =19'b0000000001001000001; end
  7'bxx0x11x: begin nstate=S42; out =19'b0110110110001000000; end
  7'bxx0x00x: begin nstate=S39; out =19'b0110000010000000001; end
  7'bxx1xxxx: begin nstate=S40; out =19'b1000111110010000000; end
  endcase
S39: casex(in)
  7'bxxxxxxx: begin nstate=S38; out =19'b1010010010000000000; end
  endcase
S40: casex(in)
  7'bxxxxxxx: begin nstate=S41; out =19'b1010010010000000000; end
  endcase
S41: casex(in)
  7'bxxxxxxx: begin nstate=S42; out =19'b0110110110000000000; end
  endcase
S42: casex(in)
  7'bxxxxxxx: begin nstate=S43; out =19'b1010010010000100000; end
  endcase
S43: casex(in)
  7'bxx0xxxx: begin nstate=S44; out =19'b0110111010000000000; end
  7'bxx1xxxx: begin nstate=S44; out =19'b0110111010010000000; end
  endcase
S44: casex(in)
  7'bxxxxxxx: begin nstate=S45; out =19'b1010010010000000000; end
  endcase
S45: casex(in)
  7'bxx0xxxx: begin nstate=S6; out =19'b0111001110000000000; end
  7'bxx1xxxx: begin nstate=S6; out =19'b0111001110010000000; end
  endcase
S46: casex(in)
  7'bxx0xxxx: begin nstate=S47; out =19'b1000000010000000001; end
  7'bxx1xxxx: begin nstate=S0; out =19'b1000111110110100000; end
  endcase
S47: casex(in)
  7'bxxxxxxx: begin nstate=S46; out =19'b1010010010000000000; end
  endcase
S48: casex(in)
  7'bxxx0000: begin nstate=S49; out =19'b1000000000000000000; end
  7'bxxx0100: begin nstate=S50; out =19'b1000000000000000000; end
  7'bxxx0010: begin nstate=S50; out =19'b1000000000000000000; end
  7'bxxx0001: begin nstate=S50; out =19'b1000000010000000000; end
  7'bxxx1100: begin nstate=S51; out =19'b1000000000000000000; end
  7'bxxx1000: begin nstate=S51; out =19'b1000000000000000000; end
  7'bxxx011x: begin nstate=S48; out =19'b0000000000010000000; end
  7'bxxx01x1: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxx101x: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxx10x1: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxx111x: begin nstate=S48; out =19'b0000000010000000000; end
  7'bxxx11x1: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000000000000000000; end
  endcase
S49: casex(in)
  7'b0000000: begin nstate=S52; out =19'b1000000000000010000; end
  7'b1000000: begin nstate=S53; out =19'b0000010000000000000; end
  7'b0100000: begin nstate=S53; out =19'b0000000000000000000; end
  7'b0010000: begin nstate=S53; out =19'b0000000100000000000; end
  7'b0001000: begin nstate=S53; out =19'b0000000000000000000; end
  7'b0000100: begin nstate=S53; out =19'b0000010000000000101; end
  7'b0000010: begin nstate=S53; out =19'b0000000000000000000; end
  7'b0000001: begin nstate=S53; out =19'b0000000001100000000; end
  7'b11xxxxx: begin nstate=S48; out =19'b0000000000000001000; end
  7'b1x1xxxx: begin nstate=S48; out =19'b0000010000000100000; end
  7'b1xx1xxx: begin nstate=S48; out =19'b0000000001000000000; end
  7'b1xxx1xx: begin nstate=S48; out =19'b0000000000000000000; end
  7'b1xxxx1x: begin nstate=S48; out =19'b0000010000000000000; end
  7'b1xxxxx1: begin nstate=S48; out =19'b0000000000000000000; end
  7'bx11xxxx: begin nstate=S48; out =19'b0000100000000000000; end
  7'bx1x1xxx: begin nstate=S48; out =19'b0000000000000000000; end
  7'bx1xx1xx: begin nstate=S48; out =19'b0000000100001000001; end
  7'bx1xxx1x: begin nstate=S48; out =19'b0001010100010001001; end
  7'bx1xxxx1: begin nstate=S48; out =19'b0000100000010000000; end
  7'bxx11xxx: begin nstate=S48; out =19'b1000100001000000000; end
  7'bxx1x1xx: begin nstate=S48; out =19'b0000010010001110000; end
  7'bxx1xx1x: begin nstate=S48; out =19'b0000000010000000000; end
  7'bxx1xxx1: begin nstate=S48; out =19'b0000010000000000000; end
  7'bxxx11xx: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxx1x1x: begin nstate=S48; out =19'b0000010000001000000; end
  7'bxxx1xx1: begin nstate=S48; out =19'b0000001101000000000; end
  7'bxxxx11x: begin nstate=S48; out =19'b1110000000000000000; end
  7'bxxxx1x1: begin nstate=S48; out =19'b0011000000000000000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000000010000000001; end
  endcase
S50: casex(in)
  7'b0000000: begin nstate=S53; out =19'b0000011011101111001; end
  7'b1xxxxxx: begin nstate=S48; out =19'b0000100010000010000; end
  7'bx1xxxxx: begin nstate=S48; out =19'b0000010000000010000; end
  7'bxx1xxxx: begin nstate=S48; out =19'b0001000000001110000; end
  7'bxxx1xxx: begin nstate=S48; out =19'b0000001100000000000; end
  7'bxxxx1xx: begin nstate=S48; out =19'b0001000000000110000; end
  7'bxxxxx1x: begin nstate=S48; out =19'b0001000000000100000; end
  7'bxxxxxx1: begin nstate=S48; out =19'b0001000100100000000; end
  endcase
S51: casex(in)
  7'b0000000: begin nstate=S54; out =19'b1001000000000000100; end
  7'b0011000: begin nstate=S53; out =19'b0000000010000100000; end
  7'b0000100: begin nstate=S53; out =19'b0000000000100010000; end
  7'b0000010: begin nstate=S53; out =19'b0000000000010010000; end
  7'b0000001: begin nstate=S53; out =19'b0111100001110000000; end
  7'b1xxxxxx: begin nstate=S48; out =19'b0000011100100000000; end
  7'bx1xxxxx: begin nstate=S48; out =19'b0000010000100100000; end
  7'bxx01xxx: begin nstate=S48; out =19'b0000001000100000000; end
  7'bxx10xxx: begin nstate=S48; out =19'b0000110010000000000; end
  7'bxx111xx: begin nstate=S48; out =19'b0000000000100100000; end
  7'bxx11x1x: begin nstate=S48; out =19'b0001000000000000000; end
  7'bxx11xx1: begin nstate=S48; out =19'b0000000010001000000; end
  7'bxxxx11x: begin nstate=S48; out =19'b0000001000100000000; end
  7'bxxxx1x1: begin nstate=S48; out =19'b0000001010000001000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000001000001000000; end
  endcase
S52: casex(in)
  7'bx000000: begin nstate=S55; out =19'b1000000000111000000; end
  7'bx100000: begin nstate=S56; out =19'b0000000001000000000; end
  7'bx010000: begin nstate=S56; out =19'b0000000000000000000; end
  7'bx001000: begin nstate=S56; out =19'b0001000011000010000; end
  7'bx000100: begin nstate=S56; out =19'b0000001000001010000; end
  7'bx000010: begin nstate=S56; out =19'b0000001000100000001; end
  7'bx000001: begin nstate=S56; out =19'b0000000000000000101; end
  7'bx11xxxx: begin nstate=S48; out =19'b0000011100000000000; end
  7'bx1x1xxx: begin nstate=S48; out =19'b0000000000000000000; end
  7'bx1xx1xx: begin nstate=S48; out =19'b0000000000000000000; end
  7'bx1xxx1x: begin nstate=S48; out =19'b0000010000000000000; end
  7'bx1xxxx1: begin nstate=S48; out =19'b0000011000000000000; end
  7'bxx11xxx: begin nstate=S48; out =19'b0000010000000000000; end
  7'bxx1x1xx: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxx1xx1x: begin nstate=S48; out =19'b0000000000100000000; end
  7'bxx1xxx1: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxx11xx: begin nstate=S48; out =19'b0000001111000000000; end
  7'bxxx1x1x: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxx1xx1: begin nstate=S48; out =19'b0000001000000000000; end
  7'bxxxx11x: begin nstate=S48; out =19'b0000001000000000000; end
  7'bxxxx1x1: begin nstate=S48; out =19'b0000000010000010000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000000010000000000; end
  endcase
S53: casex(in)
  7'bx000000: begin nstate=S56; out =19'b0000010000000100000; end
  7'bx1xxxxx: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxx1xxxx: begin nstate=S48; out =19'b0010000010000000000; end
  7'bxxx1xxx: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxxx1xx: begin nstate=S48; out =19'b0000000000000010000; end
  7'bxxxxx1x: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxxxxx1: begin nstate=S48; out =19'b0000000011000000000; end
  endcase
S54: casex(in)
  7'bx011000: begin nstate=S56; out =19'b0000010000000010000; end
  7'bx000100: begin nstate=S56; out =19'b0000000000000000000; end
  7'bx000010: begin nstate=S56; out =19'b0000000000000000000; end
  7'bx000001: begin nstate=S56; out =19'b0000010000100000000; end
  7'bx000000: begin nstate=S57; out =19'b1000000000100000000; end
  7'bx1xxxxx: begin nstate=S48; out =19'b0000010000100100000; end
  7'bxx01xxx: begin nstate=S48; out =19'b0000010000000100000; end
  7'bxx10xxx: begin nstate=S48; out =19'b0000000000100101000; end
  7'bxx111xx: begin nstate=S48; out =19'b0000000111000101000; end
  7'bxx11x1x: begin nstate=S48; out =19'b0000011010000110000; end
  7'bxx11xx1: begin nstate=S48; out =19'b0000111110000100000; end
  7'bxxxx11x: begin nstate=S48; out =19'b0000000000000100000; end
  7'bxxxx1x1: begin nstate=S48; out =19'b0000000000000110000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000000010000100000; end
  endcase
S55: casex(in)
  7'bxx00000: begin nstate=S58; out =19'b1000000000000000000; end
  7'bxx10000: begin nstate=S59; out =19'b0000010010000000000; end
  7'bxx01000: begin nstate=S59; out =19'b0000010000000010000; end
  7'bxx00100: begin nstate=S59; out =19'b0000010100100010000; end
  7'bxx00010: begin nstate=S59; out =19'b0001100000000010000; end
  7'bxx00001: begin nstate=S59; out =19'b0000000000000111001; end
  7'bxx11xxx: begin nstate=S48; out =19'b0000000100000000000; end
  7'bxx1x1xx: begin nstate=S48; out =19'b0000000000100000000; end
  7'bxx1xx1x: begin nstate=S48; out =19'b0110100000000001000; end
  7'bxx1xxx1: begin nstate=S48; out =19'b0000100000000000010; end
  7'bxxx11xx: begin nstate=S48; out =19'b0001000000000001000; end
  7'bxxx1x1x: begin nstate=S48; out =19'b0100001000000000000; end
  7'bxxx1xx1: begin nstate=S48; out =19'b0000000010000000000; end
  7'bxxxx11x: begin nstate=S48; out =19'b0001000000010000000; end
  7'bxxxx1x1: begin nstate=S48; out =19'b0000000001001000000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000100000001000000; end
  endcase
S56: casex(in)
  7'bxx00000: begin nstate=S59; out =19'b0000000001000010000; end
  7'bxx1xxxx: begin nstate=S48; out =19'b0000001000000101000; end
  7'bxxx1xxx: begin nstate=S48; out =19'b0000011110000100000; end
  7'bxxxx1xx: begin nstate=S48; out =19'b0000000000101100000; end
  7'bxxxxx1x: begin nstate=S48; out =19'b0000111000000100000; end
  7'bxxxxxx1: begin nstate=S48; out =19'b0000100001000101000; end
  endcase
S57: casex(in)
  7'bxx00000: begin nstate=S60; out =19'b0010100100010010000; end
  7'bxx11000: begin nstate=S59; out =19'b0010000000000000000; end
  7'bxx00100: begin nstate=S59; out =19'b0000000010001000000; end
  7'bxx00010: begin nstate=S59; out =19'b0001000000000100000; end
  7'bxx00001: begin nstate=S59; out =19'b0000000010010100000; end
  7'bxx01xxx: begin nstate=S48; out =19'b0001000000010100000; end
  7'bxx10xxx: begin nstate=S48; out =19'b0010000000010100000; end
  7'bxx111xx: begin nstate=S48; out =19'b0000011110010100000; end
  7'bxx11x1x: begin nstate=S48; out =19'b0000110000000100000; end
  7'bxx11xx1: begin nstate=S48; out =19'b0000000001000100000; end
  7'bxxxx11x: begin nstate=S48; out =19'b0000000000101100000; end
  7'bxxxx1x1: begin nstate=S48; out =19'b0000000000100100000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000000000100100000; end
  endcase
S58: casex(in)
  7'bxxxx000: begin nstate=S61; out =19'b1000000000100000000; end
  7'bxxxx100: begin nstate=S62; out =19'b0000000000100000000; end
  7'bxxxx010: begin nstate=S62; out =19'b0000000000100000000; end
  7'bxxxx001: begin nstate=S62; out =19'b0000000000100000000; end
  7'bxxxx11x: begin nstate=S48; out =19'b0000000000110000000; end
  7'bxxxx1x1: begin nstate=S48; out =19'b0000000000010000000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0010000000000000000; end
  endcase
S59: casex(in)
  7'bxxxx000: begin nstate=S62; out =19'b0000001000010010000; end
  7'bxxxx1xx: begin nstate=S48; out =19'b0000001000000100000; end
  7'bxxxxx1x: begin nstate=S48; out =19'b0000001000000100000; end
  7'bxxxxxx1: begin nstate=S48; out =19'b0000001000000110000; end
  endcase
S60: casex(in)
  7'bxxxxx00: begin nstate=S62; out =19'b0000001000001000000; end
  7'bxxxxx1x: begin nstate=S48; out =19'b0000000000000000000; end
  7'bxxxxxx1: begin nstate=S48; out =19'b0000001000001000000; end
  endcase
S61: casex(in)
  7'bxxxxx00: begin nstate=S63; out =19'b1000000001010000000; end
  7'bxxxxx10: begin nstate=S64; out =19'b0000000000000000000; end
  7'bxxxxx01: begin nstate=S64; out =19'b0000000000000010000; end
  7'bxxxxx11: begin nstate=S48; out =19'b0000010000100000000; end
  endcase
S62: casex(in)
  7'bxxxxx00: begin nstate=S64; out =19'b0000000000010000000; end
  7'bxxxxx1x: begin nstate=S48; out =19'b0000000000010010000; end
  7'bxxxxxx1: begin nstate=S48; out =19'b0000000000010000000; end
  endcase
S63: casex(in)
  7'bxxxxxx0: begin nstate=S65; out =19'b0000000000000000000; end
  7'bxxxxxx1: begin nstate=S66; out =19'b0000000000000000000; end
  endcase
S64: casex(in)
  7'bxxxxxx0: begin nstate=S66; out =19'b0001000000010000000; end
  7'bxxxxxx1: begin nstate=S48; out =19'b0001000000000010000; end
  endcase
S65: casex(in)
  7'bxxxxxxx: begin nstate=S48; out =19'b0000000000100000000; end
  endcase
S66: casex(in)
  7'bxxxxxxx: begin nstate=S48; out =19'b0101000000000000000; end
  endcase
S67: casex(in)
  7'b1x000xx: begin nstate=S67; out =19'b0000000100000100000; end
  7'b1x11xxx: begin nstate=S67; out =19'b0001000000010100000; end
  7'b1x1x1xx: begin nstate=S67; out =19'b0000000000000100000; end
  7'b10010xx: begin nstate=S68; out =19'b1100010000010100000; end
  7'b10011xx: begin nstate=S76; out =19'b0011001000000100000; end
  7'b10001xx: begin nstate=S73; out =19'b0000001000000100000; end
  7'b10100xx: begin nstate=S75; out =19'b0001000000000100000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000000000100000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000001000001100000; end
  endcase
S68: casex(in)
  7'b101xxxx: begin nstate=S67; out =19'b0000000000000000000; end
  7'b10010xx: begin nstate=S68; out =19'b0100000000000000000; end
  7'b1000xxx: begin nstate=S69; out =19'b0000000100010000000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000010000000001000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000010000000000000; end
  endcase
S69: casex(in)
  7'b10010xx: begin nstate=S68; out =19'b1100000000000100000; end
  7'b10011xx: begin nstate=S72; out =19'b0001000000000001000; end
  7'b10000xx: begin nstate=S69; out =19'b0000000111100100000; end
  7'b10001xx: begin nstate=S70; out =19'b1000001000000000000; end
  7'b101xxxx: begin nstate=S67; out =19'b0000001000000001000; end
  7'b0xxxxx0: begin nstate=S67; out =19'b0000000000000100000; end
  7'b0xxxxx1: begin nstate=S67; out =19'b0000010000000100000; end
  7'bx1xxxx0: begin nstate=S67; out =19'b0000000001010100000; end
  7'bx1xxxx1: begin nstate=S67; out =19'b0000010000010000000; end
  endcase
S70: casex(in)
  7'b10001xx: begin nstate=S70; out =19'b0000000000000001000; end
  7'b100x0xx: begin nstate=S71; out =19'b0000001100101100000; end
  7'b101xxxx: begin nstate=S67; out =19'b0000000101000001000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000010000000000000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000010000001000000; end
  endcase
S71: casex(in)
  7'b101xxxx: begin nstate=S67; out =19'b0000000000001000000; end
  7'b10010xx: begin nstate=S68; out =19'b1100000001000101000; end
  7'b1000xxx: begin nstate=S71; out =19'b0000000001000000000; end
  7'b10011xx: begin nstate=S72; out =19'b0001000001000000000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000001111110000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000000000000000; end
  endcase
S72: casex(in)
  7'b10x1xxx: begin nstate=S72; out =19'b0000000000001011000; end
  7'b10x0xxx: begin nstate=S67; out =19'b0000000000100010000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000110000101000000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000000000010000; end
  endcase
S73: casex(in)
  7'b10xx1xx: begin nstate=S73; out =19'b0000000000111110000; end
  7'b101xxxx: begin nstate=S73; out =19'b0000000000000000000; end
  7'b100x0xx: begin nstate=S74; out =19'b0000000000001000000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000000000010000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000000001000000; end
  endcase
S74: casex(in)
  7'b100xx0x: begin nstate=S74; out =19'b0000000000001000000; end
  7'b101xx0x: begin nstate=S73; out =19'b0000001000000100000; end
  7'b10xxx1x: begin nstate=S67; out =19'b0000000000100000001; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000000000000000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000000000010000; end
  endcase
S75: casex(in)
  7'b10x00xx: begin nstate=S75; out =19'b0000000000000000000; end
  7'b10010xx: begin nstate=S76; out =19'b0010101000001000000; end
  7'b10x01xx: begin nstate=S77; out =19'b0000010000000100000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000000110110000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000011100010000; end
  7'b10x11xx: begin nstate=S67; out =19'b0000000101000100000; end
  endcase
S76: casex(in)
  7'b10x1xxx: begin nstate=S76; out =19'b0000000100000100000; end
  7'b10x0xxx: begin nstate=S74; out =19'b0000000101000100000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000000000000000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000000001111000; end
  endcase
S77: casex(in)
  7'b10x0xxx: begin nstate=S77; out =19'b0000000000000001001; end
  7'b10x10xx: begin nstate=S78; out =19'b0000100000100001000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000100000000100000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000100001000000; end
  7'b10x11xx: begin nstate=S67; out =19'b0000000111000001000; end
  endcase
S78: casex(in)
  7'b10x10xx: begin nstate=S78; out =19'b0001100100000000000; end
  7'b10x0xxx: begin nstate=S79; out =19'b0000000000000000000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000011000001000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000000101000000; end
  7'b10x11xx: begin nstate=S67; out =19'b0000000000000100000; end
  endcase
S79: casex(in)
  7'b10x0xxx: begin nstate=S79; out =19'b0000000000000100000; end
  7'b10x10xx: begin nstate=S80; out =19'b1000000000001100000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000000000100000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000001000011000000; end
  7'b10x11xx: begin nstate=S67; out =19'b0000000000000000000; end
  endcase
S80: casex(in)
  7'b10x10xx: begin nstate=S80; out =19'b0000000000111000000; end
  7'b10x01xx: begin nstate=S80; out =19'b0000001011000000000; end
  7'b10100xx: begin nstate=S81; out =19'b0000000000000101000; end
  7'b10000xx: begin nstate=S82; out =19'b0000000000010000000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0000000100010000000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0000000100010000000; end
  endcase
S81: casex(in)
  7'bxx111xx: begin nstate=S81; out =19'b0000000001000000000; end
  7'bxx100xx: begin nstate=S81; out =19'b0000000100000001000; end
  7'bxx110xx: begin nstate=S80; out =19'b1000000000001001000; end
  7'bxx101xx: begin nstate=S80; out =19'b1000000001001010000; end
  7'bxx0xxxx: begin nstate=S67; out =19'b0001000100000000000; end
  endcase
S82: casex(in)
  7'b10000xx: begin nstate=S82; out =19'b0000000000010100000; end
  7'b10010xx: begin nstate=S80; out =19'b1000000000100000000; end
  7'b10001xx: begin nstate=S80; out =19'b1000000110000100000; end
  7'b101xxxx: begin nstate=S75; out =19'b0001000010000100000; end
  7'b0xxxxxx: begin nstate=S67; out =19'b0001000000000000000; end
  7'bx1xxxxx: begin nstate=S67; out =19'b0001000000100001000; end
  7'b10011xx: begin nstate=S67; out =19'b0001000001001000000; end
  endcase
S83: casex(in)
  7'bxxxx11x: begin nstate=S84; out =19'b0100010001000100000; end
  7'bxxxx100: begin nstate=S84; out =19'b0100000001000000001; end
  7'bxx1x101: begin nstate=S87; out =19'b0000001001110010000; end
  7'bxx0x101: begin nstate=S94; out =19'b0000001000100010000; end
  7'bxxxx0x0: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxx011: begin nstate=S84; out =19'b0100000000011010000; end
  7'bxxxx001: begin nstate=S83; out =19'b0000000000001000000; end
  endcase
S84: casex(in)
  7'bx1xxx00: begin nstate=S85; out =19'b1000001100000000000; end
  7'bx0xxx00: begin nstate=S84; out =19'b0000000010000000000; end
  7'bxxxxx01: begin nstate=S83; out =19'b0000001000000000000; end
  7'bx0xxx10: begin nstate=S84; out =19'b0000000111100100000; end
  7'bx1xxx10: begin nstate=S85; out =19'b1000000000000010000; end
  7'bx0xxx11: begin nstate=S84; out =19'b0000000000010001000; end
  7'bx1xxx11: begin nstate=S86; out =19'b0010000110100000000; end
  endcase
S85: casex(in)
  7'bxxxxx00: begin nstate=S85; out =19'b0000000000010000000; end
  7'b0xxxx01: begin nstate=S83; out =19'b0101100000011110000; end
  7'b1xxxx01: begin nstate=S83; out =19'b0101000000110010000; end
  7'b0xxxx11: begin nstate=S84; out =19'b0101100000001010000; end
  7'b1xxxx11: begin nstate=S84; out =19'b0101000000000001001; end
  7'bxxxxx10: begin nstate=S85; out =19'b0000001100000100001; end
  endcase
S86: casex(in)
  7'bxxxxx00: begin nstate=S84; out =19'b0100000010010000000; end
  7'bxxxxx10: begin nstate=S84; out =19'b0110000000100100000; end
  7'bxxxxx11: begin nstate=S86; out =19'b0010000000000000000; end
  7'bxxxxx01: begin nstate=S83; out =19'b0000000000000011000; end
  endcase
S87: casex(in)
  7'bxxxxxx0: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxxx11: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxxx01: begin nstate=S88; out =19'b0000000001000000000; end
  endcase
S88: casex(in)
  7'bxx01x01: begin nstate=S87; out =19'b0000001000000101000; end
  7'bxx00x01: begin nstate=S89; out =19'b0100010000000000000; end
  7'bxx1xx01: begin nstate=S87; out =19'b0000001001100000000; end
  7'bxxxxx11: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxxxx0: begin nstate=S84; out =19'b0100000000010010000; end
  endcase
S89: casex(in)
  7'bxxxxx1x: begin nstate=S84; out =19'b0100000001000000000; end
  7'bx1xxx01: begin nstate=S90; out =19'b0000010000000100000; end
  7'bx0xxx01: begin nstate=S89; out =19'b0000010000100000001; end
  7'bxxxxx00: begin nstate=S84; out =19'b0100000001000000000; end
  endcase
S90: casex(in)
  7'bxxxxx1x: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxxx01: begin nstate=S91; out =19'b0100000000000010000; end
  7'bxxxxx00: begin nstate=S84; out =19'b0100000000010000000; end
  endcase
S91: casex(in)
  7'bx1xxx01: begin nstate=S92; out =19'b0000001000000000000; end
  7'bx0xxx01: begin nstate=S91; out =19'b0000000000000010000; end
  7'bxxxxx11: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxxxx0: begin nstate=S84; out =19'b0100000010001100000; end
  endcase
S92: casex(in)
  7'bxxxxxx0: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxxx11: begin nstate=S84; out =19'b0100000100000000000; end
  7'bxxxxx01: begin nstate=S93; out =19'b0000000010000000000; end
  endcase
S93: casex(in)
  7'bxxxxx1x: begin nstate=S84; out =19'b0100000010000010000; end
  7'bxx10x00: begin nstate=S84; out =19'b0101000100001000000; end
  7'bxx00x00: begin nstate=S84; out =19'b0100000100001000000; end
  7'bxxx1x00: begin nstate=S84; out =19'b0100000000001000000; end
  7'bxxx1101: begin nstate=S92; out =19'b0000001000000000000; end
  7'bxx10101: begin nstate=S83; out =19'b0001000000010001000; end
  7'bxx00101: begin nstate=S89; out =19'b0100010000001001000; end
  7'bxx10001: begin nstate=S83; out =19'b0001000000000000000; end
  7'bxx11001: begin nstate=S93; out =19'b0000000001001001000; end
  7'bxx00001: begin nstate=S89; out =19'b0100010000000000000; end
  7'bxx01001: begin nstate=S93; out =19'b0000000000100000000; end
  endcase
S94: casex(in)
  7'bxxxxxx0: begin nstate=S84; out =19'b0100000000000000000; end
  7'bxxxxx01: begin nstate=S95; out =19'b0000000000001000000; end
  7'bxxxxx11: begin nstate=S84; out =19'b0100000000000000000; end
  endcase
S95: casex(in)
  7'bxxxxx1x: begin nstate=S84; out =19'b0100000000000010000; end
  7'bxxxxx00: begin nstate=S84; out =19'b0100000000000001000; end
  7'bxx1xx01: begin nstate=S87; out =19'b0000001000000000000; end
  7'bxx0xx01: begin nstate=S94; out =19'b0000001000000001000; end
  endcase
endcase
end

assertion_rule1: assert property
        (@(posedge clk) $rose(out[6])|->##[12:13] $rose(out[7]))
         else $display("assertion rule 1 failed");

assertion_rule2: assert property
        (@(posedge clk) $fell(out[17])|->##[10:10] $rose(out[0]))
         else $display("assertion rule 2 failed");

assertion_rule3: assert property
        (@(posedge clk) $fell(out[0])|->##[45:51] $fell(out[5]))
         else $display("assertion rule 3 failed");

assertion_rule4: assert property
        (@(posedge clk) $fell(out[0])|->##[3:7] $rose(out[10]))
         else $display("assertion rule 4 failed");

assertion_rule5: assert property
        (@(posedge clk) $rose(out[3])|->##[1:3] $rose(out[4]))
         else $display("assertion rule 5 failed");

assertion_rule6: assert property
        (@(posedge clk) $rose(in[0])|->##[9:19] $rose(out[2]))
         else $display("assertion rule 6 failed");

assertion_rule7: assert property
        (@(posedge clk) $fell(out[0])|->##[12:12] $rose(out[0]))
         else $display("assertion rule 7 failed");

assertion_rule8: assert property
        (@(posedge clk) $rose(out[9])|->##[1:6] $fell(out[0]))
         else $display("assertion rule 8 failed");

assertion_rule9: assert property
        (@(posedge clk) $rose(out[0])|->##[3:5] $fell(out[5]))
         else $display("assertion rule 9 failed");

assertion_rule10: assert property
        (@(posedge clk) $fell(out[1])|->##[3:10] $rose(out[2]))
         else $display("assertion rule 10 failed");

assertion_rule11: assert property
        (@(posedge clk) $fell(out[7])|->##[40:45] $fell(out[3]))
         else $display("assertion rule 11 failed");

assertion_rule12: assert property
        (@(posedge clk) $rose(in[3])|->##[20:20] $rose(out[2]))
         else $display("assertion rule 12 failed");

assertion_rule13: assert property
        (@(posedge clk) $rose(out[10])|->##[11:12] $rose(out[9]))
         else $display("assertion rule 13 failed");

assertion_rule14: assert property
        (@(posedge clk) $fell(out[11])|->##[31:31] $fell(out[13]))
         else $display("assertion rule 14 failed");

assertion_rule15: assert property
        (@(posedge clk) $rose(out[1])|->##[3:4] $fell(out[4]))
         else $display("assertion rule 15 failed");

assertion_rule16: assert property
        (@(posedge clk) $fell(out[2])|->##[1:3] $rose(out[5]))
         else $display("assertion rule 16 failed");

assertion_rule17: assert property
        (@(posedge clk) $rose(out[7])|->##[1:20] $fell(out[8]))
         else $display("assertion rule 17 failed");


assertion_rule18: assert property
        (@(posedge clk) $fell(out[11])|->##[9:11] $rose(out[9]))
         else $display("assertion rule 18 failed");


assertion_rule19: assert property
        (@(posedge clk) $fell(in[0])|->##[5:5] $rose(out[13]))
         else $display("assertion rule 19 failed");

assertion_rule20: assert property
        (@(posedge clk) $rose(out[17])|->##[36:53] $rose(out[17]))
         else $display("assertion rule 20 failed");

endmodule
