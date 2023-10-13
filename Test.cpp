#include <iostream>
using namespace std;
#include "F_Delegate.h"
#include "OOP_Delegate.h"
#include "Lampe.h"
#include "Ofen.h"

// global functions to be called by the Function-Delegate
void Function1( EventArgs e )
{
	cout << "Doing something; Message: " << e.message.c_str() << endl;
}

void Function2( EventArgs e )
{
	cout << "Doing something else; Message: " << e.message.c_str() << endl;
}

void main()
{
	F_Delegate MyDelegate = F_Delegate( &Function1 );
	MyDelegate.add( &Function2 );
	MyDelegate( EventArgs( "Function test Multicast" ));

	F_Delegate OtherDelegate = F_Delegate( &Function2 );
	OtherDelegate( EventArgs( "Function test Singlecast" ));

	// OOP objects exposing a method to be called by the OOP_Delegate
	Lampe Stehlampe( "Stehlampe" );
	Lampe Deckenlampe( "Deckenlampe" );
	Ofen Microwelle( "Microwelle" );
	Ofen Kaminofen( "Kaminofen" );

	OOP_Delegate<Lampe> Lampenschalter = OOP_Delegate<Lampe>( &Deckenlampe, &Lampe::Schalte );

	OOP_Delegate<Ofen> Ofenschalter = OOP_Delegate<Ofen>( &Microwelle, &Ofen::Schalte );
	Ofenschalter.add( &Kaminofen, &Ofen::Schalteneu );

	Lampenschalter( EventArgs( "lampe object Test" ) );
	Lampenschalter.add( &Stehlampe, &Lampe::Schalte );
	Ofenschalter( EventArgs( "ofen object Test" ) );
	Lampenschalter( EventArgs( "lampe object Test" ) );
}