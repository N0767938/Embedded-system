module clock_div(clk, reset, out_clk);
input clk,reset;
output out_clk;
reg out_clk,out_clk_aux;
reg [27:0]counter;


always @(posedge (clk),posedge (reset))
	begin

		if(reset==1'b1)
			begin
			counter = 28'd0;
			out_clk_aux=1'b0;
			end
			
		else 
			begin 
				if((counter>=28'd0) && (counter<28'd25000000/8))
					begin
						out_clk_aux=1'b1;
						counter = counter +1;
					end
				else if ((counter>=28'd25000000/8) && (counter< 2*28'd50000000/8))
					begin
						out_clk_aux=1'b0;
						counter = counter +1;
					end
					else if ((counter>=2*28'd25000000/8) && (counter<3*28'd50000000/8))
					begin
						out_clk_aux=1'b1;
						counter = counter +1;
					end
					else if ((counter>=3*28'd25000000/8) && (counter<4*28'd50000000/8))
					begin
						out_clk_aux=1'b0;
						counter = counter +1;
					end
					else if ((counter>=4*28'd25000000/8) && (counter<5*28'd50000000/8))
					begin
						out_clk_aux=1'b1;
						counter = counter +1;
					end
					else if ((counter>=5*28'd25000000/8) && (counter<6*28'd50000000/8))
					begin
						out_clk_aux=1'b0;
						counter = counter +1;
					end
					else if ((counter>=6*28'd25000000/8) && (counter<7*28'd50000000/8))
					begin
						out_clk_aux=1'b1;
						counter = counter +1;
					end
					else if ((counter>=7*28'd25000000/8) && (counter<8*28'd50000000/8))
					begin
						out_clk_aux=1'b0;
						counter = counter +1;
					end
				else
					begin
						counter = 28'd0;
					end
			end
		// port assignements
		out_clk=out_clk_aux;
	end
endmodule
