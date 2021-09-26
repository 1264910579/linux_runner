#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "linklist.h"

// 假设存储的所有整数，都需要升序排列

int main(int argc, char const *argv[])
{
    // 初始化一个空的单向链表
    linklist *ll = initLinkList();

    // 从键盘获取整数，并放入顺序表中
    int n, m;
    while(1)
    {
        m = scanf("%d", &n);
        if(m != 1 || getchar() != '\n')
        {
            while(getchar() != '\n');
            printf("再来一遍\n");
            continue;
        }

        if(n == 0)
            break;

        // 插入数据
        if(n > 0)
        {
            // 生成新的节点new
            node *new = newNode(n);

            // 将新节点new，插入到链表的头部
            if(!listAdd(ll, new))
                printf("插入数据失败\n");
        }

        // 剔除指定数据的节点
        if(n < 0)
        {
            node *tmp = listremoveNode(ll, -n);

            if(tmp == NULL)
                printf("删除数据失败\n");
            else
                free(tmp);
        }

        show(ll);
    }

    // 销毁顺序表
    // destroy(ll);

    return 0;
}
