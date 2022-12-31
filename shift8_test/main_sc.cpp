#include "shift8.cpp"

SC_MODULE(driver)
{
	sc_out<bool> din;

	void prc_driver()
	{
		din.write(0);
		wait(15,SC_NS);

		din.write(1);
		wait(15, SC_NS);

		din.write(0);
		wait(195,SC_NS);
	}

	SC_CTOR(driver)
	{
		SC_THREAD(prc_driver);	
	}

};


int sc_main(int argc, char * argv[])
{
	sc_signal <sc_int<8>>  t_out;
	sc_signal <bool>  t_in;
	sc_clock clk("clk" ,10, SC_NS, 0.5);

	shift8 sht("shifter");
	driver dr("generateInputs");

	dr.din(t_in);

	sht.clk(clk);
	sht.din(t_in);
	sht.dout(t_out);
	
	sc_trace_file *tf = sc_create_vcd_trace_file("my_db");
	sc_trace(tf,clk,"clock");
	sc_trace(tf,t_in,"input");
	sc_trace(tf,t_out,"output");

	sc_start(200,SC_NS); //start simulation for 200 nanoseconds

	sc_close_vcd_trace_file(tf);

	return 0;
}

