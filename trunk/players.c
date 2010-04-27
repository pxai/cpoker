/**
* $Id$
*/

#include "players.h"


struct player * playerinit (void)
{
	int i = 0;
	for (i=0;i<PLAYERS;i++)
	{
		players[i].name = "player";
		players[i].human = 0;
		players[i].type = RANDOM;
		players[i].money = TOTAL;
	}
	
	// Firs player will be human...
	players[0].human = 1;

	return players;
}

