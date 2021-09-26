/*
 * @Author: your name
 * @Date: 2021-09-03 14:09:13
 * @LastEditTime: 2021-09-03 15:35:44
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Desktop\bb.c
 */
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define SIZE    10000

void bubble_sort(int *arr, int len)//100
{
    int sort_count, pos;
    int tmp;

    //排序多少次:sort_count:计数已经排好了几个数据,len-1:最后一个不用排序
    for(sort_count=0; sort_count<len-1; sort_count++)
    {
        //pos:从哪个位置开始比较,len-sort_count-1:总的数据长度-已经排好的数据个数-1(这个-1是因为pos下面的操作中会访问到pos+1)
        for(pos=0; pos<len-sort_count-1; pos++)
        {
            if(arr[pos] > arr[pos+1])//前面的数据
            {
                //交换数据
                tmp = arr[pos];
                arr[pos] = arr[pos+1];
                arr[pos+1] = tmp;
            }
        }

    }

}

int main(void)
{
    int *array = malloc(SIZE*sizeof(int));
    int i;

    srand(time(NULL));

    for(i=0; i<SIZE; i++)
    {
        array[i] = rand()%SIZE;
    }

    bubble_sort(array, SIZE);


    for(i=0; i<SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");

    return 0;
}