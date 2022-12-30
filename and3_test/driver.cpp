#include "driver.h"

void driver::drivex()
{
	d_x.write((sc_bit)false);
	wait(5,SC_NS);
	d_x.write((sc_bit)true);
	wait(5,SC_NS);
	d_x.write((sc_bit)0);
	wait(5,SC_NS);
	d_x.write((sc_bit)1);
	wait(5,SC_NS);
	d_x.write((sc_bit)0);
	wait(5,SC_NS);
	d_x.write((sc_bit)1);
	wait(5,SC_NS);
	d_x.write((sc_bit)0);
	wait(5,SC_NS);
	d_x.write((sc_bit)1);
	wait(5,SC_NS);

}	
	
void driver::drivey()
{
	d_y.write((sc_bit) 0);
	wait(10,SC_NS);
	d_y.write((sc_bit) 1);
	wait(10,SC_NS);
	d_y.write((sc_bit) 0);
	wait(10,SC_NS);
	d_y.write((sc_bit) 1);
	wait(10,SC_NS);
}

void driver::drivez()
{
	d_z.write((sc_bit) 0);
	wait(20,SC_NS);
	d_z.write((sc_bit) 1);
	wait(20,SC_NS);
}
