/**
* $Id$
*/
#include "dealer.h"

void shuffle (int * deck)
{
	int i = 0;
	int num = 0;
	int tmp = 0;
	srandom(time(0));
	
	for(i=0;i<DECKSIZE;i++)
	{
		num = random() % DECKSIZE;
		
		tmp = deck[i];
		deck[i] = deck[num];
		deck[num] = tmp;
		
	}
	
}

/*
* deal
* Deals cards for players
*/
void deal (card * deck, int * ndeck,struct  player * players)
{
	int i,j,k;
	i = j = k = 0;

	for(i=0;i<2;i++)
		for (j=0;j<PLAYERS;j++)
			players[j].playerhand[i] =  deck[ndeck[k++]];

}

void showplayers (struct player * players, int turn)
{
	int i = 0;
	msg("Showing players: \n");
	
	msg("\tPlayer %d Hand (you): %s %s %d %d$ - %s:(%d) %c\n",i,players[i].playerhand[0].show,players[i].playerhand[1].show,players[i].choice,players[i].money,players[i].handval.name,players[i].handval.value,(turn==i?'*':' '));
	
	for (i=1;i<PLAYERS;i++)
		msg("\tPlayer %d Hand (you): %s %s %d %d$ - %s:(%d) %c\n",i,players[i].playerhand[0].show,players[i].playerhand[1].show,players[i].choice,players[i].money,players[i].handval.name,players[i].handval.value,(turn==i?'*':' '));
//		msg("\tPlayer %d Hand: X X %d %d$ %c\n",i,players[i].choice,players[i].money,(i==turn?'*':' '));
}


void showhands (struct player * players)
{
	int i = 0;
	msg("Showing player hands: \n");
	
	for (i=0;i<PLAYERS;i++)
		msg("\t\tPlayer %d Hand: %s %s %d %d$ - %s:(%d) \n",i,players[i].playerhand[0].show,players[i].playerhand[1].show,players[i].choice,players[i].bet,players[i].handval.name,players[i].handval.value);
}

void showall (card * deck, int * ndeck)
{
	int i = 0;
	
	msg("Current DECK:\n");

	for(i=0;i<DECKSIZE;i++)
	{
		msg("%s,",deck[ndeck[i]].show);
	}

	msg("\n");
}


