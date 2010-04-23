/**
* $Id$
*/
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "players.h"

card * gamedeck;
int * gamendeck;
player * gameplayers;

void start (card * deck, int * ndeck, struct  player * players);
void pre_flop ();
void flop ();
void turn ();
void river ();
void showdown (card * deck, int * ndeck);

#endif
