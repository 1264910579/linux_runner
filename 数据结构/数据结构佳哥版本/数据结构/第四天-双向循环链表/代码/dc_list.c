/*
 * @Author: your name
 * @Date: 2021-08-31 10:53:58
 * @LastEditTime: 2021-08-31 14:20:04
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Desktop\data_struct\dc_list.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>


typedef struct link_node{
    int data;
    struct link_node *prev, *next;
}node_t;

//不安全的遍历
#define list_for_each(head, pos)    for(pos=head->next; pos!=head; pos=pos->next)
#define list_for_each_tail(head, pos)   for(pos=hread->prev; pos!=head; pos=pos->prev)
//安全的遍历
#define list_for_each_safe(head, pos, n)  for(pos=head->next, n=pos->next; pos!=head; pos=n, n=n->next)
#define list_for_each_safe_tail(head, pos, n)    for(pos=head->prev, n=pos->prev; pos!=head; pos=n, n=n->prev)

/*
    函数功能:
        新建节点
    参数:
        无
    返回值:
        成功返回申请的节点内存,失败返回NULL
*/
node_t *request_list_node(void)
{
    node_t *new_node;

    new_node = malloc(sizeof(node_t));//申请内存
    if(new_node == NULL)//判断内存是否申请失败
    {
        perror("申请节点失败");
        return NULL;
    }

    new_node->prev = new_node;//让新申请的节点的上一个位置指向自己
    new_node->next = new_node;//让新申请的节点的下一个位置指向自己

    return new_node;
}

/*
    函数功能:
        将insert_node这个节点插入到refer_node这个节点之后的位置
    参数:
        refer_node:是链表中的任意一个节点
        insert_node:需要插入的节点
    返回值:
        无
*/
void insert_node_list(node_t *refer_node, node_t *insert_node)
{
    insert_node->prev = refer_node;
    insert_node->next = refer_node->next;
    refer_node->next->prev = insert_node;
    refer_node->next = insert_node;
}

/*
    函数功能:
        将insert_node这个节点插入到refer_node这个节点之前的位置
    参数:
        refer_node:是链表中的任意一个节点
        insert_node:需要插入的节点
    返回值:
        无
*/
static inline void insert_node_to_list_tail(node_t *refer_node, node_t *insert_node)
{
    insert_node->prev = refer_node->prev;
    insert_node->next = refer_node;
    refer_node->prev->next = insert_node;
    refer_node->prev = insert_node;
}

void display_list_node(node_t *list_head)
{
    node_t *pos;

    printf("表格已有数据:");

    list_for_each(list_head, pos)
    {
        printf("%d ", pos->data);
    }

    printf("\n");
}

/*
    函数功能:
        将rm_node这个节点移除出所在的表格
    参数:
        rm_node:删除出表格的节点地址
    返回值:
        无
*/
static inline void remove_list_node(node_t *rm_node)
{
    rm_node->prev->next = rm_node->next;
    rm_node->next->prev = rm_node->prev;
}

/*
    函数功能:
        将rm_node这个节点移除出所在的表格,并且释放其节点内存
    参数:
        rm_node:删除出表格的节点地址
    返回值:
        无
*/
void destroy_list_node(node_t *rm_node)
{
    remove_list_node(rm_node);

    free(rm_node);
}

/*
    函数功能:
        判断head这个表格是否为空
    返回值:
        为空返回真,没有空的话返回假
*/
bool is_empty(node_t *head)
{
    return head->next == head;
}

/*
    函数功能:
        搜索指定节点
*/

/*
    函数功能:
        销毁整条链表
    参数:
        list_head:需要销毁的链表头节点
    返回值:
        无
*/
void destroy_link_list(node_t *list_head)
{
    
    node_t *pos;
    node_t *n;

    //安全的遍历方式,可以任意的pos节点
    //for(pos=list_head, n=pos->next; pos!=list_head; pos = n, n=n->next)
    list_for_each_safe(list_head, pos, n)
    {
        printf("free %d \n", pos->data);
        free(pos);
    }

    free(list_head);

}


int main(void)
{
    int input_value;
    node_t *list_head, *new_node;//申明两个链表节点的指针变量,其中list_head用来存放链表的头节点,new_node用来临时存放一下新申请的节点

    //新建链表头节点
    list_head = request_list_node();

    while(1)
    {
        scanf("%d", &input_value);

        if(input_value > 0)
        {
            //新建节点
            new_node = request_list_node();//新申请一个节点
            new_node->data = input_value;//将数据存放进去这个节点当中

            //将这个新的节点插入到list_head所对应的表格中
            insert_node_to_list_tail(list_head, new_node);
        }
        else if(input_value < 0)
        {
            //删除指定节点
            //搜索指定节点
            //将其销毁掉
        }
        else    
            break;

        //遍历表格
        display_list_node(list_head);
    }

    //销毁链表

    return 0;
}