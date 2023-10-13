/*
	C++ Modul Delegate

	Example code: Ofen class
	example class exposing a method that shall be called by the OOP_Delegate class


*/
#pragma once;
#include <iostream>
using namespace std;
#include "OOP_Delegate.h"

class Ofen
{
public:
	Ofen( string Name ) : Status(false), Name(Name) {}
	void Schalte( EventArgs e )
	{
		Status ^= true;
		if( Status == true )
		{
			cout << "Ofen (Schalte)" << Name.c_str() << " brennt; Message: " << e.message.c_str() << endl;
		}
		else
		{
			cout << "Ofen (Schalte)" << Name.c_str() << " brennt nicht; Message: " << e.message.c_str()<< endl;
		}
	}
	void Schalteneu( EventArgs e )
	{
		Status ^= true;
		if( Status == true )
		{
			cout << "Ofen (Schalteneu)" << Name.c_str() << " brennt; Message: " << e.message.c_str() << endl;
		}
		else
		{
			cout << "Ofen (Schalteneu)" << Name.c_str() << " brennt nicht; Message: " << e.message.c_str()<< endl;
		}
	}
private:
	string Name;
	bool Status;
};

