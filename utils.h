/**
* $Id$
*/
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <libintl.h>
#include <locale.h>
#include "config.h"

#define _(STRING)    gettext(STRING)

extern int CPKDEBUG;
extern char * CHARSET;

void setdbg(int debuglevel);
void setchrset(char * chrset);
int isdbg();
void msg(char *format, ...);
void msgp(char *format, ...);
void dbg(char *format, ...);
#endif
