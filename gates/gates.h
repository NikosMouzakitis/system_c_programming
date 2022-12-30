#include "systemc.h"

SC_MODULE(or2)
{
	sc_in	<sc_bit> x;
	sc_in	<sc_bit> y;
	sc_out	<sc_bit> f;

	void prc_or2_gt()
	{
		f = x | y;
	}

	SC_CTOR(or2)
	{
		SC_METHOD(prc_or2_gt);
		sensitive << x << y;
	}
};

SC_MODULE(or3)
{
	sc_in	<sc_bit> x;
	sc_in	<sc_bit> y;
	sc_in	<sc_bit> z;
	sc_out	<sc_bit> f;

	void prc_or3_gt()
	{
		f = (y | y) | z;
	}

	SC_CTOR(or3)
	{
		SC_METHOD(prc_or3_gt);
		sensitive << x << y << z;
	}
};


SC_MODULE(and2)
{
	sc_in	<sc_bit> x;
	sc_in	<sc_bit> y;
	sc_out	<sc_bit> f;

	void prc_and2_gt()
	{
		f = x & y;
	}

	SC_CTOR(and2)
	{
		SC_METHOD(prc_and2_gt);
		sensitive << x << y;
	}
};

SC_MODULE(and3)
{
	sc_in	<sc_bit> x;
	sc_in	<sc_bit> y;
	sc_in	<sc_bit> z;
	sc_out	<sc_bit> f;

	void prc_and3_gt()
	{
		f = (y & y) & z;
	}

	SC_CTOR(and3)
	{
		SC_METHOD(prc_and3_gt);
		sensitive << x << y << z;
	}
};

SC_MODULE(mux2)
{
	sc_in <sc_bit> i0;
	sc_in <sc_bit> i1;
	sc_in <sc_bit> s;
	sc_out <sc_bit> o;

	void prc_mux2_gt()
	{
		if( s == (sc_bit) 0 )
			o = i0;
		else
			o = i1;
	}

	SC_CTOR(mux2)
	{
		SC_METHOD(prc_mux2_gt);
		sensitive << i0 << i1 << s;
	}

};

SC_MODULE(Int_Adder)
{
	sc_in <int> i0;
	sc_in <int> i1;
	sc_out <int> o;

	//perform addition
	void prc_int_add()
	{
		o = i0+i1;
	}

	SC_CTOR(Int_Adder)
	{
		SC_METHOD(prc_int_add);
		sensitive << i0 << i1;	
	}
};
