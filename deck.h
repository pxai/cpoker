/**
* $Id$
*/

#include "config.h"
#include "card.h"
#include "players.h"
#include "utils.h"

#ifndef DECK_H
#define DECK_H


char * IMAGES[DECKSIZE];
int NDECK[DECKSIZE];

int DECKINDEX;

struct card POKERDECK[DECKSIZE];

void deckinit (void);


struct handvalue calculatehand (struct player * p,card * tc, int phase);

struct handvalue resolve(card * phand);

void sorthand(card * phand);


#endif

	

