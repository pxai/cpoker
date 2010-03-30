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

int main (int argc, char * argv[])
{
	unsigned long int players, money, color, c;
	struct player * cpokerplayers;
	
	players = PLAYERS;
	money = TOTAL;
	color = 1;
	
	printf("Welcome to cpoker!!\n");
	
	while ((c = getopt (argc, argv, "p:m:c")) != -1)
         switch (c)
           {
           case 'p':
             players = (!strtoul(optarg,NULL, 0))?PLAYERS:strtoul(optarg,NULL, 0);
             break;
           case 'm':
             money = (!strtoul(optarg,NULL, 0))?TOTAL:strtoul(optarg,NULL, 0);
             break;
           case 'c':
             color = 1;
             break;
           case '?':
             if (optopt == 'p' || optopt == 'm')
               fprintf (stderr, "Option -%c requires an argument. Setting to default. \n", optopt);
             else if (isprint (optopt))
               fprintf (stderr, "Unknown option `-%c'.\n", optopt);
             else
               fprintf (stderr,"Unknown option character `\\x%x'.\n",optopt);
             return 1;
           default:
		abort();
           }

	printf("Arguments: %d %d %d\n",players,money,color);
	   
	deckinit();

	printf("Let's see: %s\n",POKERDECK[20].show);

	showall(POKERDECK,NDECK);
	shuffle(&NDECK);
	showall(POKERDECK,NDECK);
	cpokerplayers = playerinit();
	deal(POKERDECK,NDECK,cpokerplayers);
	   
	showhands(cpokerplayers);

	printf("Thnx for playing cpoker!!\n");
	return 1;
}

