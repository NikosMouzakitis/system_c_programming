#include "systemc.h"

SC_MODULE(shift8)
{
	sc_in <bool> clk;
	sc_in <bool> din;

	sc_out <sc_int<8>> dout;

	void prc_rot8();

	SC_CTOR(shift8)
	{
		SC_THREAD(prc_rot8);
		sensitive << clk.pos();
	}
};


