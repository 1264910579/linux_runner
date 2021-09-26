/*
 * @Author: your name
 * @Date: 2021-09-02 17:20:51
 * @LastEditTime: 2021-09-02 17:31:59
 * @LastEditors: Please set LastEditors
 * @Description: In User Settings Edit
 * @FilePath: \Desktop\dc_func.c
 */
#include <stdio.h>

/*
    1,递归实现的功能
*/
void my_print(int numb)
{
    if(numb < 0)
        return;

    printf("numb=%d\n", numb);

    my_print(numb-1);

    
 
}


int main(void)
{
  

    my_print(10);


    return 0;
}