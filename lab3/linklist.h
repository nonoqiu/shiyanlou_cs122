/*
*
*name:	linklist.h
*desc:	shuju jiegou shengming
*user:	qiuzaihui
*time:	20160930
*
*/

struct DataNode
{
    char* cmd;
    char* desc;
    int (*handler)();
    struct DataNode *next;
}tDataNode;

/* find a cmd in the linklist and return the datanode pointer */
tDataNode* FindCmd(tDataNode* head, char* cmd);

/* show all cmd in linklist */
int ShowAllCmd(tDataNode* head);
