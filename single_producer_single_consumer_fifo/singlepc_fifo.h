#include "systemc.h"

SC_MODULE(my_fifo)
{

	
	sc_fifo<int> f1;

	void generate(void)
	{
		int  v = 5;

		while(true)
		{

			f1.write(v);
			cout << "generator  wrote: " << v << " at " << sc_time_stamp() << endl;
			v++;
			wait(2, SC_NS);
		}
	}


	void consume(void)
	{
		int v = -1;

		while(true)
		{
			f1.read(v);	
			cout << "consume  read: " << v << " at " << sc_time_stamp() << endl;
			wait(10,SC_NS);	
		}	
	}

	SC_CTOR(my_fifo)
	{
		SC_THREAD(generate);
		//sensitive << clk.pos();
		SC_THREAD(consume);
		//sensitive << clk.pos();
	}
};
