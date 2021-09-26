
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct list_node{
    int data;
    struct list_node *next;
}node_t;//链表节点类型

/*
    函数功能:
        申请一个节点
    返回值:
        成功返回申请的节点
*/
node_t *request_list_node(void)
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
        将insert_node这个节点插入到list_head这个栈当中
    参数:
        list_head:栈列表头节点
        insert_node:需要插入的节点
    返回值:
        无
*/
static inline void in_stack(node_t *list_head, node_t *insert_node)
{
    insert_node->next = list_head->next;
    list_head->next = insert_node;
}


void show_list_data(node_t *list_head)
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
        从list_head这条栈中获取一个节点出来(并且移除栈表格)
    参数:
        list_head:栈链表头节点
    返回值:
        成功返回获取到的节点,失败返回NULL(链表已空)
*/
node_t *out_stack(node_t *list_head)
{
    if(is_empty(list_head))
        return NULL;

    node_t *get_stack_node;

    get_stack_node = list_head->next;

    list_head->next = get_stack_node->next;//将节点移出队列

    get_stack_node->next = NULL;//让这个节点初始化一下,没有下一个节点(因为队列中是将节点插入到最后,如果不是NULL,这循环会出现问题)

    return get_stack_node;
}

//由于出队逻辑与出栈逻辑一致,给出栈函数取个别名叫做出队
#define dequeue(list_head) out_stack(list_head)

//入队函数
static inline void enqueue(node_t *list_head, node_t *insert_node)
{
    node_t *pos;

    for(pos=list_head; pos->next != NULL; pos=pos->next);//队尾到文件末尾入队

    pos->next = insert_node;//直接将节点插入到表格最后(注意,这个插入的节点的next值应为NULL,不然逻辑会异常)
}
//销毁队列
void destroy_list(node_t *list_head)
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
    node_t *src1_list, *src2_list, *new_node;
    node_t *queue_list;
    node_t *get_src1_node, *get_src2_node;
    int i;
    int src1_data[] = {2, 5, 8, 13, 18};
    int src2_data[] = {1, 3, 4, 7, 9, 10, 19};

    src1_list = request_list_node();//第一条栈列表
    src2_list = request_list_node();//第二条栈列表
    queue_list = request_list_node();//第三条队列

    for(i=sizeof(src1_data)/sizeof(int)-1; i>=0; i--)//逆序的将数组1当中的每个元素放入栈中(实现后入先出的逻辑,这样表格出栈的时候便是按照后入先出的原则从小到大输出)
    {
        new_node = request_list_node();//申请节点内存,并且将其存放进去
        new_node->data = src1_data[i];//将数组的数据存放到新建的节点
        in_stack(src1_list, new_node);//将数据按照栈逻辑存放到第1条链表中
    }

    for(i=sizeof(src2_data)/sizeof(int)-1; i>=0; i--)//逆序的将数组2当中的每个元素放入栈中(实现后入先出的逻辑,这样表格出栈的时候便是按照后入先出的原则从小到大输出)
    {
        new_node = request_list_node();//申请节点内存,并且将其存放进去
        new_node->data = src2_data[i];//将数组的数据存放到新建的节点
        in_stack(src2_list, new_node);//将数据按照栈逻辑存放到第2条链表中
    }

    show_list_data(src1_list);//打印链表1内容

    show_list_data(src2_list);//打印链表1内容

    get_src1_node = out_stack(src1_list);//先从表格1移除并且获取到一个节点(栈逻辑获取的(也就是表格中最小的那个值))

    get_src2_node = out_stack(src2_list);//先从表格2移除并且获取到一个节点(栈逻辑获取的(也就是表格中最小的那个值))

    while(1)
    {
        
        if(get_src1_node->data < get_src2_node->data)//判断哪个节点比较小,谁小谁插入第三条链表
        {
            //从链表1获取到的节点较小
            enqueue(queue_list, get_src1_node);//将链表1获取到的节点插入到第三条链表(队列入队(先入先出原则))
            get_src1_node = out_stack(src1_list);//重新从链表1中获取节点给get_src1_node这个变量(原先那个已经插入队列了)
        }
        else//从俩表2获取到的节点较小
        {
            enqueue(queue_list, get_src2_node);//将链表2获取到的节点插入到第三条链表(队列入队(先入先出原则))
            get_src2_node = out_stack(src2_list);//重新从链表2中获取节点给get_src2_node这个变量(原先那个已经插入队列了)
        }

        show_list_data(queue_list);//打印第三条链表的数据

        sleep(3);

        //如果上面out_stack函数返回值是NULL,这代表对应的链表已经空了
        if(get_src1_node == NULL)//表格1已经空了
        {
            enqueue(queue_list, get_src2_node);//将先获取出来的表格2节点写入队列中

            while((get_src2_node = out_stack(src2_list))!= NULL)//再将表格2中剩余的节点全部写入链表3里面去(入队)
            {
                enqueue(queue_list, get_src2_node);//将获取的节点数据入队
            }
            break;//完成,退出合并
        }
        else if(get_src2_node == NULL)//表格2已经空了
        {
            enqueue(queue_list, get_src1_node);//将先获取出来的表格1节点写入队列中

            while((get_src1_node = out_stack(src1_list))!= NULL)//再将表格1中剩余的节点全部写入链表3里面去(入队)
            {
                enqueue(queue_list, get_src1_node);//将获取的节点数据入队
            }
            break;
        }

    }
    
    show_list_data(queue_list);



    return 0;
}