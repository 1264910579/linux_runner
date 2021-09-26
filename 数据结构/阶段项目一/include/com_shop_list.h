#ifndef __COM_SHOP_LIST_H
#define __COM_SHOP_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <errno.h>
#include <pthread.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h> 
#include <strings.h>
#define RE "\033[1;31;40m"   // 红色
#define G "\033[1;32;40m"   // 绿色
#define Y "\033[1;33;40m"   // 黄色
#define B "\033[1;36;40m"   //浅蓝色
#define N "\033[0m"         // 清除格式
#define PRI_STYLE(type,str) printf("\e[%dm%s\e[m",(type),(str))
#define Back_COLOR 41+rand()%7//背景颜色切换
#define FRONT_COLOR 31+rand()%7//字体颜色切换
//历史信息数据结构体
typedef struct history_info
{
    char display_history_info[100];
    char shop_name[40];/*商品名称*/
    float price;/*单价*/
    int count;/*数量*/
    float total;/*总金额*/
}history_info;

//商品信息数据结构体
typedef struct commodity_info
{
    char shop_name[40];
    float price;
    int stock;
}commodity_info;

//购物车信息数据结构体
typedef struct shop_info
{
    char shop_name[40];
    int number;
    float sum_price;
}shop_info;

//历史链表节点
typedef struct node_history
{
    history_info data_history;
    struct list_head list_history;
}node_history;//链表节点类型

//商品链表节点
typedef struct node_commodity
{
    commodity_info data_commodity;
    struct list_head list_commodity;
}node_commodity;//链表节点类型

//购物车链表节点
typedef struct node_shop
{
    shop_info data_shop;
    struct list_head list_shop;
}node_shop;//链表节点类型
//新建商品信息节点的函数
node_commodity *new_commodity();
//新建一个历史链表结点的函数
node_history *new_history_node();
//把commodity.txt里面的内容全部放到商品链表当中
void init_commodity(node_commodity *head , char *flic_name);
//把商品链表显示出来
void display_commodity_list(node_commodity *head);
//把购物节点加到购物车链表中
void init_shop_head(node_shop *head_shop,node_commodity *head_commodity);
//查看商品是否存在
node_commodity * find_commodity(node_commodity *head,char *shop_name);
//新建购物车信息节点的函数(并判断商品里是否有该商品)
node_shop *new_shop(node_commodity *head_commodity);
//创建一个购物车头结点
node_shop *new_shop_head();
//确认购买时,销毁购物车链表(链表头不销毁,同时商品链表的库存)
void destroy_link_list(node_commodity *head_commodity,node_shop * head_shop,node_history *head_history);
//把购物车链表显示出来
bool display_shop_list(node_shop *head);
//更改commodity.txt数据
void write_commodity_txt(node_commodity *head_commodity,char *flic_name);
//修改购物车信息
void change_shop_list(node_commodity *head_commodity,node_shop * head_shop);
//管理员录入商品,先更新链表，再写进txt
void write_txt(node_commodity *head_commodity,char *flic_name);
//管理员搜索已有商品,并且更改信息
void change_commodity(node_commodity *head_commodity,char *flic_name);
//head_history把链表的内容写到txt
void write_history(node_history *head_history,char *flis_name);
//把head_history文件数据全部给history链表,并把所有的内容显示出来
void display_history_list(node_history *head,char *flis_name);
//修改密码
void ch_passwd(void);
//密码登录
void passward(void);
//用户模式
void user(node_commodity *head_commodity,node_shop * head_shop,node_history *head_history,char *flic_name,char *flis_name);
//管理员模式
void admin(node_commodity *head_commodity,node_history *head_history,char *flic_name,char *flis_name);
int my_getch(void);

//界面
void show_system();
void show_user(void);
void show_admin(void);
#endif