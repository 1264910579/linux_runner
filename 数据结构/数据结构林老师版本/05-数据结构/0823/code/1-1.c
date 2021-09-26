#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>

#include "linklist.h"

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
