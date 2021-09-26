#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data  ;
    struct node *next;
}node;

typedef struct linklist
{
    int number;
    struct node *head;
}linklist;

void show(node* head);

void overturn (node *head);

int main(int argc, char const *argv[])
{
    node *head=calloc(1,sizeof(struct node));//不带头的指针
    head->next=NULL;
    int n;
    printf("请输入若干整数的个数：");
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
        {
            node *new =calloc(1,sizeof(struct node));
            new->data=i;
            new->next=NULL;
            /*****尾插*****/
            //找到尾节点
            node *tail=NULL;
            for(tail=head;tail->next !=NULL;tail=tail->next);
            tail->next=new;
        }
    show(head); 
    printf("\n");
    overturn (head);
    show(head);
    return 0;
}

void show(node *head)
{
    for(node* p=head->next;p!=NULL;p=p->next)
        printf("%d",p->data);
}

//逆转单链表
void overturn (node *head)
{
    node *p=head->next;
    head->next=NULL;
    while (p!=NULL)
    {
        node *k=p->next;
        p->next=head->next;
        head->next=p;
        p=k;
    }
}