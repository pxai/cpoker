# $Id$
# Makefile for cpoker
# For alternative use make -f othermakefile

CC = gcc
CFLAGS = -O
OBJS = utils.o deck.o

all=cpoker

cpoker: $(OBJS)
	$(CC) $(CFLAGS)	-o cpoker $(OBJS) cpoker.c

utils.o: utils.c
	$(CC) -c utils.c


deck.o: deck.c
	$(CC) -c deck.c

clean:
	-$(RM) cpoker *.o