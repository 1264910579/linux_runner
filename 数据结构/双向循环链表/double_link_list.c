#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


typedef struct double_link_list
{
    int data;
    struct double_link_list *prev;
    struct double_link_list *next;
}node;


    //新建一个带数据的双向链表节点
node *add_new_node(int data)
{
    node *new = calloc(1,sizeof(node));
    if(new!=NULL)
    {
        new->data=data;
        new->next=new;
        new->prev=new;
    }
    else
    perror("申请节点失败");
    return  new;
}

    //将数据按顺序插入到双向链表
void inser_node(node *head,node *new)
{
    node *p=NULL;
    for(p=head->next;p!=head;p=p->next)
    {
        if(p->data>new->data)
        break;
    }
    //在p的前面插入
    new->next=p;
    new->prev=p->prev;
    p->prev->next=new;
    p->prev=new;
}
    //在链表中找数据,返回该节点指针
node *find(node*head,int data)
{
    node *p=NULL;
    for(p=head->next;p!=head;p=p->next)
    {
        if(p->data==data)
        return p;
    }
    printf("不好意思，没有该数据\n");
    return NULL;
}
    //数据据删除出链表,返回该剔除出去的结点指针
node *remove_node(node *head,int data)
{
    node *p;
    p=find(head,-data);
    if(p==NULL)
    return NULL;
    p->prev->next=p->next;
    p->next->prev=p->prev;
}
    //遍历链表
void display(node *head)
{
    node *p;
    for(p=head->next;p!=head;p=p->next)
    {
        printf("%d\t",p->data);
    }
}
    //销毁链表
void destroy_list(node *head)
{
    node *k;
    node *p;
   for(p=head->next,k=p->next;p!=head;p=k,k=k->next)
   {
       printf("free%d\t",p->data);
       free(p);
       if(k==NULL)
        break;
   }
       printf("free_head %d",head->data);
       free(head);
}
int main(int argc, char const *argv[])
{
    node *head=add_new_node(0);
    int data;
    while (1)
    {
        scanf("%d",&data);
        if(data>0)//插入数据
        {
            //新建一个带数据的双向链表节点
            node *new=add_new_node(data);
            //数据插入双向链表
            inser_node(head,new);
            display(head);
        }
        if(data<0)//删除数据
        {
            //数据据删除出链表,返回该剔除出去的结点指针
            remove_node(head,data);
            display(head);
        }
        if(data==0)//销毁双向循环链表
        {
            destroy_list(head);
        }
    }

    return 0;
}
