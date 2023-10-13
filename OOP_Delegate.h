/*
	C++ Modul Delegate

	Example code: OOP_Delegate class
	implementation of a Delegate class for calling object methods

*/
#pragma once
#include <iostream>
using namespace std;
#include "EventArgs.h"
#include <list>
#include "TypemethodWrapper.h"

template<typename Typ>
class OOP_Delegate
{
public:
	typedef void (Typ::*OOP_Functionpointer) ( EventArgs args );

	OOP_Delegate( Typ* pObject, OOP_Functionpointer Callbacktarget );
	void operator() ( EventArgs e );
	void add( Typ* pObject, OOP_Functionpointer CallBacktarget );
private:
	void FireEvent( EventArgs args );
	
	list<TypemethodWrapper<Typ, OOP_Functionpointer>>* Callbacktargetlist;	
};

template<typename Typ>
OOP_Delegate<Typ>::OOP_Delegate( Typ* pObject, OOP_Functionpointer Callbacktarget ) 
{
	Callbacktargetlist = new list<TypemethodWrapper<Typ, OOP_Functionpointer>>();
	Callbacktargetlist->push_back( TypemethodWrapper<Typ, OOP_Functionpointer>( pObject, Callbacktarget ) );
}

template<typename Typ>
void OOP_Delegate<Typ>::operator() ( EventArgs e )
{
	OOP_Delegate<Typ>::FireEvent( e );
}

template<typename Typ>
void OOP_Delegate<Typ>::add( Typ* pObject, OOP_Functionpointer CallBacktarget )
{
	TypemethodWrapper<Typ, OOP_Functionpointer>* wrap = new TypemethodWrapper<Typ, OOP_Functionpointer>( pObject, CallBacktarget );
	Callbacktargetlist->push_back( *wrap );
}

template<typename Typ>
void OOP_Delegate<Typ>::FireEvent( EventArgs args )
{
	for( list<TypemethodWrapper<Typ, OOP_Functionpointer>>::iterator it = Callbacktargetlist->begin(); 
		 it != Callbacktargetlist->end(); it++ )
	{
		TypemethodWrapper<Typ, OOP_Functionpointer> pWrap = *it;
		(pWrap.pObject->*pWrap.Adr)( args );
	}
}