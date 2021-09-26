#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "linklist.h"

// 初始化一个空链表即创建一个带头大哥的函数，返回创建的
linklist * initLinkList()
{
    linklist *ll = calloc(1, sizeof(linklist));
    if(ll != NULL)
    {
        ll->number = 0;
        ll->head   = NULL;
    }
    return ll ;
}

// 产生一个新节点
node *newNode(int data)
{
    node *new = calloc(1, sizeof(node));
    if(new != NULL)
    {
        new->data = data;
        new->next = NULL;
    }
    return new;
}

// 头插法：在链表的头部，插入数据data
bool listAdd(linklist *ll, node *new)
{
    if(ll == NULL || new == NULL)
        return false;

    new->next = ll->head;
    ll->head  = new;

    ll->number++;
    return true;
}

bool isEmpty(linklist *ll)
{
    return ll->number == 0;
}

// 尾插法：在链表的尾部，插入数据data
bool listAddTail(linklist *ll, node *new)
{
    if(ll == NULL || new == NULL)
        return false;

    if(isEmpty(ll))
        ll->head = new;
    else
    {
        // 0, 找到尾结点
        node *tail;
        for (tail = ll->head; tail->next != NULL; tail = tail->next);

        // 1, 将新节点接入尾部
        tail->next = new;
    }

    // 2, 更新一下number
    ll->number++;
    return true;
}

// 在链表ll中，将指定数据的节点剔除出当前链表
node * listremoveNode(linklist *ll, int data)
{
    if(isEmpty(ll))
        return NULL;

    // 找到要删除的节点的前一个节点的指针
    // p 指向要剔除的节点
    // k 指向 p 的前一个节点
    node *k, *p;
    for(p=ll->head; p!=NULL && p->data!=data; p=p->next)
    {
        k = p;
    }

    // 查无此人
    if(p == NULL)
        return NULL;

    // 将指定节点剔除出去
    if(p == ll->head)
        ll->head = ll->head->next;
    else
        k->next = p->next;

    p->next = NULL;

    // 更新一下number
    ll->number--;
    return p;
}

// node * findNode(linklist *ll, int data);
void show(linklist *ll)
{
    if(isEmpty(ll))
        return;

    for(node *p=ll->head; p!=NULL; p=p->next)
        printf("%d\t", p->data);
    printf("\n");
}
// void destroy(linklist *ll);