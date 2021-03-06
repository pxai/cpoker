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

char * deck_plain[DECKSIZE] = {
	"As","2s","3s","4s","5s","6s","7s","8s","9s","10s","Js","Qs","Ks",
	"Ah","2h","3h","4h","5h","6h","7h","8h","9h","10h","Jh","Qh","Kh",
	"Ac","2c","3c","4c","5c","6c","7c","8c","9c","10c","Jc","Qc","Kc",
	"Ad","2d","3d","4d","5d","6d","7d","8d","9d","10d","Jd","Qd","Kd"
	};
	
char * deck_only_text[DECKSIZE] = {
	"A♠","2♠","3♠","4♠","5♠","6♠","7♠","8♠","9♠","10♠","J♠","Q♠","K♠",
	"A♥","2♥","3♥","4♥","5♥","6♥","7♥","8♥","9♥","10♥","J♥","Q♥","K♥",
	"A♣","2♣","3♣","4♣","5♣","6♣","7♣","8♣","9♣","10♣","J♣","Q♣","K♣",
	"A♦","2♦","3♦","4♦","5♦","6♦","7♦","8♦","9♦","10♦","J♦","Q♦","K♦"
	};

int NDECK[DECKSIZE] = {0,1,2,3,4,5,6,7,8,9,10,11,12,
		       13,14,15,16,17,18,19,20,21,22,23,24,25,
		       26,27,28,29,30,31,32,33,34,35,36,37,38,
	               39,40,41,42,43,44,45,46,47,48,49,50,51
			};
			
int combturn[4][3]= {{0,1,2},{0,1,3},{0,2,3},{1,2,3}};
int combriver[10][3] ={{0,1,2},{0,2,3},{0,1,3},{0,1,4},{0,2,4},{0,3,4},{1,2,3},{1,2,4},{1,3,4},{2,3,4}};



void deckinit (int dtype)
{
	DECKINDEX = 0;
	int type[4] = {1,2,3,4};
	int i,t, value;
	i = t = value = 0;

	for (i=0;i<DECKSIZE;i++)	
	{
		t = (i/13) + 1;
		value = (!(i%13))?14:(i%13)+1;
		POKERDECK[i].value = value;
		POKERDECK[i].type = type[t];
		POKERDECK[i].show = IMAGES[i];
		//POKERDECK[i].show = deck_plain[i];
	}

}

/*
* This is... the mother of the little lamb xD
*/
void  calculatehand (struct player * p, int n, card * tc,int phase)
{
 int i,j, k, x;
 i = j = k = x = 0;
 
  card tmphand[5]; 
 struct handvalue result,besthand;
  
  
 for (x=0;x<n;x++)
 {
 	tmphand[0] = p[x].playerhand[0];
 	tmphand[1] = p[x].playerhand[1];
 	besthand.value = 0;		
	dbg("%d player hand------------------------------\n",x);
 	
 	switch (phase)
 	{
		 		
 		// FLOP 
		case 1 : 
		 		tmphand[2] = tc[0];
		 		tmphand[3] = tc[1];
		 		tmphand[4] = tc[2];
       		sorthand(tmphand);
		 		result = resolve(tmphand);
		 		if (result.value > besthand.value) { besthand = result;  }
		 		break;
		 		
		// TURN
		case 2 : 
				for (i=0;i<4;i++)
				{
				 	tmphand[0] = p[x].playerhand[0];
 					tmphand[1] = p[x].playerhand[1];
					for (j=0;j<3;j++)
					{
				 		tmphand[(j+2)] = tc[combturn[i][j]];
					}
	       		sorthand(tmphand);
			 		result = resolve(tmphand);
			 		if (result.value > besthand.value) { besthand = result; }
				}
		 		break;

		// RIVER
		case 3 : 
				for (i=0;i<10;i++)
				{
				 	tmphand[0] = p[x].playerhand[0];
 					tmphand[1] = p[x].playerhand[1];
					for (j=0;j<3;j++)
					{
				 		tmphand[(j+2)] = tc[combriver[i][j]];
					}
	       		sorthand(tmphand);
			 		result = resolve(tmphand);
			 		if (result.value > besthand.value) { besthand = result; }
				}
			 	

		 		break;

		default: break;
 	}
 
 
 	p[x].handval = besthand;
 
 } // for
// return besthand;
 
}

struct handvalue  resolve (card * phand)
{
	int i = 0, j = 0, tmp = 0;

