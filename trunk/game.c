/**
* $Id$
*/
#include "game.h"

void start ()
{

	deckinit();
	endgame = 0;
	gameround = 0;
	nplayers = PLAYERS;
	pturn = -1;

	if (isdbg())	
		showall(POKERDECK,NDECK);

	do
	{
		// showing for debug
		shuffle(NDECK);
		if (isdbg())
			showall(POKERDECK,NDECK);

	
		gamedeck = POKERDECK;
		gamendeck = NDECK;
		gameplayers = playerinit();
		deal(gamedeck,gamendeck,gameplayers);
		inittablecards();	
		pot = 0;

		gameround++;
		playerinitchoice(gameplayers);
		pre_flop();
	} while(!endgame);
}

void pre_flop ()
{
	initbets();
	initturn();	
	int i = 0;
	int tmppot = 0;

	unsigned short finish = 0;
	msg("-------------[Round %d]-----------\n",gameround);
	msg("PreFlop phase:\n");
	char option[80];
	char op;
	
	do 
	{

		if (gameplayers[current].human)
		{
			msg("[POT %d$]\n",pot);
			showplayers(gameplayers, pturn);
			msg("Please, select a choice:\n");
			msg("(c)Call:%d$\t",max);
			msg("(r)Raise:%d$\t",(max*2));
			if (check_f) { msg("(k)Check.\t"); }
			msg("(f)Fold.\t");
			msg("(q)Chicken.\n");
			scanf("%s",&option);
				
			dbg("You entered: %s\n",option);
			op = option[0];		
		}
		else // machine choice
		{
			op = decide(gameplayers[current],tablecards,check_f);
		}

		switch (op)
		{
			case 'c':	
					gameplayers[current].bet = max;
					gameplayers[current].choice = CALL;
					pot += max;
					check_f = 0;
					break;
							
			case 'r':
					gameplayers[current].bet = max * 2;
					gameplayers[current].choice = RAISE;
					pot += (max * 2);
					max *= 2;
					check_f = 0;
					break;		
					
			case 'k':	if (!check_f) {break;}
					gameplayers[current].bet = -1;
					gameplayers[current].choice = CHECK;
					break;		
		
			case 'f':	gameplayers[current].bet = -2;
					gameplayers[current].choice = FOLD;
					showdown();
					finish = 1;
					break;		

			case 'q':	finish = 1;
					endgame = 1;
					break;
			default:
					msg("\aWhat? repeat please.\n");
					break;		
		}	//switch
	
	
			dbg("[POT %d$]\n",pot);

		next();

	} while (!finish && !checkbets());	
	
	flop();

}

void flop ()
{

	msg("Flop phase:\n");
	showtablecards(3);
	initbets();
	int i = 0;
	int tmppot = 0;

	unsigned short finish = 0;
	char option[80];
	char op;
	
	do 
	{

		if (gameplayers[current].human)
		{

			showtablecards(3);
			msg("[POT %d$]\n",pot);
			showplayers(gameplayers, pturn);
			calculatehand(gameplayers,tablecards,1);
			msg("Please, select a choice:\n");
			msg("(c)Call:%d$\t",max);
			msg("(r)Raise:%d$\t",(max*2));
			if (check_f) { msg("(k)Check.\t"); }
			msg("(f)Fold.\t");
			msg("(q)Chicken.\n");
			scanf("%s",&option);
				
			dbg("You entered: %s\n",option);
			op = option[0];		
		}
		else // machine choice
		{
			op = decide(gameplayers[current],tablecards,check_f);
//			op = decide();
		}

		switch (op)
		{
			case 'c':	
					gameplayers[current].bet = max;
					gameplayers[current].choice = CALL;
					pot += max;
					check_f = 0;
					break;
							
			case 'r':
					gameplayers[current].bet = max * 2;
					gameplayers[current].choice = RAISE;
					pot += (max * 2);
					max *= 2;
					check_f = 0;
					break;		
					
			case 'k':	if (!check_f) {break;}
					gameplayers[current].bet = -1;
					gameplayers[current].choice = CHECK;
					break;		
		
			case 'f':	gameplayers[current].bet = -2;
					gameplayers[current].choice = FOLD;
					showdown();
					finish = 1;
					break;		

			case 'q':	finish = 1;
					endgame = 1;
					break;
			default:
					msg("\aWhat? repeat please.\n");
					break;		
		}	//switch
	
	
			dbg("[POT %d$]\n",pot);

		
		next();

	} while (!finish && !checkbets());	
	

	turn();
}

