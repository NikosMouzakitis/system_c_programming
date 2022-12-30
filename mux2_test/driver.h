#include "systemc.h"

SC_MODULE(driver)
{
	sc_out <sc_bit> d_x;
	sc_out <sc_bit> d_y;
	sc_out <sc_bit> d_z;
	

	void drivex();
	void drivey();
	void drivez();
	
	SC_CTOR(driver){

		SC_THREAD(drivex);
		SC_THREAD(drivey);
		SC_THREAD(drivez);
	}
};
