#include "systemc.h"

SC_MODULE(driver)
{
	sc_out <int> d_x;
	sc_out <int> d_y;
	

	void drivex();
	void drivey();
	
	SC_CTOR(driver){

		SC_THREAD(drivex);
		SC_THREAD(drivey);
	}
};
