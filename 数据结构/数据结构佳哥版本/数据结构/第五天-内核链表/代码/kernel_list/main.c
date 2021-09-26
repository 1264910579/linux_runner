/*
 * @Author: your name
 * @Date: 2021-09-01 17:01:47
 * @LastEditTime: 2021-09-01 17:35:15
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Desktop\kernel_list\main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include "list.h"

typedef struct big{
    int data;
    struct list_head list;
}node_t;

typedef struct one{
    int data;
    struct list_head list;
}node_one_t;

typedef struct two{
    int data;
    struct list_head list;
}node_two_t;


node_t *request_list_node(void)
{
    node_t *new_node;

    new_node = malloc(sizeof(node_t));
    if(new_node == NULL)
    {
        perror("申请节点出错");
        return NULL;
    }

    INIT_LIST_HEAD(&new_node->list);

    return new_node;
}


/*
#define request_list_node(new_node)({\
\
    new_node = malloc(sizeof(typeof(new_node)));\
    if(new_node == NULL)\
    {\
        perror("申请节点出错");\
    }\
\
    INIT_LIST_HEAD(&(new_node->list));\
})
*/

void display_list_node(node_t *list_head)
{
    struct list_head *pos;//小个结构体的pos
    node_t *bpos;

    printf("表格已有数据：");

    list_for_each(pos, &list_head->list)//这就是跟之前一样的for循环，只是里面循环的是小个结构体的地址
    {
        bpos = list_entry(pos, node_t, list);//通过小个结构体获取大个结构体的地址

        printf("%d ", bpos->data);

    }

    printf("\n");

}


int main(void)
{
    int input_value;
    node_t *list_head, *new_node;//申明两个链表节点的指针变量,其中list_head用来存放链表的头节点,new_node用来临时存放一下新申请的节点
    node_t *find_node;

    //新建链表头节点
    list_head = request_list_node();

    while(1)
    {
        scanf("%d", &input_value);

        if(input_value > 0)
        {
            //新建一个节点
            new_node = request_list_node();
            new_node->data = input_value;
            //插入表格
            list_add(&new_node->list, &list_head->list);
        }
        else if(input_value < 0)
        {
            if(list_empty(&list_head->list))
                continue;

            find_node = list_entry(list_head->list.next, node_t, list);//通过小个结构体获取大个结构体的地址
            //移除出链表
            list_del(list_head->list.next);

            free(find_node);
        }
        else    
            break;

        //遍历表格
        display_list_node(list_head);
    }

    //销毁链表
    

    return 0;
}