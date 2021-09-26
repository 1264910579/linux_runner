/*
 * @Author: your name
 * @Date: 2021-09-01 17:01:47
 * @LastEditTime: 2021-09-04 09:39:13
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


/*
    node_t *pos;

    list_for_each_entry(pos, &list_head->list, list)
    {
         printf("%d ", pos->data);
    }
*/

}

void destroy_list(node_t *list_head)
{
    struct list_head *pos, *n;
    node_t *bpos;

    list_for_each_safe(pos, n, &list_head->list)
    {
        bpos = list_entry(pos, node_t, list);
        printf("free %d\n", bpos->data);
        free(bpos);
    }

/*
    node_t *pos, *n;

    list_for_each_entry_safe(pos, n, &list_head->list, list)
    {
        printf("free %d\n", pos->data);
        free(pos);
    }
*/
}

//冒泡排序链表
void bubble_sort(node_t *list_head)
{
    struct list_head *cmp_pos, *finish_pos;
    node_t *bpos, *bposn;
    int tmp;

    //此层for是用来计算需要排序的数据个数-1个(-1个的原因是因为最后一个不用比较)
    for(finish_pos=list_head->list.prev; finish_pos != &list_head->list; finish_pos=finish_pos->prev)
    {
        //此层for循环是从第一个节点开始与后面的相邻节点比较,把大的数据换到后面去
        //cmp_pos != finish_pos:finish_pos是每次冒泡完一个数据后,位置刚好往前挪动一个单位,我们利用这一特性来实现每次比较的结束位置-1
        for(cmp_pos=list_head->list.next; cmp_pos != finish_pos; cmp_pos=cmp_pos->next)
        {
            //获取大个结构体
            bpos = list_entry(cmp_pos, node_t, list);
            bposn = list_entry(cmp_pos->next, node_t, list);

            if(bpos->data > bposn->data)//如果发现pos的数据比pos->next数据大,则交换数据
            {
                tmp = bpos->data;
                bpos->data = bposn->data;
                bposn->data = tmp;
            }
        }
    }

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
            list_add_tail(&new_node->list, &list_head->list);
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
            bubble_sort(list_head);

        //遍历表格
        display_list_node(list_head);
    }

    //销毁链表
    

    return 0;
}