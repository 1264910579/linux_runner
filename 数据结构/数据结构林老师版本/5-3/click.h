#ifndef __CLICK_H
#define __CLICK_H

#include <fcntl.h>
#include <stdio.h>
#include <errno.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>

#include <linux/fb.h>    // LCD
#include <linux/input.h> // 触摸屏

void wait4click(int x, int y, int width, int height);

#endif