void turn ()
{
	msg("Turn phase:\n");
	initbets();
	showtablecards(4);
	unsigned short finish = 0;
	char option[80];
	char op;
	
	do 
	{

		if (gameplayers[current].human)
		{

			showtablecards(4);
			msg("[POT %d$]\n",pot);
			showplayers(gameplayers, pturn);
			calculatehand(gameplayers,tablecards,2);
			msg("Please, select a choice:\n");
			msg("(c)Call:%d$\t",max);
			msg("(r)Raise:%d$\t",(max*2));
			if (check_f) { msg("(k)Check.\t"); }
			msg("(f)Fold.\t");
			msg("(q)Chicken.\n");
			scanf("%s",&option);
				
			dbg("You entered: %s\n",option);
			op = option[0];		
		}
		else // machine choice
		{
			op = decide(gameplayers[current],tablecards,check_f);
//			op = decide();
		}

		switch (op)
		{
			case 'c':	
					gameplayers[current].bet = max;
					gameplayers[current].choice = CALL;
					pot += max;
					check_f = 0;
					break;
							
			case 'r':
					gameplayers[current].bet = max * 2;
					gameplayers[current].choice = RAISE;
					pot += (max * 2);
					max *= 2;
					check_f = 0;
					break;		
					
			case 'k':	if (!check_f) {break;}
					gameplayers[current].bet = -1;
					gameplayers[current].choice = CHECK;
					break;		
		
			case 'f':	gameplayers[current].bet = -2;
					gameplayers[current].choice = FOLD;
					showdown();
					finish = 1;
					break;		

			case 'q':	finish = 1;
					endgame = 1;
					break;
			default:
					msg("\aWhat? repeat please.\n");
					break;		
		}	//switch
	
	
			dbg("[POT %d$]\n",pot);

		
		next();

	} while (!finish && !checkbets());	

	river();
}

void river ()
{
	msg("River phase:\n");
	initbets();
	showtablecards(5);
	unsigned short finish = 0;
	char option[80];
	char op;
	
	do 
	{

		if (gameplayers[current].human)
		{

			showtablecards(5);
			msg("[POT %d$]\n",pot);
			showplayers(gameplayers, pturn);
			calculatehand(gameplayers,tablecards,3);
			msg("Please, select a choice:\n");
			msg("(c)Call:%d$\t",max);
			msg("(r)Raise:%d$\t",(max*2));
			if (check_f) { msg("(k)Check.\t"); }
			msg("(f)Fold.\t");
			msg("(q)Chicken.\n");
			scanf("%s",&option);
				
			dbg("You entered: %s\n",option);
			op = option[0];		
		}
		else // machine choice
		{
			op = decide(gameplayers[current],tablecards,check_f);
//			op = decide();
		}

		switch (op)
		{
			case 'c':	
					gameplayers[current].bet = max;
					gameplayers[current].choice = CALL;
					pot += max;
					check_f = 0;
					break;
							
			case 'r':
					gameplayers[current].bet = max * 2;
					gameplayers[current].choice = RAISE;
					pot += (max * 2);
					max *= 2;
					check_f = 0;
					break;		
					
			case 'k':	if (!check_f) {break;}
					gameplayers[current].bet = -1;
					gameplayers[current].choice = CHECK;
					break;		
		
			case 'f':	gameplayers[current].bet = -2;
					gameplayers[current].choice = FOLD;
					showdown();
					finish = 1;
					break;		

			case 'q':	finish = 1;
					endgame = 1;
					break;
			default:
					msg("\aWhat? repeat please.\n");
					break;		
		}	//switch
	
	
			dbg("[POT %d$]\n",pot);

			
		next();

	} while (!finish && !checkbets());	

	showdown();
}

void showdown ()
{
	msg("Showdown phase\n");
	showtablecards(5);
	showhands(gameplayers);
	gameround++;
}

// initbets 
void initbets()
{
	int i = 0;
	max = 20;
	check_f = 1;

	for (i=0;i<nplayers;i++)
	{
		gameplayers[i].bet = 0;		
	}
}
// initbets 
void initturn()
{
	pturn++;
	pturn = (pturn==nplayers)?0:pturn;
	current = pturn;
	msg("Current turn: %d\n",pturn);
}

// checkbets
int checkbets()
{
	int i = 0;
	
	// ph33r m| 1337 5k|llz 
	// while (!bets[i] || (i++)<=nplayers);
	// return bets[--i];
	
	for (i=0;i<nplayers;i++)
	{
		dbg("checkbet>%d> %d\n",i,gameplayers[i].bet);
		if (gameplayers[i].bet > -1 && gameplayers[i].bet < max) 
		{
			dbg("checkbet> NO!\n");
			return 0;
		}		
	}
			dbg("checkbet> OK!\n");
	
	return 1;
	
}

void putpot (int qty, int who)
{
}

void next ()
{
	current++;
	current = (current==nplayers)?0:current;
}

void inittablecards ()
{
	int i = 0;
	int begin = (nplayers * 2) + 1;
	int idx = begin;

	for (i=0;i<5;i++)
	{
		tablecards[i] = gamedeck[gamendeck[idx]];
		idx++;
	}
}

 

void showtablecards(int howmany)
{
	int i = 0;

	msg("Visible Cards: ");

	for (i=0;i<howmany;i++)
	{
		msg("%s ",tablecards[i].show);
	}
	msg("\n");
}

