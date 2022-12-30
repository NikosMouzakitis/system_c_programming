#include "driver.h"

void driver::drivex()
{
	d_x.write((int)10);
	wait(5,SC_NS);

	d_x.write((int)20);
	wait(5,SC_NS);
}	
	
void driver::drivey()
{
	d_y.write((int) 32);
	wait(10,SC_NS);
}


