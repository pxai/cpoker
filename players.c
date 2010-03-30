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
		players[i].type = RANDOM;
		players[i].money = TOTAL;
	}

	return players;
}

