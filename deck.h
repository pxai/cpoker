/**
* $Id$
*/
#include <stdio.h>
#include "config.h"
#include "card.h"
#include "players.h"

#ifndef DECK_H
#define DECK_H


char * IMAGES[DECKSIZE];
int NDECK[DECKSIZE];

int DECKINDEX;

struct card POKERDECK[DECKSIZE];

void deckinit (void);


void calculatehand (struct player * p,card * tc, int phase);

struct handvalue resolve(card * phand);

void shorthand(card * phand);


#endif

	

