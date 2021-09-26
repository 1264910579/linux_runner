#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include "list.h"
#include "com_shop_list.h"
char sys_ID[11]="1264910579";
char sys_passward[10] = "123456";
int main(int argc, char const *argv[])
{
	// system("clear");
	char key;
	char *flic_name="commodity.txt";
	char *flis_name="shopping_history.txt";
	node_commodity *head_commodity=new_commodity();
	node_shop *head_shop=new_shop_head();
	node_history *head_history=new_history_node();
	init_commodity(head_commodity , flic_name);//先初始化商品链表链表
	while (1)
	{
		// system("clear");
		show_system();//界面显示函数
			//按键选择
		{
			STAR:
			scanf("%c",&key);
			while (getchar()!='\n');
			system("clear");
			switch(key)
			{
				case '1'://普通用户模式
				{
					user(head_commodity,head_shop,head_history,flic_name,flis_name);
					break;
				}
				case '2'://管理员模式
				{
					//密码登录
					passward();
					admin(head_commodity,head_history,flic_name,flis_name);
					break;
				}
				case '0':exit(1);break;//退出程序
				default:printf(RE"您输入命令有误，请重新输入\n"N);goto STAR;break;		
			}
		}
	}	
	return 0;
}
