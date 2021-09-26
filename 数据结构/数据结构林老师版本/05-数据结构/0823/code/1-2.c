#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

// 初始化一个不带头结点的空链表
node *initList()
{
    return NULL;
}

// 在链表head的末尾，插入新节点new
// 返回更新之后的新链表的头指针
node *insertList(node *head, node *new)
{
    // 1，空链表
    if(head == NULL)
    {
        return new;
    }

    // 2，非空链表
    // 找到尾结点
    node *tail;
    for (tail = head; tail->next != head; tail = tail->next);

    // 插入新节点
    tail->next = new;
    new->next  = head;
    return head;
}

// 将节点p从链表中剔除出去
// 返回更新之后的新的链表的头指针：
// 1，如果删除之后链表变空，那么返回NULL
// 2，如果删除之后链表非空，那么返回p的原来的下一个节点指针
node *listRemove(node *p)
{
    if(p == NULL)
        return NULL;

    // 1，p是链表唯一的节点
    if(p->next == p)
        return NULL;

    // 2，p不是链表的唯一节点
    node *k;
    for(k=p->next; k->next!=p; k=k->next);

    k->next = p->next;
    p->next = p;

    return k->next;
}

node *kill3(node *head)
{
    if(head == NULL)
        return NULL;

    node *p;
    for(p=head->next->next; p!=p->next->next ;p=p->next->next)
    {
        p = listRemove(p);
    }
    return p;
}

void show(node *head)
{
    if(head == NULL)
        return;

    node *p;
    for(p=head; p->next!=head; p=p->next)
        printf("%d\t", p->data);
    printf("%d\n", p->data);
}


int main(int argc, char const *argv[])
{
    // 构建一个空的单循环链表
    node *head = initList();

    // 插入若干元素
    int n;
    scanf("%d", &n);
    for(int i=1; i<=n; i++)
    {
        node *new = calloc(1, sizeof(node));
        if(new != NULL)
        {
            new->data = i;
            new->next = new;
        }

        head = insertList(head, new);
    }
    show(head);

    // 数3出局
    head = kill3(head);

    // 输出幸运儿
    show(head);

    return 0;
}
