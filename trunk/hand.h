/**
* $Id$
*/
#include "config.h"
#include "card.h"

#ifndef HAND_H
#define HAND_H

typedef card hand[HANDSIZE];

typedef struct posibility {
	card handpos[TOTALHAND];
	char * handname;
	int handvalue;	
} posibility;

void inithand(card * cards);

#endif

	

