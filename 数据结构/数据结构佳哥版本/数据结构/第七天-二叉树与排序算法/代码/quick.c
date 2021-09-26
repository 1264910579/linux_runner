/*
 * @Author: your name
 * @Date: 2021-09-03 15:21:41
 * @LastEditTime: 2021-09-03 15:34:54
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Desktop\quick.c
 */
/**********************************************
 *  File Name: quick.c
 *  Created  @ 2016-08-03 21:20
 *  Author   : Gec
 *  E-mail   : 2034294993@qq.com
 **********************************************/
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


#define SIZE    100000

void quick(int arr[],  int left, int right)
{
	int i;
	
	if(left < right)
	{
			int tmp = arr[left];
        	int low = left;
        	int high = right;
			
        	while(low < high)//循环在左下标小于右下标的基础上
    		{
                while(low < high && arr[high] >= tmp)//从右到左比较，实时判断左下标有没有小于右下标的值，并且右值有没有小于中间的交换值
				{
                	high--;
                }

            	arr[low] = arr[high];//把右值放到腾出来的空间中

                while(low < high && arr[low] < tmp)//从左到右比较，实时判断左下标有没有大于或者等于右下标的值，并且右值有没有小于中间的交换值
				{
                	low++;
                }

                arr[high] = arr[low];

			}

        arr[low] = tmp;
		
		quick(arr,left,low-1);
		quick(arr,low+1,right);
		
    }
}

int main(int argc, char **argv)
{
	
	int *array = malloc(SIZE*sizeof(int));
    int i;

    srand(time(NULL));

    for(i=0; i<SIZE; i++)
    {
        array[i] = rand()%SIZE;
    }
	
	quick(array, 0, SIZE-1);// 0--8 是下标
	

	for(i=0; i<SIZE; i++)
    {
        printf("%d ", array[i]);
    }

    printf("\n");


	return 0;
}

