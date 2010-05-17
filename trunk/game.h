/**
* $Id$
*/
#ifndef GAME_H
#define GAME_H

#include <stdlib.h>
#include "deck.h"
#include "players.h"
#include "dealer.h"
#include "ai.h"
#include "utils.h"

card * gamedeck;
card tablecards[5];
char choice[6][10];
int * gamendeck;
player * gameplayers;
struct handvalue dealerhand;
int pturn;
int nplayers;
int current;
int pot;
int endgame;
int max;
int gameround;
int check_f;

void initbets();
void initturn();
int checkbets();
void start ();
void pre_flop ();
void flop ();
void turn ();
void river ();
void showdown ();
void putpot (int qty,int who);
void next();
void inittablecards();
void showtablecards(int howmany);
void winners();
int istablecard(struct handvalue dealerhand, struct handvalue playerhand);
#endif
