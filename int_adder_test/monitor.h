#include "systemc.h"

SC_MODULE(monitor)
{
	sc_in<int> m_x, m_y;//input of the or gate
	sc_in<int> m_z;  //output of the or gate
	
	void prc_monitor()
	{
		cout << "At " <<sc_simulation_time() << "(ns) input is: ";
		cout << m_x << " , " << m_y << ", " <<  " output is: " << m_z << endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(prc_monitor);
		sensitive <<  m_x <<  m_y <<m_z ;
	}
};

