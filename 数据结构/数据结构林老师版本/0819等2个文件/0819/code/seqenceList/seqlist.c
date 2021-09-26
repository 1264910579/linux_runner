#include <stdio.h>
#include <stdlib.h>
#include "seqlist.h"

// 初始化
struct seqList * initSeqList(int cap)
{
    struct seqList *sl = calloc(1, sizeof(struct seqList));

    if(sl != NULL)
    {
        sl->capacity = cap;
        sl->last     = -1;
        sl->data = calloc(cap, sizeof(int));

        if(sl->data == NULL)
        {
            free(sl);
            return NULL;
        }
    }
    return sl;
}

bool isFull(struct seqList *sl)
{
    return sl->last == sl->capacity-1;
}

// 插入元素到合适的位置，使之满足升序的逻辑
bool insertNode(struct seqList *sl, int data)
{
    // 判定是否有位置
    if(isFull(sl))
    {
        // 扩大容量
        sl->data = realloc(sl->data, sl->capacity+10*sizeof(int));
        if(sl->data == NULL)
            return false;
        
        sl->capacity += 10;
    }

    // 找到data应该放置的位置
    int pos;
    for(pos = 0; pos<=sl->last; pos++)
    {
        if(sl->data[pos] >= data)
            break;
    }

    // 批量地将数据往后移
    for(int k=sl->last; k>=pos; k--)
        sl->data[k+1] = sl->data[k];

    // 妥善地放入新的元素
    sl->data[pos] = data;

    sl->last++;
    return true;
}

bool isEmpty(struct seqList *sl)
{
    return sl->last == -1;
}

// 查找指定的节点
int findNode(struct seqList *sl, int data)
{
    if(isEmpty(sl))
        return -1;

    for(int i=0; i<=sl->last; i++)
    {
        if(data == sl->data[i])
            return i;
    }

    return -1;
}


// 删除元素
bool removeNode(struct seqList *sl, int data)
{
    // 判定顺序表是否为空
    if(isEmpty(sl))
        return false;

    // 判定是否有元素
    int pos = findNode(sl, data);
    printf("pos: %d\n", pos);
    if(pos == -1)
        return false;

    // 妥善删掉指定的元素：将后续的元素批量往前移
    for(int k=pos; k<sl->last; k++)
        sl->data[k] = sl->data[k+1];
    sl->last--;

    return true;
}

// 销毁顺序表
void destroySeqList(struct seqList *sl)
{
    if(sl == NULL)
        return;

    free(sl->data);
    free(sl);
}

void show(struct seqList *sl)
{
    if(isEmpty(sl))
        return;

    for(int i=0; i<=sl->last; i++)
        printf("%d\t", sl->data[i]);
    printf("\n");
}