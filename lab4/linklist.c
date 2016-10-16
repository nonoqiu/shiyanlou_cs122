/************************************************/
/* FILE NAME 	: linklist.c			*/
/* MODULE NAME 	: linklist			*/
/* DESCRIPTION  : linklist for menu progrom	*/
/* AUTHOR      	: qzh				*/
/* DATE		: 2016/10/14			*/
/************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

tDataNode* FindCmd(tLinkTable* head, char* cmd)
{
    if(head == NULL || cmd == NULL)
    {
        return NULL;
    }

    tDataNode * p = (tDataNode*)GetLinkTableHead(head);
    while(p!=NULL)
    {
        if(!strcmp(p->cmd, cmd))
        {
            return p;
        }
        p = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)p);
    }
    return NULL;
}

int ShowAllCmd(tLinkTable* head)
{
    printf("Menu List:\n");
    tDataNode *p = (tDataNode*)GetLinkTableHead(head);
    while(p != NULL)
    {
        printf(" * %s\t-\t%s\n", p->cmd, p->desc);
        p = (tDataNode*)GetNextLinkTableNode(head, (tLinkTableNode*)p);
    }
    return 0;
}
