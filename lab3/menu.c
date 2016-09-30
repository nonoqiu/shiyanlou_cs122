/*
*
*name:	menu.c
*desc:	zhu chengxu
*user:	qiuzaihui
*time:	20160930
*
*/

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int Help();
int Quit();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

static tDataNode head[] =
{
    { "help", "this is help cmd!", Help, &head[1] },
    { "version", "menu program v1.0.", NULL, &head[2] },
    { "register", "register a useraccount.", NULL, &head[3] },
    { "login", "login shiyanlou.", NULL, &head[4] },
    { "logout", "logout shiyanlou.", NULL, &head[5] },
    { "changePsd", "change your password.", NULL, &head[6] },
    { "publish", "publish a message.", NULL, &head[7] },
    { "quit", "bye bye!", Quit, NULL }
};

int main()
{
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd number > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if(p==NULL)
        {
            printf(" * This is a wrong cmd!\n");
            continue;
        }
        printf(" * %s\t-\t%s\n", p->cmd, p->desc);
        if(p->handler != NULL)
        {
            p->handler();
        }
    }
}

int Help()
{
    ShowAllCmd(head);
}

int Quit()
{
    exit(0);
    return 0;
}
