#ifndef __SEQLIST_H
#define __SEQLIST_H

#include <stdbool.h>

/*
****************************************
*
*  假定：
*  本顺序表专用于组织整数数据，并且他们具有
*  升序排列的内在逻辑
*
****************************************
*/

struct seqList
{
    int capacity; // 总容量
    int last;     // 末尾元素位置
    int *data;    // 指向真正的顺序表所在位置
};

// 初始化一个初始容量为 cap 的顺序表
struct seqList * initSeqList(int cap);

// 插入元素，并保证表内元素严格升序
bool insertNode(struct seqList *sl, int data);

// 删除元素，并保证表内元素严格升序
bool removeNode(struct seqList *sl, int data);

// 销毁顺序表
void destroySeqList(struct seqList *sl);

// 查看顺序表的各个节点内容
void show(struct seqList *sl);


#endif