#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "seqlist.h"

// 假设存储的所有整数，都需要升序排列

int main(int argc, char const *argv[])
{
    // 初始化一个空的顺序表
    struct seqList *sl = initSeqList(10);

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
            if(!insertNode(sl, n))
                printf("插入数据失败\n");
        }

        // 删除数据
        if(n < 0)
        {
            if(!removeNode(sl, -n))
                printf("删除数据失败\n");
        }

        show(sl);
    }

    // 销毁顺序表
    destroySeqList(sl);

    return 0;
}
