/**
* $Id$
*/
#ifndef UTILS_H
#define UTILS_H


#include <stdlib.h>
#include "deck.h"
#include "players.h"
#include "utils.h"

void shuffle (int * deck);

void deal (card * deck, int * ndeck, struct  player * players);
void showplayers (struct player * players, int turn);
void showhands (struct player * players);
void showall (card * deck, int * ndeck);

#endif
