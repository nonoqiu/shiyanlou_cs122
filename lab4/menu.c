/************************************************/
/* FILE NAME 	: linktable.h			*/
/* MODULE NAME 	: linktalbe			*/
/* DESCRIPTION  : interface of Link Table	*/
/* AUTHOR      	: qzh				*/
/* DATE		: 2016/10/14			*/
/************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"
#include "linktable.h"

int Help();
int Quit();

#define CMD_MAX_LEN 	128
#define DESC_LEN 	1024
#define CMD_NUM    	8

char appCmd[CMD_NUM][CMD_MAX_LEN] = { "help", "version", "register", "login", "logout", "changePsd", "publish", "quit"}; 
char appRemark[CMD_NUM][CMD_MAX_LEN] = { "this is help cmd!", "menu program v1.3.", "register a useraccount.",
				         "login shiyanlou.", "logout shiyanlou.", "change your password.",
				         "publish a message.", "bye bye!"};

int InitMenuData(tLinkTable ** pLinkTable)
{
     tDataNode * pNode = NULL;
     *pLinkTable = CreateLinkTable();  

     if ( pLinkTable == NULL )
     {
        printf("CreateLinkTable Error!\n");
        exit(0);
     }

     int i;
     for(i = 0; i < CMD_NUM; i++)
     {
        pNode = (tDataNode*)malloc(sizeof(tDataNode));  
        pNode->cmd = appCmd[i];  
        pNode->desc = appRemark[i];
	if( i==0 ) pNode->handler = Help;
	else if(i==7) pNode->handler = Quit;
	else pNode->handler = NULL;
        AddLinkTableNode(*pLinkTable, (tLinkTableNode*)pNode);
     }
     return 0;
}

tLinkTable * head = NULL;
int main()
{
    InitMenuData(&head);
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
