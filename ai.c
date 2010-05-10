/**
* $Id$
*/
#include "ai.h"

// decide
char decide (struct player p, card * tablec, int check_flag)
{
	int i = 0;
	int max = 2;
	char * options = "crkf";

	// is check possible?
	if (check_flag)
	{
		options = "ckrf";
		max = 3;
	}

	//srandom(time(0));
	// Raise prob: 20%
	if (random() % 100 > 69)
	{	
		i = random() % max;
	}
	else
	{
		
		i = (check_flag)?(random() % 2):0;
	}
	//i = 0;
	return options[i];	
}
