#include "F_Delegate.h"

void F_Delegate::operator() ( EventArgs e )
{
	FireEvent( e );
}

void F_Delegate::add( F_Delegater CallBacktarget )
{
	Callbacktargetlist->push_back( CallBacktarget );
}

void F_Delegate::FireEvent( EventArgs args )
{
	for( list<F_Delegater>::iterator it = Callbacktargetlist->begin(); it != Callbacktargetlist->end(); it++ )
	{
		F_Delegater temp = *it;
		temp( args );
	}
}