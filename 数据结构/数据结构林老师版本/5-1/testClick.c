#include "click.h"

int main(void)
{
    while(1)
    {
        wait4click(0,0,100,50);
        printf("a\n");
    }
}
