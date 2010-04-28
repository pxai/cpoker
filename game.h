/**
* $Id$
*/
#ifndef GAME_H
#define GAME_H

#include <stdio.h>
#include <stdlib.h>
#include "deck.h"
#include "players.h"
#include "dealer.h"

card * gamedeck;
int * gamendeck;
player * gameplayers;
int nplayers;
int pot;
int endgame;
int bets[16];
int max;

void initbets();
int checkbets();
void start ();
void pre_flop ();
void flop ();
void turn ();
void river ();
void showdown ();

#endif
