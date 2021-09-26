#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "list.h"
typedef struct node_data
{
    int data;
    struct list_head list;
}node;

//新建节点函数
node *add_node(int data)
{
    node *new=calloc(1,sizeof(node));
    if(new !=NULL)
    {
        new->data=data;
        INIT_LIST_HEAD(&new->list);
    }
    return new;
}
void display_node(node *head);
//冒泡排序
void bubble_node(node *head)
{
    node *pos,*n;
    int i,j;
    int sum=0;//元素个数
    list_for_each_entry_safe(pos, n, &head->list, list)
    {
        sum++;
    }
    for(i = 1;i < sum+1;i++) //趟数循环 
        {
            for (j=0,pos = list_entry((&head->list)->next, typeof(*pos), list),n = list_entry(pos->list.next, typeof(*pos), list);
            &pos->list != (&head->list)&&j<sum-i+1;
            pos = n, n = list_entry(n->list.next, typeof(*n), list),j++)
            {   
                struct  list_head *pos_=&pos->list;
                struct  list_head *n_=&n->list;
                
                //从小到大
                if(pos->data>n->data)
                {
                    pos->list.next=n->list.next;
                    n->list.next->prev=pos_;

                    pos->list.prev->next=n_;
                    n->list.prev=pos->list.prev;

                    pos->list.prev=n_;
                    n->list.next=pos_;
                } 
            }
        }
        display_node(head);
}

//遍历
void display_node(node *head)
{
    node *pos;
    list_for_each_entry(pos,&head->list,list)
    {
        printf("%d\t",pos->data);
    }
}


int main(int argc, char const *argv[])
{
    printf("欢迎进入内核冒泡排序系统:\n");
    printf("输入正数或负数:录入数据并显示\n");
    printf("输入0:排序并显示:\n"); 

    int data;
    //新增头节点
    node *head=add_node(0);
    while (1)
    {
        scanf("%d",&data);
        if (data!=0)
        {
            //新增节点数据，并头插在内核链表
            node *new=add_node(data);
            list_add(&new->list,&head->list);
            //遍历
            display_node(head);

        }
        else
        {   
            //排序
            bubble_node(head);   
            //遍历
            // display_node(head);
        }
    }
    return 0;
}
