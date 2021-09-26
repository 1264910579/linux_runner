
#define DATATYPE double
#include "linklist.h"

void show2(double data)
{
    printf("%lf\t", data);
}

void f()
{
   // 初始化一个带头结点的空链表
    node *head = initList();

    double n;
    scanf("%lf", &n);
    for(double i=1; i<=n; i++)
    {
        node *new = calloc(1, sizeof(node));
        new->data = i;
        new->next = NULL;

        // 在链表head的尾部插入新节点new
        insertList(head, new);
    }
    // 展示链表
    listForEach(head, show2);
    printf("\n");

    // 逆转单链表
    revert(head);

    // 展示链表
    listForEach(head, show2);
    printf("\n");

}