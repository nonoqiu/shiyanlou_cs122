/************************************************/
/* FILE NAME 	: linktable.h			*/
/* MODULE NAME 	: linktalbe			*/
/* DESCRIPTION  : interface of Link Table	*/
/* AUTHOR      	: qzh				*/
/* DATE		: 2016/10/14			*/
/************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "linktable.h"

/* 
 * Create a LinkTable 
 */
tLinkTable *CreateLinkTable()
{
     tLinkTable *pTable = (tLinkTable*)malloc(sizeof(tLinkTable));  
     pTable->pHead = NULL;  
     pTable->pTail = NULL;  
     pTable->SumOfNode = 0;  
  
     return pTable;
}

/* 
 * Delete a LinkTalbe 
 */
int DeleteLinkTable(tLinkTable *pLinkTable)
{
     free(pLinkTable);  
     return 0; 
}

/* 
 * Add a LinkTableNode to LinkTable 
 */
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
     if (pLinkTable == NULL)   
     {  
          printf("The table is empty and cannot add this node!\n");  
          exit(0);   
     }  
  
     if (pNode == NULL)  
     {  
          printf("The node is empty and cannot add this node!\n");  
          return 0;  
     }  
  
     if (pLinkTable->pHead == NULL)  
     {  
          pLinkTable->pHead = pNode;  
          pLinkTable->pTail = pNode;  
          pLinkTable->SumOfNode = 1;  
     }
     else  
     {  
          pLinkTable->pTail->pNext = pNode;  
          pLinkTable->pTail = pNode;  
          pLinkTable->SumOfNode++;   
     }  
  
     return 0;  
}

/* 
 * Delete a LinkTableNode from LinkTable 
 */ 
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
    if(pLinkTable == NULL)
    {
        return FAILURE;
    }
    while(pLinkTable->pHead != NULL)
    {
        tLinkTableNode * p = pLinkTable->pHead;
        pLinkTable->pHead = pLinkTable->pHead->pNext;
        pLinkTable->SumOfNode -= 1 ;
        free(p);
    }
    pLinkTable->pHead = NULL;
    pLinkTable->pTail = NULL;
    pLinkTable->SumOfNode = 0;
    free(pLinkTable);
    return SUCCESS;
}

/* 
 * Get LinkTableHead 
 */  
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable)
{
     if (pLinkTable == NULL)   
     {  
          printf("The table is empty!\n");  
          exit(0);   
     }  
  
     return pLinkTable->pHead; 
}

/* 
 * Get next LinkTableNode 
 */
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode)
{
     if (pLinkTable == NULL)   
     {  
          printf("The table is empty!\n");  
          exit(0);   
     }  
      
     if (pNode == NULL)   
     {  
          printf("The node is empty and cannot get next node!\n");  
          exit(0);  
     } 
     return pNode->pNext;  
}
