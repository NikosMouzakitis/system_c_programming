#include "shift8.h"

void shift8::prc_rot8()
{
	sc_int<8> t_r;
	//write 0 to the output.
	dout.write(0);
	
	while(1)
	{
		wait(); //wait for any signal on sensitivity list
		
		t_r = dout;

		for(int i = 7; i > 0; i--)
			t_r[i] = t_r[i-1];

		t_r[0] = din;

		dout.write(t_r);
	}
}
