/**
* $Id$
*/
#include "game.h"

void start ()
{

	deckinit();
	endgame = 0;
	nplayers = PLAYERS;
	
	showall(POKERDECK,NDECK);

	do
	{
		// showing for debug
		shuffle(NDECK);
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
	initbets();	
	int i = 0;

	unsigned short finish = 0;
	printf("PreFlop phase:\n");
	char option[80];
	
	do 
	{


		for (i=0;i<nplayers;i++)
		{

			if (gameplayers[i].human)
			{

				showplayers(gameplayers);
				printf("Please, select a choice:\n");
				printf("(c)Call.\t");
				printf("(r)Raise.\t");
				printf("(k)Check.\t");
				printf("(f)Fold.\t");
				printf("(q)Chicken.\n");
				scanf("%s",&option);
		
				switch (option[0])
				{
					case 'c':	bets[0] = 1;
									break;
									
					case 'r':	bets[0] = 1;
									break;		
							
					case 'k':	bets[0] = 0;
									break;		
					case 'f':	bets[0] = 1;
									showdown();
									finish = 1;
									break;		

					case 'q':	finish = 1;
									endgame = 1;
									break;
					default:
									printf("\aWhat? repeat please.\n");
									break;		
				}	//switch
		
				printf("You entered: %s\n",option);
	
			}
			else // machine choice
			{
			}
			
		} //for
		
	} while (!finish);
	
	
	flop();
	
}

void flop ()
{
	printf("Flop phase:\n");
	initbets();
	turn();
}

void turn ()
{
	printf("Turn phase:\n");
	initbets();
	river();
}

void river ()
{
	printf("River phase:\n");
	initbets();
	showdown();
}

void showdown ()
{
	printf("Showdown phase\n");
	showhands(gameplayers);
}

// initbets 
void initbets()
{
	int i = 0;
	max = 0;
	
	for (i=0;i<nplayers;i++)
	{
		bets[i] = 0;		
	}
}

// checkbets
int checkbets()
{
	int i = 0;
	int result = 1;
	
	// ph33r m| 1337 5k|llz 
	// while (!bets[i] || (i++)<=nplayers);
	// return bets[--i];
	
	for (i=0;i<nplayers;i++)
	{
		if (bets[i] == 0) 
		{
			result = 0;
			break;
		}		
	}
	
	return result;
	
}
