/**
* $Id$
*/
#include "config.h"
#include "card.h"
#include <stdio.h>

#ifndef HAND_H
#define HAND_H

typedef card hand[HANDSIZE];

typedef struct handvalue {
	char * name;
	int value;	
} handvalue;

void inithand(card * cards);
void printresult(struct handvalue hv);
#endif

	

