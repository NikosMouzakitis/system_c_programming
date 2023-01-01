#include "singlepc_fifo.h"

int sc_main(int argc, char * argv[])
{
	my_fifo f("fifo test");

/*	sc_trace_file *tf = sc_create_vcd_trace_file("my_db");
	sc_trace(tf,clk,"clock");
	sc_trace(tf,t_enable,"input");
	sc_trace(tf,t_out,"output");
*/
	sc_start(100,SC_NS); //start simulation for 200 nanoseconds

//	sc_close_vcd_trace_file(tf);

	return 0;
}

