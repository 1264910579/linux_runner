#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dlinklist.h"

// 初始化一个带头结点的空链表
node * initList()
{
    node *head = calloc(1, sizeof(node));
    if(head != NULL)
    {
        head->prev = head;
        head->next = head;
    }
    return head;
}

// 头插法：
void listAdd(node *head, node *new)
{
    new->prev = head;
    new->next = head->next;

    head->next = new;
    new->next->prev = new;
}

// 尾插法：
void listAddTail(node *head, node *new)
{
    new->prev = head->prev;
    new->next = head;

    head->prev->next = new;
    head->prev = new;
}

node * newNode(int data)
{
    node *new = calloc(1, sizeof(node));
    if(new != NULL)
    {
        new->data = data;
        new->prev = new;
        new->next = new;
    }
    return new;
}

void listForEach(node *head, void (*p)(int data))
{
    for(node *tmp=head->next; tmp!=head; tmp=tmp->next)
    {
        p(tmp->data);
    }
}


// 剔除指定的节点
void listRemove(node *p)
{
    if(p == NULL)
        return;
    
    p->prev->next = p->next;
    p->next->prev = p->prev;

    p->prev = p;
    p->next = p;
}

// 查找指定数据的节点
node *findNode(node *head, int data)
{
    node *p;
    for(p=head->next; p!=head; p=p->next)
    {
        if(p->data == data)
            return p;
    }

    return NULL;
}

// 销毁链表，彻底释放所有的内存
node *destroy(node *head)
{
    destroyInit(head);
    free(head);
    return NULL;
}

// 销毁链表，使得 head 回归初始状态
void destroyInit(node *head)
{
    node *p = head->next;

    while(p != head)
    {
        listRemove(p);
        free(p);
        p = head->next;
    }
}