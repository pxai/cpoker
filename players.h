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

#define NONE 0
#define CALL 1
#define RAISE 2
#define CHECK 3
#define FOLD 4

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

	// fold
	int choice;

	// bets
	int bet;
		
	// hand posibilities
	struct handvalue * handval;
} player;

struct player players[PLAYERS];

struct player * playerinit (void);

void playerinitchoice (struct player * pl);
#endif

	

