#pragma once
#include <iostream>
using namespace std;
#include "OOP_Delegate.h";

template<typename Typ, typename MethodAddress=OOP_Delegate<Typ>::OOP_Functionpointer>
class TypemethodWrapper
{
public:
	TypemethodWrapper(Typ* pObject, MethodAddress Adr) : pObject(pObject), Adr(Adr) {}
	Typ* pObject;
	MethodAddress Adr;
};
