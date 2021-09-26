#include "click.h"
#include <pthread.h>

enum {red, green, blue};
int color;

void *redColor(void *arg)
{
    while(1)
    {
        wait4click(0, 000, 50, 160);
        color = red;
    }
}

void *greenColor(void *arg)
{
    while(1)
    {
        wait4click(0, 160, 50, 160);
        color = green;
    }
}

void *blueColor(void *arg)
{
    while(1)
    {
        wait4click(0, 320, 50, 160);
        color = blue;
    }
}


int main(int argc, char const *argv[])
{
    // 3条线程们：判定选取哪种颜色
    pthread_t t;
    pthread_create(&t, NULL, redColor, NULL);
    pthread_create(&t, NULL, greenColor, NULL);
    pthread_create(&t, NULL, blueColor, NULL);

    // 主线程：划线
    color = red;
    while(1)
    {
        switch(color)
        {
        case red:
            printf("\r正在使用红色");
            break;
        case green:
            printf("\r正在使用绿色");
            break;
        case blue:
            printf("\r正在使用蓝色");
            break;
        }
    }


    return 0;
}
