/**
* $Id$
*/
#include "game.h"

void start (card * deck, int * ndeck, struct  player * players)
{
	gamedeck = deck;
	gamendeck = ndeck;
	gameplayers = players;
	pre_flop();
	flop();
	turn();
	river();
	
}

void pre_flop ()
{
	printf("PreFlop phase\n");
}

void flop ()
{
	printf("Flop phase\n");
}

void turn ()
{
	printf("Turn phase\n");
}

void river ()
{
	printf("River phase\n");
}

void showdown (card * deck, int * ndeck)
{
	printf("Showdown phase\n");
}
