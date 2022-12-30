#include "systemc.h"

SC_MODULE(monitor)
{
	sc_in<bool> m_c;//input of the or gate

	
	void prc_monitor()
	{
		cout << "At " <<sc_simulation_time() << "(ns) input is: ";
		cout << m_c << endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(prc_monitor);
		sensitive <<  m_c ;
	}
};

