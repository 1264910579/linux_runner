#include "click.h"

void wait4click(int x, int y, int width, int height)
{
	// 1，打开触摸屏
	int tp = open("/dev/input/event0", O_RDWR);	

	// 2，定义输入信息结构体 input_event
	struct input_event buf;

    int x1, y1; // 开始点击的坐标点
    int x2, y2; // 松开手时的坐标点
    while(1)
    {
        bool x1done = false;
        bool y1done = false;

        while(1)
        {
            bzero(&buf, sizeof(buf));
            read(tp, &buf, sizeof(buf));

            // 获取按压信息
            if(buf.type == EV_KEY && buf.code == BTN_TOUCH && buf.value == 0)
                break;

            // 获取坐标信息
            if(buf.type == EV_ABS)
            {
                if(buf.code == ABS_X && !x1done)
                {
                    x1 = buf.value;
                    x1done = true;
                }
                if(buf.code == ABS_Y && !y1done)
                {
                    y1 = buf.value;
                    y1done = true;
                }

                if(buf.code == ABS_X)
                    x2 = buf.value;
                if(buf.code == ABS_Y)
                    y2 = buf.value;
            }
        }

        if(x<=x1 && x1<=(x+width)  &&
           x<=x2 && x2<=(x+width)  &&
           y<=y1 && y1<=(y+height) &&
           y<=y2 && y2<=(y+height))
        {
            close(tp);
            break;
        }
    }
}
