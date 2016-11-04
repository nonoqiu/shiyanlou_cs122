/************************************************/
/* FILE NAME    : test.c                        */
/* MODULE NAME  : text                          */
/* DESCRIPTION  : This is a start entrance      */
/* AUTHOR       : qzh                           */
/* DATE         : 2016/11/4                     */
/************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "menu.h"

#define FONTSIZE 10

int Quit(int argc, char *argv[])
{
    /* add XXX clean ops */
	exit(0);
}

int Time(int argc, char *argv[])
{
    time_t tt;
    struct tm *t;
    tt = time(NULL);
    t = localtime(&tt);
    printf("time:%d-%d-%d %d:%d:%d\n",t->tm_year+1900, t->tm_mon, t->tm_mday, t->tm_hour, t->tm_min, t->tm_sec);
    return 0;
}
int main()
{
    SetPrompt("MenuOS>>");
    MenuConfig("version","Menu program V1.0",NULL);
    MenuConfig("quit","Quit from MenuOS", Quit);
    MenuConfig("time","Show System Time", Time);
    MenuConfig("register","register a useraccount.",NULL);
    MenuConfig("login","login shiyanlou.",NULL);
    MenuConfig("logout","logout shiyanlou.",NULL);
    ExecuteMenu();
}
