#ifndef __DLINKLIST_H
#define __DLINKLIST_H

// 节点
typedef struct node
{
    int data;

    struct node *prev;
    struct node *next;
}node;

// 操作接口
// 初始化一个带头结点的空链表
node * initList();
// 头插法：
void listAdd(node *head, node *new);
// 尾插法：
void listAddTail(node *head, node *new);

// 新节点
node * newNode(int data);
void listForEach(node *head, void(*handle)(int data));

void listRemove(node *p);
// 查找指定数据的节点
node *findNode(node *head, int data);


// 销毁链表，彻底释放所有的内存
node *destroy(node *head);
// 销毁链表，使得 head 回归初始状态
void destroyInit(node *head);

#endif