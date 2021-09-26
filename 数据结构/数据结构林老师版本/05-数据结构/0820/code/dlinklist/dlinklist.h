#ifndef __DLINKLIST_H
#define __DLINKLIST_H

#ifndef DATATYPE
#define DATATYPE int // 链表默认装载的数据类似
#endif

typedef DATATYPE datatype;

// 节点
typedef struct node
{
    datatype data;

    struct node *prev;
    struct node *next;
}node;


// 本文件所有函数接口的声明：
//
//
//



// 初始化一个带头结点的空链表
static node * initList()
{
    node *head = calloc(1, sizeof(node));
    if(head != NULL)
    {
        head->prev = head;
        head->next = head;
    }
    return head;
}


// 头插法：
static void listAdd(node *head, datatype data)
{
    node *new = __newNode(data);

    new->prev = head;
    new->next = head->next;

    head->next = new;
    new->next->prev = new;
}


// 尾插法：
static void listAddTail(node *head, datatype data)
{
    node *new = __newNode(data);

    new->prev = head->prev;
    new->next = head;

    head->prev->next = new;
    head->prev = new;
}

// 内部接口
static node * __newNode(datatype data)
{
    node *new = calloc(1, sizeof(node));
    if(new != NULL)
    {
        new->data = data;
        new->prev = new;
        new->next = new;
    }
    return new;
}

static void listForEach(node *head, void (*p)(datatype data))
{
    for(node *tmp=head->next; tmp!=head; tmp=tmp->next)
    {
        p(tmp->data);
    }
}


// 剔除指定的节点
static void listRemove(node *p)
{
    if(p == NULL)
        return;
    
    p->prev->next = p->next;
    p->next->prev = p->prev;

    p->prev = p;
    p->next = p;
}

// 查找指定数据的节点
static node *findNode(node *head, datatype data, bool (*cmp)(datatype d1, datatype d2) /*比较器*/)
{
    node *p;
    for(p=head->next; p!=head; p=p->next)
    {
        if(cmp == NULL)
        {
            if(p->data == data)
                return p;
        }
        else
        {
            if(cmp(p->data, data))
                return p;
        }
    }

    return NULL;
}


// 销毁链表，使得 head 回归初始状态
static void destroyInit(node *head)
{
    node *p = head->next;

    while(p != head)
    {
        listRemove(p);
        free(p);
        p = head->next;
    }
}


// 销毁链表，彻底释放所有的内存
static node *destroy(node *head)
{
    destroyInit(head);
    free(head);
    return NULL;
}


#endif