#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct link_list_node
{
    int data;
    struct link_list_node *next;
}node;

//新建一个节点的函数
node *new_node(int data)
{
    node *new =calloc(1,sizeof(node));
    if(new!=NULL)
    {
        new->data=data;
        new->next=NULL;
    }
    return new;
}

    //由大到小顺序插入
void insert_node(node *head,node *new)
{
    node *k;//定义一个跟屁虫
    node *p;
    for(k=head,p=head->next;p!=NULL;k=p,p=p->next)
    {
        if (p->data>new->data)
        {
            break;
        }
        
    }
    new->next=k->next;
    k->next=new;
}


    //寻找指定节点,返回该指定节点的上一节点的指针
node *find_node(node *head,int data)
{
    bool bigan=false;
    int i=0;
    node *k;//p的跟屁虫，为了返回p节点的上一个节点的指针
    node *p;
    for(p=head->next,k=head;p!=NULL;p=p->next,k=k->next)
    {
        
        if(p->data==data)
        {
            bigan=true;
            return k;
        }
    }
    if(!bigan)
    {
    printf("没有该数据\n");
    return NULL;
    }

}    
    //删除指点节点
node *remove_node(node *head,int data)
{
    node *p=find_node(head,-data);
    if (p==NULL)
    return NULL;
    else
    {
    node *k=p->next;
    p->next=p->next->next;
    free(k);
    k=NULL;
    }
}
    //遍历链表

    //显示链表
void  display_list(node *head)
{
    for(node *p=head->next;p!=NULL;p=p->next)
    {
        printf("%d\t",p->data);
    }
}
    //销毁链表
void des_list(node *head)
{
    node *p;
    node *k;
   for(p=head,k=p->next;p!=NULL;p=k,k=k->next)
   {
       printf("free %d",p->data);
       free(p);
       if(k==NULL)
        break;
   } 

}
int main(int argc, char const *argv[])
{
    //新建一个头节点
    node *head=new_node(0);
    while (1)
    {
        int data;
        scanf("%d",&data);
        if(data>0)
        {
            //插入节点
            node *new=new_node(data);
            insert_node(head,new);
            display_list(head);
        }
        if (data<0)
        {
            //删除指点节点
            remove_node(head,data);
            //显示链表
            display_list(head);
        }
        if(data==0)
            //销毁链表
        des_list(head);
    }
    return 0;
}
