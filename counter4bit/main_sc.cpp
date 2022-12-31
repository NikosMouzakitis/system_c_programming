#include "counter4.cpp"

SC_MODULE(driver)
{
	sc_out<bool> d_enable;
	
	void prc_driver()
	{
		d_enable.write(1);
		wait(200,SC_NS);
	}

	SC_CTOR(driver)
	{
		SC_THREAD(prc_driver);	
	}

};


int sc_main(int argc, char * argv[])
{
	sc_signal <sc_int<4>>  t_out;
	sc_signal <bool>  t_enable;
	sc_clock clk("clk" ,10, SC_NS, 0.5);

	counter4 c4("counter");
	driver d("driver");

	// to set enable=1	
	d.d_enable(t_enable);

	c4.clk(clk);
	c4.enable(t_enable);
	c4.out(t_out);
	
	sc_trace_file *tf = sc_create_vcd_trace_file("my_db");
	sc_trace(tf,clk,"clock");
	sc_trace(tf,t_enable,"input");
	sc_trace(tf,t_out,"output");

	sc_start(200,SC_NS); //start simulation for 200 nanoseconds

	sc_close_vcd_trace_file(tf);

	return 0;
}

