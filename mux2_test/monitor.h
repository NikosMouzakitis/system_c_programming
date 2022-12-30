#include "systemc.h"

SC_MODULE(monitor)
{
	sc_in<sc_bit> m_x, m_y, m_z;//input of the or gate
	sc_in<sc_bit> m_f;  //output of the or gate
	
	void prc_monitor()
	{
		cout << "At " <<sc_simulation_time() << "(ns) input is: ";
		cout << m_x << " , " << m_y << ", " << m_z <<  " output is: " << m_f << endl;
	}

	SC_CTOR(monitor)
	{
		SC_METHOD(prc_monitor);
		sensitive <<  m_x <<  m_y << m_z << m_f;
	}
};

