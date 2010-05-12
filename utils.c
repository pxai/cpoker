/**
* $Id$
*/
#include "utils.h"


int CPKDEBUG = 1;
char * CHARSET = "en-US";

// SET debug level.
void setdbg(int debuglevel)
{
	CPKDEBUG = debuglevel;
}


// SET charset
void setchrset(char * chrset)
{
	CHARSET = chrset;
	
	setlocale (LC_ALL, CHARSET);
   bindtextdomain (PACKAGE, LOCALEDIR);
   textdomain (PACKAGE);
}


// GET for debug level 
int isdbg()
{
	return CPKDEBUG;
}


void msg(char* format, ...) {
        va_list args;


        va_start(args, format);
        vfprintf(stdout,_(format),args);
        va_end(args);

}

// prefix
void msgp(char* format, ...) {
		  char msg[256]; 
        va_list args;

        va_start(args, format);
        snprintf(msg,256,"cPK> %s",_(format));
        vfprintf(stdout,msg,args);
        va_end(args);

}


void dbg(char* format, ...) {
        va_list args;

        if (!CPKDEBUG)
                return;

		  char msg[256]; 


        va_start(args, format);
        snprintf(msg,256,"dbg> %s",_(format));
        vfprintf(stdout,msg,args);
        va_end(args);

}
