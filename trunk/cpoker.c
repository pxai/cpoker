/*
* $Id$
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "config.h"
#include "symbols.h"
#include "dealer.h"
#include "deck.h"
#include "players.h"
#include "game.h"
#include "utils.h"

int main (int argc, char * argv[])
{
	unsigned long int players, money, color, c;
	struct player * cpokerplayers;
	char * charst= "     ";
	int debug = 0;
	players = PLAYERS;
	money = TOTAL;
	color = 1;
	setdbg(debug);
	
	msg("Welcome to cpoker!!\n");
	
	while ((c = getopt (argc, argv, "p:m:c:d:l")) != -1)
         switch (c)
           {
           case 'p':
             players = (!strtoul(optarg,NULL, 0))?PLAYERS:strtoul(optarg,NULL, 0);
             break;
           case 'm':
             money = (!strtoul(optarg,NULL, 0))?TOTAL:strtoul(optarg,NULL, 0);
             break;
           case 'l':
           	 charst = optarg;
             setchrset(optarg);
             break;
           case 'c':
             color = 1;
           case 'd':
             setdbg(1);
             break;
           case '?':
             if (optopt == 'p' || optopt == 'm')
               msg("Option -%c requires an argument. Setting to default. \n", optopt);
             else if (isprint (optopt))
               msg("Unknown option `-%c'.\n", optopt);
             else
               msg("Unknown option character `\\x%x'.\n",optopt);
             return 1;
           default:
		abort();
           }

	msg("Arguments: %d %d %d %d %s\n",players,money,color,debug,charst);

	   
	// And here we go...
	start();
	
	msg("Thnx for playing cpoker!!\n built $Id$ \n");
	return 1;
}

