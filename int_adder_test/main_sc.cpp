#include "driver.h"
#include "monitor.h"
#include "../gates/gates.h"

int sc_main(int argc, char * argv[])
{
	sc_signal <int> t_x, t_y, t_z, t_f;

	Int_Adder adder("int_adder");
	driver d1("driver");
	monitor m1("monitor");
	
	// inputs and outputs of the or gate.
	// name binding
	adder.i0(t_x);
	adder.i1(t_y);
	adder.o(t_z);

	//positional binding	
	// driver only drives the inputs. ;)
	//d1 << t_x << t_y;
	d1.d_x(t_x);
	d1.d_y(t_y);
//	d1.d_z(t_z);
	// monitor monitors also the output tf.
	//m1 << t_x << t_y << t_z;	
	m1.m_x(t_x);
	m1.m_y(t_y);
	m1.m_z(t_z);	

	sc_trace_file *tf = sc_create_vcd_trace_file("my_db");
	sc_trace(tf,t_x,"x");
	sc_trace(tf,t_y,"y");
	sc_trace(tf,t_z,"z");

	sc_start(40,SC_NS); //start simulation for 100 nanoseconds.
	sc_close_vcd_trace_file(tf);
	return 0;
}

