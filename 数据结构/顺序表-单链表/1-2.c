#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data ;
    struct node *next;
}node;

typedef struct linklist
{
    int data ;
    struct node *next;
}linklist;

void show(node *head);

void kill3(node *head);




int main(int argc, char const *argv[])
{
    //定义一个单向循环链表
    node *head;
    head->next=head;
    int n;
    printf("请输入若干个数：");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        node *new=calloc(1,sizeof(struct node));
        new->data=i;
        new->next=NULL;
        /****尾插***/
        //找到尾节点
        node*tail=NULL;
        for(tail=head;tail->next!=head;tail=tail->next);
        tail->next=new;
        new->next=head;
    }
    show(head);
    printf("\n");
    kill3(head);
    show (head);
    return 0;
}
void show(node *head)
{
    for (node *p=head->next;p!=head;p=p->next)
    {
        printf("%d",p->data);
    }
}
void kill3(node *head)
{
    node *p=head->next;
    node *k=head->next;
    while (1)
    {
        k=p;
        k->next->next=k->next->next->next;
        p=k->next->next->next;
    if(p->next==head)
    break;
    }
    
}