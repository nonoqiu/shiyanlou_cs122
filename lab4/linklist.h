/************************************************/
/* FILE NAME 	: linklist.h			*/
/* MODULE NAME 	: linklist			*/
/* DESCRIPTION  : linklist for menu progrom	*/
/* AUTHOR      	: qzh				*/
/* DATE		: 2016/10/14			*/
/************************************************/

#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include "linktable.h"

/* data struct and its operations */
typedef struct DataNode
{
    tLinkTableNode *next;
    char* cmd;
    char* desc;
    int (*handler)();
}tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tLinkTable* head, char* cmd);

/* show all cmd in linklist */
int ShowAllCmd(tLinkTable* head);

#endif /*_LINK_LIST_H_*/
