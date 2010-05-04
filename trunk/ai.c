/**
* $Id$
*/
#include "ai.h"

// decide
char decide ()
{
	int i = 0;
	char * options = "crkf";
	//srandom(time(0));
	// Raise prob: 20%
	if (random() % 100 > 79)
	{	
		i = random() % 2;
	}
	else
	{
		i = 0;
	}
	//i = 0;
	return options[i];	
}
