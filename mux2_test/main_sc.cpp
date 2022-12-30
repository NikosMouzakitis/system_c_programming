#include "driver.h"
#include "monitor.h"
#include "../gates/gates.h"

int sc_main(int argc, char * argv[])
{
	sc_signal <sc_bit> t_x, t_y, t_z, t_f;

	mux2 mux("mux2");
	driver d1("driver");
	monitor m1("monitor");
	
	// inputs and outputs of the or gate.
	// name binding
	mux.i0(t_x);
	mux.i1(t_y);
	mux.s(t_z);
	mux.o(t_f);	

	//positional binding	
	// driver only drives the inputs. ;)
	d1 << t_x << t_y << t_z;	

	// monitor monitors also the output tf.
	m1 << t_y << t_y << t_z << t_f;	
	
	sc_trace_file *tf = sc_create_vcd_trace_file("my_db");
	sc_trace(tf,t_x,"x");
	sc_trace(tf,t_y,"y");
	sc_trace(tf,t_z,"z");
	sc_trace(tf,t_f,"f");

	sc_start(40,SC_NS); //start simulation for 100 nanoseconds.
	sc_close_vcd_trace_file(tf);
	return 0;
}

