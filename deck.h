/**
* $Id$
*/
#include "config.h"
#include "card.h"

#ifndef DECK_H
#define DECK_H


char * IMAGES[DECKSIZE];
int NDECK[DECKSIZE];

int DECKINDEX;

struct card POKERDECK[DECKSIZE];

void deckinit (void);
#endif

	

