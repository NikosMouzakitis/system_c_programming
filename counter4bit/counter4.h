#include "systemc.h"

SC_MODULE(counter4)
{
	sc_in <bool> clk;
	sc_in <bool> enable;
	sc_out <sc_int<4>> out;

	void prc_cnt();

	SC_CTOR(counter4)
	{
		SC_THREAD(prc_cnt);
		sensitive << clk.pos();
	}
};


