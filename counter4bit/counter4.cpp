#include "counter4.h"

void counter4::prc_cnt()
{
	sc_int<4> t_r = 0;

	//write 0 to the output.
	out.write(0);

	while(1)
	{

		wait(); //wait for any signal on sensitivity list

		if( enable == true)
		{
			
			if( t_r == ( (sc_int<4>) 0xF) )
			{
				//reset it again.
				t_r = (sc_int<4>)0x0;
			} else {
				t_r += (sc_int<4>)0x1;
			}
			out.write(t_r);
		}
	}

}
