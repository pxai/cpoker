# $Id$
# Makefile for cpoker
# For alternative use make -f othermakefile

CC = gcc
CFLAGS = -O
OBJS = dealer.o deck.o players.o hand.o game.o ai.o utils.o
OBJTEST = deck.o dealer.o hand.o utils.o
MSG=echo OK

all=cpoker

cpoker: $(OBJS)
	$(CC) $(CFLAGS)	-o cpoker $(OBJS) cpoker.c 
	$(MSG)

test: $(OBJTEST)
	$(CC) -o test $(OBJTEST) test.c

ai.o: ai.c
	$(CC) -c ai.c
	
game.o: game.c
	$(CC) -c game.c

dealer.o: dealer.c
	$(CC) -c dealer.c


deck.o: deck.c
	$(CC) -c deck.c

players.o: players.c
	$(CC) -c players.c

hand.o: hand.c
	$(CC) -c hand.c

utils.o: utils.c
	 $(CC) -c utils.c
	 
clean:
	-$(RM) cpoker *.o
