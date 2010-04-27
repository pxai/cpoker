/**
* $Id$
*/
#include "game.h"

void start ()
{

	deckinit();
	endgame = 0;
	
	showall(POKERDECK,NDECK);

	do
	{
		// showing for debug
		shuffle(&NDECK);
		showall(POKERDECK,NDECK);

	
		gamedeck = POKERDECK;
		gamendeck = NDECK;
		gameplayers = playerinit();
		deal(gamedeck,gamendeck,gameplayers);
	
		pot = 0;


		pre_flop();

	} while(!endgame);
}

void pre_flop ()
{
	unsigned short finish = 0;
	printf("PreFlop phase:\n");
	char option[80];
	
	do 
	{
		showplayers(gameplayers);
		printf("Please, select a choice:\n");
		printf("(1)Call.\t");
		printf("(2)Raise.\t");
		printf("(3)Fold.\t");
		printf("(q)Chicken.\n");
		scanf("%s",&option);

		
		switch (option[0])
		{
			case '1':	 
							break;
									
			case '2':	 
							break;		
							
			case '3':	
							showdown();
							finish = 1;
							break;		

			case 'q':	finish = 1;
							endgame = 1;
							break;
			default:
							printf("\aWhat? repeat please.\n");
							break;		
		}	
		
		printf("You entered: %s\n",option);
	
	} while (!finish);
	
	flop();
	
}

void flop ()
{
	printf("Flop phase:\n");
	turn();
}

void turn ()
{
	printf("Turn phase:\n");
	river();
}

void river ()
{
	printf("River phase:\n");
	showdown();
}

void showdown ()
{
	printf("Showdown phase\n");
	showhands(gameplayers);
}
