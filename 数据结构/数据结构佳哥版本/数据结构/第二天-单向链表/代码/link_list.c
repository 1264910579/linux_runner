
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node{
    int data;
    struct list_node *next;
}node_t;//链表节点类型


node_t *request_link_list_node(void)
{
    node_t *new_node;

    new_node = malloc(sizeof(node_t));
    if(new_node == NULL)
    {
        perror("申请链表节点失败");
        return NULL;
    }

    new_node->next = NULL;

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
void insert_node_link_list(node_t *refer_node, node_t *insert_node)
{
    insert_node->next = refer_node->next;
    refer_node->next = insert_node;
}

void display_link_node_data(node_t *list_head)
{
    node_t *pos;

    printf("链表现有数据:");

    for(pos=list_head->next; pos!=NULL; pos = pos->next)
    {
        printf("%d ", pos->data);
    }

    printf("\n");
}

bool is_empty(node_t *head)
{
    return head->next == NULL;
}

/*
    函数功能:
        删除refer_node的下一个节点出链表
    参数:
        refer_node:链表当中的任意一个节点
*/
int remove_list_next_node(node_t *refer_node)
{
    if(is_empty(refer_node))
    {
        fprintf(stderr, "表格已经空了\n");
        return -1;
    }

    node_t *rm_node;

    rm_node = refer_node->next;

    refer_node->next = rm_node->next;

    free(rm_node);

    return 0;
}


int main(void)
{
    int input_value;
    node_t *list_head, *new_node;

    //新建头节点
    list_head = request_link_list_node();
    if(list_head == NULL)
        return -1;
        
    while(1)
    {
        scanf("%d", &input_value);

        if(input_value > 0)
        {

            //新建节点
            new_node = request_link_list_node();

            new_node->data = input_value;

            //将节点插入到表格当中
            insert_node_link_list(list_head, new_node);

            //打印表格当中的数据
            display_link_node_data(list_head);
        }
        else if(input_value < 0)
        {
            //删除头节点之后的节点数据
            remove_list_next_node(list_head);
            //打印表格当中的数据
            display_link_node_data(list_head);
        }
        else
            break;
    }

    //销毁表格

    return 0;
}