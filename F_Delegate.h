/*
	C++ Modul Delegate

	Example code: F_Delegate class
	implementation of a Delegate class for calling global functions

	Author: Gerhard Biebl

*/
#pragma once
#include <iostream>
using namespace std;
#include "EventArgs.h"
#include <list>

class F_Delegate
{
public:
	typedef void (*F_Delegater) ( EventArgs args );

	F_Delegate( F_Delegater obj ) : CustomerCallback(obj)
	{
		Callbacktargetlist = new list<F_Delegater>();
		Callbacktargetlist->push_back( obj );
	}
	void add( F_Delegater CallBacktarget );
	void operator() ( EventArgs e );
	void FireEvent( EventArgs args );
private:
	F_Delegater CustomerCallback;
	list<F_Delegater>* Callbacktargetlist;
};