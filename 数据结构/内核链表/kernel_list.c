#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct big_node
{
    int data;
    struct list_head list;
}node;
    
    //新增节点
node *add_new_node(int data)
{
    node *
    new=calloc(1,sizeof(node));
    if(new!=NULL)
    {
        new->data=data;
        INIT_LIST_HEAD(&new->list);
        return new;
    }
    return new;
}



    //数据删除出内核链表

    //在内核链表搜索数据

    //遍历内核链表
void display(struct list_head *head) 
{   
    node *p=NULL;
    struct list_head *pos;
    list_for_each(pos, head)
    {
        p=list_entry(pos,node,list);
        printf("%d\t",p->data);
    }
}



int main(int argc, char const *argv[])
{

    //新增一个头节点
    node *head=add_new_node(0);
    int data;
    while (1)
    {
        scanf("%d",&data);

        if(data>0)
        {
            //数据插入进内核链表
            node *new=add_new_node(data);

            /*   方法1
            //按照数据顺序插入
            struct list_head *pos;
            struct list_head *n;
           
            if (list_empty(&head->list))
            {
                list_add(&new->list,&head->list);  
            }
            else
            {
                list_for_each_safe(pos, n,&head->list)
                {
                    node *p=list_entry(pos,node,list);
                    if (p->data<data)
                    {
                        __list_add(&new->list,p->list.prev,&p->list);    
                        break;
                    }
                }
            }
            */

            //方法2
            node *pos,*n;
            if (list_empty(&head->list))
            {
                list_add(&new->list,&head->list);  
            }
            else
            {
                list_for_each_entry_safe(pos, n, &head->list, list)
                {
                    if(pos->data<data)
                    {
                        __list_add(&new->list,pos->list.prev,&pos->list);    
                        break;
                    }
                }
            }
            /*   方法3
            list_add_tail(&new->list,&head->list);
            //遍历内核链表
            */



            display(&head->list);
        }

        if(data<0)
        {
            
            node *pos=NULL;
            //在内核链表搜索数据
            node *n=NULL;
            list_for_each_entry_safe(pos, n, &head->list, list)
            {
                //将数据删除出链表
                if(pos->data==-data)
                {
                    list_del(&pos->list);
                }
            }
           /*    方法2
            node *p=NULL;
            //在内核链表搜索数据
            struct list_head *pos;
            struct list_head *n;
            list_for_each_safe(pos, n, &head->list)
            {
                p=list_entry(pos,node,list);//通过小个结构体地址获取大个结构体地址的方式
                //将数据删除出链表
                if(p->data==-data)
                {
                    list_del_init(&p->list);
                }
            }
            */
            //遍历内核链表
            display(&head->list);
        }   

        if(data==0)
        {
            //销毁内核链表

            break;
        }

    }
    


    return 0;
}
