#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
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
void show(int data)
{
    printf("%d\t", data);
}

void f();

int main(int argc, char const *argv[])
{
    // 初始化一个带头结点的空链表
    node *head = initList();

    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        node *new = calloc(1, sizeof(node));
        new->data = i;
        new->next = NULL;
        // 在链表head的尾部插入新节点new
        insertList(head, new);
    }
    // 展示链表
    listForEach(head, show);
    printf("\n");

    // 逆转单链表
    revert(head);

    // 展示链表
    listForEach(head, show);
    printf("\n");


    // 利用通用单链表搞一个存储double数据的链表
    f();

    return 0;
}
