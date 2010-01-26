/*
* $Id$
*/

#include <stdio.h>
#include "symbols.h"
#include "utils.h"
#include "deck.h"

int main ()
{
	printf("Welcome to cpoker\n");
	printf("Let's see: %s\n",POKERDECK[0]);
	showall(POKERDECK);
	shuffle(&POKERDECK);
	showall(POKERDECK);
	return 1;
}

