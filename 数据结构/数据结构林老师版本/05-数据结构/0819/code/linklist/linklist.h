#include <stdbool.h>

/*
***************************
*
*  假定：
*  本链表专用于组织整数数据
*
***************************
*/

// 节点
typedef struct node
{
    int data;
    struct node *next;
}node;


// 管理结构体
typedef struct linkklist
{
    int number;
    struct node *head;
}linklist;


// 各种链表的基本操作
linklist * initLinkList();

node *newNode(int data);
bool listAdd(linklist *ll, node *new);
bool listAddTail(linklist *ll, node *new);

node *listremoveNode(linklist *ll, int data);
void show(linklist *ll);

// node * findNode(linklist *ll, int data);
// void destroy(linklist *ll);