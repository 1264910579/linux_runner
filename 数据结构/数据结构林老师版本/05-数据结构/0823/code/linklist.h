#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

#ifndef DATATYPE
#define DATATYPE int
#endif

typedef DATATYPE datatype;

typedef struct node
{
    datatype data;
    struct node *next;
}node;

static void revert(node *head)
{
    node *p = head->next;
    head->next = NULL;

    node *k;
    while(p != NULL)
    {
        k = p->next;
        p->next = head->next;
        head->next = p;

        p = k;
    }
}

static node *initList()
{
    node *head = calloc(1, sizeof(node));
    if(head != NULL)
    {
        head->next = NULL;
    }
    return head;
}

static void insertList(node *head, node *new)
{
    // 找到尾结点
    node *tail;
    for(tail=head; tail->next!=NULL; tail=tail->next);

    // 插入新节点
    tail->next = new;
}

static void listForEach(node *head, void(*handler)(datatype data))
{
    for(node *p=head->next; p!=NULL; p=p->next)
        handler(p->data);
}