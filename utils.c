/**
* $Id$
*/
#include "utils.h"


void shuffle (char **deck)
{
	int i = 0;
	int num = 0;
	char tmp[80] ="";
	
	for(i=0;i<DECKSIZE;i++)
	{
		num = rand() % DECKSIZE;
		//printf("%d,",num);
		/*
		tmp = *deck[i];
		deck[i] = *deck[num];
		deck[num] = *tmp;
		*/
	}
	
}

void showall (char ** deck)
{
	int i = 0;
	
	for(i=0;i<DECKSIZE;i++)
	{
		printf("%s,",deck[i]);
	}
}
