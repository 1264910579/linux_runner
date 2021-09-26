#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "kernel_list.h"

// 大结构体
typedef struct node
{
    int data;

    // 小结构体
    struct list_head list; // 镶嵌标准链表节点
}node;

// 初始化一个带头结点的空链表
node *initList()
{
    node *head = calloc(1, sizeof(struct node));
    if(head != NULL)
        INIT_LIST_HEAD(&head->list);

    return head;
}

node *newNode(int data)
{
    node *new = calloc(1, sizeof(struct node));
    if(new != NULL)
    {
        new->data = data;
        INIT_LIST_HEAD(&new->list);
    }

    return new;
}

int main(int argc, char const *argv[])
{
    // 搞一个空链表
    node *head = initList();

    // 插入某些数据
    for(int i=0; i<5; i++)
    {
        node *new = newNode(i);

        // 将新节点new，放入链表的末尾
        list_add_tail(&new->list, &head->list);
    }

    // 遍历展示整条链表
    struct list_head *pos;
    list_for_each(pos, &head->list)
        printf("%d\t", list_entry(pos, node, list)->data);

    printf("\n");

    return 0;
}
