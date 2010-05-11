#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "config.h"
#include "deck.h"
#include "symbols.h"
#include "dealer.h"
#include "players.h"
#include "game.h"
#include "hand.h"

// gcc -o test deck.o dealer.o hand.o test.c
void printhand(card * h);

int main (void)
{
	unsigned long int players, money, color, c;
	struct player * cpokerplayers;
	struct handvalue result;
	struct handvalue bestresult;
	int j = 0;
	card testhand[5];
	card besthand[5];
	
	bestresult.value = 0;
	players = PLAYERS;
	money = TOTAL;
	color = 1;
	char car = ' ';

	printf("Numero: %d\n",PLAYERS);
	deckinit();
	showall(POKERDECK,NDECK);


	printf("A ver: %d",(0%13));
/*
   // test Royal flush
   testhand[0] = POKERDECK[9];
   testhand[1] = POKERDECK[10];
   testhand[2] = POKERDECK[11];
   testhand[3] = POKERDECK[12];
   testhand[4] = POKERDECK[0];
	printf("\nTest Royal flush: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
	
	scanf("%c",&car);

   // test Straight and flush
   testhand[0] = POKERDECK[1];
   testhand[1] = POKERDECK[2];
   testhand[2] = POKERDECK[3];
   testhand[3] = POKERDECK[4];
   testhand[4] = POKERDECK[5];
	printf("\nTest StraightFlush, Straight and flush: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
	
	scanf("%c",&car);

   // test Straight and flush 2
   testhand[0] = POKERDECK[0];
   testhand[1] = POKERDECK[1];
   testhand[2] = POKERDECK[2];
   testhand[3] = POKERDECK[11];
   testhand[4] = POKERDECK[12];
	printf("\nTest StraightFlush, Straight and flush 2 : \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
	
	scanf("%c",&car);
	
	   // test Straight and flush 3
   testhand[0] = POKERDECK[0];
   testhand[1] = POKERDECK[12];
   testhand[2] = POKERDECK[1];
   testhand[3] = POKERDECK[15];
   testhand[4] = POKERDECK[29];
	printf("\nTest StraightFlush, Straight and flush 3: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
	
	scanf("%c",&car);

   // test FLUSH
   testhand[0] = POKERDECK[1];
   testhand[1] = POKERDECK[4];
   testhand[2] = POKERDECK[6];
   testhand[3] = POKERDECK[8];
   testhand[4] = POKERDECK[10];
	printf("\nTest Flush: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
	
	scanf("%c",&car);
	
   	
   // test Two Pairs
   testhand[0] = POKERDECK[0];
   testhand[1] = POKERDECK[13];
   testhand[2] = POKERDECK[38];
   testhand[3] = POKERDECK[51];
   testhand[4] = POKERDECK[4];
	printf("\nTest Two Pairs: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
	
	scanf("%c",&car);
   // test Two Pairs 2
   testhand[1] = POKERDECK[0];
   testhand[2] = POKERDECK[13];
   testhand[3] = POKERDECK[38];
   testhand[4] = POKERDECK[51];
   testhand[0] = POKERDECK[4];
	printf("\nTest Two Pairs: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
	
	scanf("%c",&car);

   // test Three of a kind
   testhand[0] = POKERDECK[0];
   testhand[1] = POKERDECK[13];
   testhand[2] = POKERDECK[26];
   testhand[3] = POKERDECK[51];
   testhand[4] = POKERDECK[4];
	printf("\nTest Three of a Kind: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);

	scanf("%c",&car);

   // test Three of a kind 2
   testhand[0] = POKERDECK[0];
   testhand[1] = POKERDECK[1];
   testhand[2] = POKERDECK[2];
   testhand[3] = POKERDECK[15];
   testhand[4] = POKERDECK[28];
	printf("\nTest Three of a Kind 2: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);

   // test FULLHOUSE
   testhand[4] = POKERDECK[1];
   testhand[1] = POKERDECK[13];
   testhand[2] = POKERDECK[26];
   testhand[3] = POKERDECK[27];
   testhand[0] = POKERDECK[14];
	printf("\nTest FULLHOUSE: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
   
	scanf("%c",&car);	
   // test Four of a kind
   testhand[1] = POKERDECK[0];
   testhand[2] = POKERDECK[13];
   testhand[3] = POKERDECK[26];
   testhand[4] = POKERDECK[39];
   testhand[0] = POKERDECK[4];
	printf("\nTest Four of a Kind: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
   	
	scanf("%c",&car);

   // test Four of a kind 2
   testhand[1] = POKERDECK[0];
   testhand[2] = POKERDECK[14];
   testhand[3] = POKERDECK[27];
   testhand[4] = POKERDECK[40];
   testhand[0] = POKERDECK[1];
	printf("\nTest Four of a Kind 2: \n");
	sorthand(testhand);
	printhand(testhand);	
   result = resolve(testhand);
   printresult(result);
   	
	scanf("%c",&car);
*/	
	int total = 1000;			
	//while(--total>0)
	while(1)
	{
		
		shuffle(NDECK);
		//showall(POKERDECK,NDECK);

		for (c=0;c<5;c++)
		{
			testhand[c] = POKERDECK[NDECK[c]];
		}
		
		sorthand(testhand);
		result = resolve(testhand);
		printf("\nBest hand (%dpts): %s: ",result.value,result.name);
		printhand(testhand);
		/*		
		if (result.value>bestresult.value)
		{
			bestresult.value = result.value;
			bestresult.name = result.name;
			for (j=0;j<5;j++)
				besthand[j] = testhand[j];
		}
*/
		if (result.hand==FOUR_OF_A_KIND) {scanf("%c",&car);}
	}
	
	printf("Best hand (%dpts): %s\n",bestresult.value,bestresult.name);
	printhand(besthand);
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
