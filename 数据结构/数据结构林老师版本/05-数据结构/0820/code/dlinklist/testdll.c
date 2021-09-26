#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "dlinklist.h"

void show(int data)
{
    printf("%d\t", data);
}

static bool first = true;
void show2(int data)
{
    printf("%s%d", (first ? "" : " <--> "), data);
    first = false;
}

int main(int argc, char const *argv[])
{
    // 搞一个空链表
    node *head = initList();

    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        listAddTail(head, i); // 1 2 3 ... ... n
    }
    // 展示出来
    listForEach(head, show2);
    printf("\n");

    // 删除节点
    printf("输入想要删除的节点:\n");
    while(1)
    {
        scanf("%d", &n);
        if(n == 0)
            break;

        node *p = findNode(head, n, NULL);
        if(p == NULL)
        {
            printf("查无此人!\n");
            continue;
        }
        listRemove(p);
        free(p);

        // 展示出来
        first = true;
        listForEach(head, show2);
        printf("\n");
    }

    // 彻底销毁链表，head会变成NULL
    head = destroy(head);

    // // 销毁链表，head回归空链表头
    // destroyInit(head);



    return 0;
}
