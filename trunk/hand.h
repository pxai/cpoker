/**
* $Id$
*/
#include "config.h"
#include "card.h"
#include "utils.h"

#ifndef HAND_H
#define HAND_H

#define HIGHEST 0
#define PAIR 1
#define DOUBLEPAIR 2
#define THREE_OF_A_KIND 3
#define STRAIGHT 4
#define FLUSH 5
#define FULLHOUSE 6
#define FOUR_OF_A_KIND 7
#define STRAIGHT_FLUSH 8
#define ROYAL_FLUSH 9

typedef card hand[HANDSIZE];

typedef struct handvalue {
	char * name;
	int value;	
	int hand;
	card * cards;	
} handvalue;

int combturn[4][3];
int combriver[10][3];

void inithand(card * cards);
void printresult(struct handvalue hv);
void printhand (card * h);
#endif

	

