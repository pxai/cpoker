/**
* $Id$
*/

#include "hand.h"


void printresult(struct handvalue hv)
{
	msg("hand:%s %d pts\n",hv.name,hv.value);
}

void printhand (card * h)
{
	int c = 0;

	for (c=0;c<5;c++)
	{
		msg(" %s",h[c].show);
	}
	msg("\n");
}
