#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "config.h"
#include "deck.h"
#include "symbols.h"
#include "dealer.h"
#include "players.h"
#include "game.h"

// gcc -o test deck.o dealer.o test.c
void printhand(card * h);

int main (void)
{
	unsigned long int players, money, color, c;
	struct player * cpokerplayers;
	card testhand[5];
	players = PLAYERS;
	money = TOTAL;
	color = 1;
	char car = ' ';

	printf("Numero: %d\n",PLAYERS);
	deckinit();
	showall(POKERDECK,NDECK);

	printf("A ver: %d",(0%13));
	while(1)
	{
		shuffle(NDECK);
		showall(POKERDECK,NDECK);

		for (c=0;c<5;c++)
		{
			testhand[c] = POKERDECK[NDECK[c]];
		}
		
		printf("Test HAND: ");
		printhand(testhand);
		sorthand(testhand);
		printf(" -> ");
		printhand(testhand);
		printf("\n");
		resolve(testhand);

		scanf("%c",&car);
	}
	return 1;
}


void printhand (card * h)
{
	int c = 0;

	for (c=0;c<5;c++)
	{
		printf(" %s",h[c].show);
	}
}
