/*
	C++ Modul Delegate

	Example code: lampe class
	example class exposing a method that shall be called by the OOP_Delegate class


*/
#pragma once;
#include <iostream>
using namespace std;
#include "OOP_Delegate.h"

class Lampe
{
public:
	Lampe( string Name ) : Status(false), Name(Name) {}
	void Schalte( EventArgs e )
	{
		Status ^= true;
		if( Status == true )
		{
			cout << "Lampe " << Name.c_str() << " brennt; Message: " << e.message.c_str() << endl;
		}
		else
		{
			cout << "Lampe " << Name.c_str() << " brennt nicht; Message: " << e.message.c_str()<< endl;
		}
	}
private:
	string Name;
	bool Status;
};

