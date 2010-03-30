/**
* $Id$
*/
#ifndef CARD_H
#define CARD_H

#define SPADES 1
#define HEARTS 2
#define CLUBS 3
#define DIAMONDS 4

typedef struct card
{
        // Card value: 1,2,3,4,...,10,11,12,13
        int value;

        // Card type: SPADES, HEARTS, CLUBS, DIAMONDS
        int type;

        // Card show: graphical representation
        char *show;

} card;


#endif

	

