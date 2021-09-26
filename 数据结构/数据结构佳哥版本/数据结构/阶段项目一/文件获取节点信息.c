
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>

struct order_info{
    char name[20];
    char menu[20];
    float price;
};

typedef struct list_node{
    struct order_info data;
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

    for(pos=list_head; pos->next != NULL; pos=pos->next);

    pos->next = insert_node;
}


void show_queue(node_t *list_head)
{
    node_t *pos;

    printf("队列已有数据:\n");

    for(pos=list_head->next; pos!=NULL; pos = pos->next)
    {
        printf("姓名:%s\t类型:%s\t价格:%.2f\n", pos->data.name, pos->data.menu, pos->data.price);
    }
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

/*
    函数功能:
        读取文件内容,加载进队列当中
*/
int init_queue_list(const char *file_name, node_t *list_head)
{
    char *buffer, *pos;
    FILE *order_fp;
    node_t *new_node;
    void *ret_point;//通配型指针类型

    order_fp = fopen(file_name, "r");
    if(order_fp == NULL)
    {
        perror("打开订单文件失败");
        goto open_order_file_err;
    }

    buffer = malloc(1024);
    if(buffer == NULL)
    {
        perror("申请内存出错");
        goto request_mem_error;
    }

    while(1)
    {
        
        ret_point = fgets(buffer, 1024, order_fp);//获取一行数据
        if(ret_point == NULL)
            break;
        //buffer有一行数据

        new_node = request_queue_node();
        
        pos = strstr(buffer, "姓名：");//搜索到指定字符串,并且返回该字符串的地址

        sscanf(pos+strlen("姓名："), "%s", new_node->data.name);

        pos = strstr(buffer, "类型：");//搜索到指定字符串,并且返回该字符串的地址
        sscanf(pos+strlen("类型："), "%s", new_node->data.menu);

        pos = strstr(buffer, "价格：");//搜索到指定字符串,并且返回该字符串的地址
        sscanf(pos+strlen("价格："), "%f", &(new_node->data.price));
        enqueue(list_head, new_node);
    }

    free(buffer);

    return fclose(order_fp);

request_mem_error:
    fclose(order_fp);
open_order_file_err:
    return -1;

}


int main(void)
{

    node_t *list_head, *get_node;

    //新建头节点
    list_head = request_queue_node();
    if(list_head == NULL)
        return -1;

   

    init_queue_list("order.txt", list_head);

    while(1)
    {
        sleep(2);

        get_node = dequece(list_head);
        if(get_node == NULL)
            break;

        printf("姓名:%s\t类型:%s\t价格:%.2f\n", get_node->data.name, get_node->data.menu, get_node->data.price);

        free(get_node);
    }

    //销毁队列
    destroy_queue(list_head);

    return 0;
}