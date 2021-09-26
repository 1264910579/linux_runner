
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node{
    int data;
    struct list_node *next;
}node_t;//链表节点类型


node_t *request_queue_node(void)
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
static inline void enqueue(node_t *list_head, node_t *insert_node)
{
    node_t *pos;

    for(pos=list_head; pos->next != NULL; pos=pos->next);//找最后一个元素

    pos->next = insert_node;
}


void show_queue(node_t *list_head)
{
    node_t *pos;

    printf("队列已有数据:");

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
        在队列中获取一个
    参数:
        refer_node:链表当中的任意一个节点
*/
node_t *dequece(node_t *list_head)
{
    if(is_empty(list_head))
        return NULL;

    node_t *dequece_node;

    dequece_node = list_head->next;

    list_head->next = dequece_node->next;//将节点移出队列

    return dequece_node;
}

//销毁队列
void destroy_queue(node_t *list_head)
{
    node_t *pos, *next;

    pos = list_head;
   
    do{
        next = pos->next;
        free(pos);
        pos=next;
    }while(pos!=NULL);

}


int main(void)
{

    int input_value;
    node_t *list_head, *new_node, *get_node;

    //新建头节点
    list_head = request_queue_node();
    if(list_head == NULL)
        return -1;
    
    list_head->data = -1;

    while(1)
    {
        scanf("%d", &input_value);

        if(input_value > 0)
        {

            //新建节点
            new_node = request_queue_node();

            new_node->data = input_value;

            //将节点插入队伍
            enqueue(list_head, new_node);

        }
        else if(input_value < 0)
        {
            //删除头节点之后的节点数据
            get_node = dequece(list_head);
            if(get_node != NULL)
            {
                printf("出队节点为%d\n", get_node->data);
                free(get_node);
            }
            else
            {
                printf("队列已空\n");
            }
        }
        else
            break;

        //打印表格当中的数据
        show_queue(list_head);
    }

    //销毁队列
    destroy_queue(list_head);

    return 0;
}