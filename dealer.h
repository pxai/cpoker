/**
* $Id$
*/
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "players.h"

void shuffle (int * deck);

void deal (card * deck, int * ndeck, struct  player * players);
void showplayers (struct player * players);
void showhands (struct player * players);

void showall (card * deck, int * ndeck);

#endif
