/*
	C++ Modul Delegate

	Example code: EventArgs class
	parameter class to pass messages from the Delegate to the individual objects

*/
#pragma once
#include <iostream>
using namespace std;

class EventArgs
{
public: 
	string message;
	EventArgs( string message ) : message(message) {};
};
