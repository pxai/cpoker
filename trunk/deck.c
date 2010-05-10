/**
* $Id$
*/

#include "deck.h"


char * IMAGES[DECKSIZE] = {
	"\033[0;40;32mA♠\033[0m","\033[0;40;32m2♠\033[0m","\033[0;40;32m3♠\033[0m","\033[0;40;32m4♠\033[0m","\033[0;40;32m5♠\033[0m","\033[0;40;32m6♠\033[0m","\033[0;40;32m7♠\033[0m","\033[0;40;32m8♠\033[0m","\033[0;40;32m9♠\033[0m","\033[0;40;32m10♠\033[0m","\033[0;40;32mJ♠\033[0m","\033[0;40;32mQ♠\033[0m","\033[0;40;32mK♠\033[0m",
	"\033[0;40;31mA♥\033[0m","\033[0;40;31m2♥\033[0m","\033[0;40;31m3♥\033[0m","\033[0;40;31m4♥\033[0m","\033[0;40;31m5♥\033[0m","\033[0;40;31m6♥\033[0m","\033[0;40;31m7♥\033[0m","\033[0;40;31m8♥\033[0m","\033[0;40;31m9♥\033[0m","\033[0;40;31m10♥\033[0m","\033[0;40;31mJ♥\033[0m","\033[0;40;31mQ♥\033[0m","\033[0;40;31mK♥\033[0m",
	"\033[0;40;32mA♣\033[0m","\033[0;40;32m2♣\033[0m","\033[0;40;32m3♣\033[0m","\033[0;40;32m4♣\033[0m","\033[0;40;32m5♣\033[0m","\033[0;40;32m6♣\033[0m","\033[0;40;32m7♣\033[0m","\033[0;40;32m8♣\033[0m","\033[0;40;32m9♣\033[0m","\033[0;40;32m10♣\033[0m","\033[0;40;32mJ♣\033[0m","\033[0;40;32mQ♣\033[0m","\033[0;40;32mK♣\033[0m",
	"\033[0;40;31mA♦\033[0m","\033[0;40;31m2♦\033[0m","\033[0;40;31m3♦\033[0m","\033[0;40;31m4♦\033[0m","\033[0;40;31m5♦\033[0m","\033[0;40;31m6♦\033[0m","\033[0;40;31m7♦\033[0m","\033[0;40;31m8♦\033[0m","\033[0;40;31m9♦\033[0m","\033[0;40;31m10♦\033[0m","\033[0;40;31mJ♦\033[0m","\033[0;40;31mQ♦\033[0m","\033[0;40;31mK♦\033[0m"
	};

int NDECK[DECKSIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,
		       13,14,15,16,17,18,19,20,21,22,23,24,25,
		       26,27,28,29,30,31,32,33,34,35,36,37,38,
	               39,40,41,42,43,44,45,46,47,48,49,50,51
			};

void deckinit (void)
{
	DECKINDEX = 0;
	int type[4] = {1,2,3,4};
	int i,t, value;
	i = t = value = 0;

	for (i=0;i<DECKSIZE;i++)	
	{
		t = (i/13) + 1;
		value = (!(i%13))?13:i%13;
		POKERDECK[i].value = value;
		POKERDECK[i].type = type[t];
		POKERDECK[i].show = IMAGES[i];
	}

}

/*
* This is... the mother of the little sheep xD
*/
void calculatehand (struct player * p, card * tc,int phase)
{
 card tmphand[5];
 
 switch (phase)
 {
	case 1 : tmphand[0] = p->playerhand[0];
		 tmphand[1] = p->playerhand[1];
		 tmphand[2] = tc[0];
		 tmphand[3] = tc[1];
		 tmphand[4] = tc[2];
                 sorthand(tmphand);
		 resolve(tmphand);
		 break;

	default: break;
 }
 
}

void resolve (card * phand)
{
	int i = 0, j = 0;
	card prev, current;
	int pairs[2] = {0,0};
	int idx = 0;
	// Checks for
	char * debug[20] = {"Royal flush", "Straight Flush", "Four of a Kind", "Fullhouse", "Flush","Straight", "Three of a Kind", "Two Pairs", "Pairs", "Highest card"};
	int checks[10] = {1,1,1,1,1,1,1,1,1,1};
	
	for (i=1;i<5;i++)
	{
		prev = phand[i-1];
		current = phand[i];
		for (j=0;j<10;j++)
		{
			if (!checks[j]) {continue;}

			switch (j)
			{
				case 0: // ROYAL FLUSH?
					if (phand[0].value != 10)
						checks[j] = 0;
					break;
				case 1: // STRAIGHT FLUSH?
					if (prev.value+1 != current.value || prev.type != current.type)
						checks[j] = 0;
					break;
				case 2: // FOUR OF A KIND?
					if (j==2 && !pairs[0] && prev.value != current.value)
						checks[j] = 0;
					break;
				case 3: // FULLHOUSE
					checks[j] = 0;
					break;
				case 4: // FLUSH
					if (prev.type != current.type)
						checks[j] = 0;
					break;
				case 5: // STRAIGHT
					if (prev.value+1 != current.value)
						checks[j] = 0;
					break;
				case 6: // THREE OF A KIND
					if ( !(pairs[0] == prev.value && pairs[0] == current.value) ||  
   					     !(pairs[1] == prev.value && pairs[0] == current.value)   )
						checks[j] = 0;
					break;
				case 7: // TWO PAIRS
					if (j>3 && (!pairs[0] || !pairs[1]))
					{
						checks[j] = 0;
					}
					break;
				case 8: // PAIRS
					if (prev.value == current.value)
					{
						idx = (!pairs[0])?0:1;
						pairs[idx] = prev.value;
						checks[j] = 1;
					}
					if (i==4 && !pairs[0] )
						checks[j] = 0;
					break;
				case 9: // HIGHEST
					checks[j] = 1;
					break;
				default:
					break;
			} // end switch
		} // end for
	} // end for

	for (i=0;i<10;i++)
	{	
		printf("check: %s = %d: %d\n",debug[i],i,checks[i]);
	}
}

/*
* performs a sort operation in possible hand
* this is auxiliary to hand determination
*/
void sorthand (card * phand)
{
	int i, j;
	card tmp;

//	for (i=0;i<5;i++) printf("%d %s\n",i,phand[i].show);

	i = j = 0;

	for (i=1;i<5;i++)
	{
		tmp = phand[i];
		j = i - 1; 
		while(j>-1 && (phand[j].value > tmp.value))
		{
			phand[j+1] = phand[j];
			j = j - 1;
		}
		
		phand[j+1] = tmp;
	}

//	for (i=0;i<5;i++) printf("%d %s\n",i,phand[i].show);
	
}
