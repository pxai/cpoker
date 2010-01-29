/**
* $Id$
*/
#include "utils.h"


void shuffle (int * deck)
{
	int i = 0;
	int num = 0;
	int tmp = 0;
	srandom(time(0));
	
	for(i=0;i<DECKSIZE;i++)
	{
		num = random() % DECKSIZE;
		
		tmp = deck[i];
		deck[i] = deck[num];
		deck[num] = tmp;
		
	}
	
}

void showall (char ** deck, int * ndeck)
{
	int i = 0;
	
	for(i=0;i<DECKSIZE;i++)
	{
		printf("%s,",deck[ndeck[i]]);
	}
}
