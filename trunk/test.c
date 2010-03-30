#include <stdio.h>
#include "config.h"
#include "libtest.h"

int main (void)
{
	initgame();
	printf("Test para ver:\n");
	printf("Numero: %d\n",PLAYERS);
	return 1;
}
