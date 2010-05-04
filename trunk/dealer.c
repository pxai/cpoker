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
	printf("Showing players: \n");
	
	printf("\tPlayer %d Hand (you): %s %s %d %d$ %c\n",i,players[i].playerhand[0].show,players[i].playerhand[1].show,players[i].choice,players[i].bet,(turn==i?'*':' '));
	
	for (i=1;i<PLAYERS;i++)
		printf("\tPlayer %d Hand: X X %d %d$ %c\n",i,players[i].choice,players[i].bet,(i==turn?'*':' '));
}


void showhands (struct player * players)
{
	int i = 0;
	printf("Showing player hands: \n");
	
	for (i=0;i<PLAYERS;i++)
		printf("\t\tPlayer %d Hand: %s %s %d %d$ \n",i,players[i].playerhand[0].show,players[i].playerhand[1].show,players[i].choice,players[i].bet);
}

void showall (card * deck, int * ndeck)
{
	int i = 0;
	
	printf("Current DECK:\n");

	for(i=0;i<DECKSIZE;i++)
	{
		printf("%s,",deck[ndeck[i]].show);
	}

	printf("\n");
}


