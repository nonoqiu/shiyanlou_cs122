/************************************************/
/* FILE NAME 	: linktable.h			*/
/* MODULE NAME 	: linktalbe			*/
/* DESCRIPTION  : interface of Link Table	*/
/* AUTHOR      	: qzh				*/
/* DATE		: 2016/10/14			*/
/************************************************/

#ifndef _LINK_TABLE_H_
#define _LINK_TABLE_H_

#define SUCCESS 0
#define FAILURE (-1)

/*
 * LinkTable Node Type
 */
typedef struct LinkTableNode
{
	struct LinkTableNode * pNext;
}tLinkTableNode;

/*
 * LinkTable Type
 */
typedef struct LinkTable
{
	tLinkTableNode *pHead;
	tLinkTableNode *pTail;
	int	SumOfNode;
}tLinkTable;

/* 
 * Create a LinkTable 
 */
tLinkTable *CreateLinkTable();

/* 
 * Delete a LinkTalbe 
 */
int DeleteLinkTable(tLinkTable *pLinkTable);

/* 
 * Add a LinkTableNode to LinkTable 
 */
int AddLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

/* 
 * Delete a LinkTableNode from LinkTable 
 */ 
int DelLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

/* 
 * Get LinkTableHead 
 */  
tLinkTableNode *GetLinkTableHead(tLinkTable *pLinkTable);

/* 
 * Get next LinkTableNode 
 */
tLinkTableNode *GetNextLinkTableNode(tLinkTable *pLinkTable, tLinkTableNode *pNode);

#endif /*_LINK_TABLE_H_*/
