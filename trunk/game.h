/**
* $Id$
*/
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "players.h"
#include "dealer.h"

card * gamedeck;
int * gamendeck;
player * gameplayers;
int pot;
int endgame;

void start ();
void pre_flop ();
void flop ();
void turn ();
void river ();
void showdown ();

#endif