	struct handvalue result;
	
	card prev, current;
	int pairs[2] = {0,0};
	int three = -1;
	int idx = 0;
	// Checks for
	char * debug[20] = {"Highest card","Pairs", "Two Pairs", "Three of a Kind", "Straight", "Flush","Fullhouse", "Four of a Kind", "Straight Flush", "Royal flush"};
	int handvalue[10] = {0,100,200,300,400,500,600,700,800,1000};
	int checks[10] = {1,1,1,1,1,1,0,1,1,0};
	int what[10] = {0,0,0,0,1,1,0,0,0,0};
	int totalvalue = 0;
	
	totalvalue = phand[0].value;


	// Check for straight special cases: e.g. 2,3,4,K,A
	// It's an ACE?
	if (phand[4].value == 14 && phand[0].value == 2)
	{
		//msg("Possible Special CASE of straight");
		for (i=1;i<4;i++)
			if ((phand[i-1].value+1) != phand[i].value) {break;}
		
		for (j=i;j<4;j++)
			if (phand[j].value+1 != phand[j+1].value) 
				{//msg("out: [%d] %d %d\n",j,phand[j].value,phand[j+1].value);
					what[4] = what[8] = what[9] = checks[4] = checks[8] = checks[9] = 0;
					break;
				}

		// STRAIGHT DETECTED		
		if (j==4)
		{
			//msg("Straight detected!!");
			what[4] = 1;
			checks[4] = checks[8] = checks[9] = 0;
		}
	}	
	
	
	for (i=1;i<5;i++)
	{
		totalvalue += phand[i].value;
		
		prev = phand[i-1];
		current = phand[i];
		for (j=0;j<10;j++)
		{
			if (!checks[j]) {continue;}

			switch (j)
			{
				case 0: // HIGHEST
					what[j] = 1;
					break;
				case 1: // PAIRS [OK]
					if (prev.value == current.value)
					{
						idx = (!pairs[0])?0:1;
						pairs[idx] = prev.value;
						what[j] = 1;
					}
					break;
				case 2: // TWO PAIRS
					if (pairs[0] && pairs[1] && i>2)
					{
						what[j] = 1;
					}
					break;
				case 3: // THREE OF A KIND
					if ( i<4 && (pairs[0] == current.value && pairs[0] == phand[i+1].value) ||  
		     			(pairs[1] == current.value && pairs[1] == phand[i+1].value)   )
		     		{
						what[j] = 1;
						three = current.value;
					}
					break;
				case 4: // STRAIGHT 
					if (prev.value+1 != current.value)
						checks[j] = what[j]  = 0;
					break;
				case 5: // FLUSH
					if (prev.type != current.type)
						checks[j] = what[j]  = 0;
					break;
				case 7: // FOUR OF A KIND
					if (i==2 && prev.type != current.type)
						checks[j] = what[j]  = 0;
					break;
				default:
					break;
			} // end switch

		} // end for
	} // end for
	
	// Check FULLHOUSE
	if ((phand[0].value == phand[1].value && phand[3].value == phand[4].value) &&
			(phand[1].value == phand[2].value || phand[2].value == phand[3].value) )
	{
		what[6] = 1;
	}

	// Check FOUR OF A KIND
	if ((phand[1].value == phand[2].value && phand[2].value == phand[3].value) &&
			(phand[0].value == phand[1].value || phand[3].value == phand[4].value) )
	{
		what[7] = 1;
	}
	
	// STRAIGHT FLUSH
	if (what[4] && what[5])
	{
		what[8] = 1;
	}
	
	// ROYAL STRAIGHT FLUSH
	if (what[8] && phand[0].value == 10)
	{
		what[9] = 1;
	}
	
	for (i=9;i>=0;i--)
	{	
		if (what[i]) {break;}
	}

	// debug
	if (isdbg())
			for (j=0;j<10;j++) {dbg("What: %s = %d: %d\n",debug[j],j,what[j]);}

		
	
	//msg("\n");

	result.value = (handvalue[i]+totalvalue);
	result.name = debug[i];
	result.hand = i;

	return result;

}

/*
* performs a sort operation in possible hand
* this is auxiliary to hand determination
*/
void sorthand (card * phand)
{
	int i, j;
	card tmp;

//	for (i=0;i<5;i++) msg("%d %s\n",i,phand[i].show);

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

//	for (i=0;i<5;i++) msg("%d %s\n",i,phand[i].show);
	
}
