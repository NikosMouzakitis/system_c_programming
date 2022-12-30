#include "monitor.h"

int sc_main(int argc, char * argv[])
{
	sc_clock clk("clk" ,10, SC_NS, 0.5);
	monitor m1("monitor");
	
	m1.m_c(clk);
		
	// inputs and outputs of the or gate.
	// name binding


	sc_trace_file *tf = sc_create_vcd_trace_file("my_db");
	sc_trace(tf,clk,"clock");

	sc_start(40,SC_NS); //start simulation for 40 ns.

	sc_close_vcd_trace_file(tf);

	return 0;
}

