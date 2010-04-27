/**
* $Id$
*/
#include "config.h"
#include "hand.h"

#ifndef PLAYERS_H
#define PLAYERS_H

#define LIAR 1
#define RANDOM 2
#define WINNER 3

typedef struct player {
	// Player name
	char * name;
	
	// Human or not
	unsigned short human;
	
	// Player type: future use.
	int type;

	// Money
	int money;

	// card hand
	hand playerhand;
	
	// hand posibilities
	posibilities playerposibilities[12];
} player;

struct player players[PLAYERS];

struct player * playerinit (void);
#endif

	

