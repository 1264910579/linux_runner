#include "list.h"
#include "com_shop_list.h"
void show_system(void)
{
	printf(B"-------------------------------------------------\n");
	printf("|               欢迎来到口袋商店系统              |\n");
	printf("|               基于Linux的通用消费平台系统架构优化              |\n");
	printf("-------------------------------------------------\n");
	printf("|        【1】普通用户      【2】管理员用户       |\n");
	printf("|        【0】退出程序                           |\n");
	printf("-------------------------------------------------\n"N);
	printf(Y"请选择："N);
}

void show_user(void)
{
	printf(B"----------------------------------------------------------\n");
	printf("|        【1】添加购买商品     【2】查看及购买购物车全部商品 |\n");
	printf("|        【3】修改购物车信息   【0】退出用户模式            |\n");
	printf("----------------------------------------------------------\n"N);
	printf(Y"请选择：\n"N);
}


void show_admin(void)
{
	printf(B"-------------------------------------------------\n");
	printf("|        【1】录入商品       【2】更改商品信息      |\n");
	printf("|        【3】查看购买历史   【4】密码修改          |\n");
    printf("|        【0】退出管理员模式                       |\n");
	printf("-------------------------------------------------\n"N);
	printf(Y"请选择："N);
}
int my_getch(void)
{
    char a;
    system("stty -icanon");        //关闭终端缓冲区
    system("stty -echo");        //关闭终端回显
    a = getchar();
    system("stty icanon");        //打开终端缓冲区
    system("stty echo");        //打开终端回显
    return a;
}
extern char sys_ID[11];
extern char sys_passward[10];
//密码登录
void passward(void)
{
	int i = 0;
	char user_passward[10];
	bzero(user_passward,sizeof(user_passward));
	int cont = 0;
	char my_ID[11];
	bzero(my_ID,sizeof(my_ID));
	printf(Y"请输入登录账号："N);
	while (1)
	{
		scanf("%s",my_ID);
		while (getchar()!='\n');
		if(strcmp(my_ID,sys_ID)!= 0)
		{
			printf(RE"该账号不是管理员账号,请重新输入:"N);
		}
		else
		break;
	}
	
	printf(Y"请输入登录密码："N);
STAR:	
	for(i=0;i<10;i++)
	{
		user_passward[i] =my_getch();
		//按回车和删除不显示*
		if(user_passward[i] != 10 && user_passward[i] != 127)
		{
			printf("*");
		}
		//按回车结束输入 添加结束字符
		if(user_passward[i] == 10)
		{
			//将回车替换为结束符
			user_passward[i] = '\0';
			break;
		}
		//按删除键
		if(user_passward[i] == 127)
		{
			//数组
			i-=2;       //回到要删除的字符的前一个字符位置
			if(i<=-1)   //防止用户一直按删除导致程序崩溃
			{
				i = -1;
			}
			//界面显示
			printf("\b");
			printf(" ");
			printf("\b");	
		}
	}
	//对比密码
	if(strcmp(user_passward,sys_passward)!= 0)
	{
		system("clear");
		cont++;
		if(cont == 5)
		{
			printf(RE"系统密码输入错误次数达到5次，请按任意键退出系统\n\a\a\a"N);
			my_getch();
			exit(1);
		}
		printf(RE"系统密码错误，请重新输入\n"N);
		goto STAR;
	}
	system("clear");
}				
//修改密码
void ch_passwd(void)
{
	int i,j;
	char ch_passward[2][10];
	/*输入原密码*/
	passward();
SA:	
	/*修改密码程序*/
	for(j=0;j<2;j++)
	{
		printf(Y"\n请输入第%d次密码\n"N,j+1);
		for(i=0;i<10;i++)
		{
			ch_passward[j][i] = my_getch();
			//按回车和删除不显示*
			if(ch_passward[j][i] != 10 && ch_passward[j][i] != 127)
			{
				printf("*");
			}
			
			//按回车结束输入 添加结束字符
			if(ch_passward[j][i] == 10)
			{
				//将回车替换为结束符
				ch_passward[j][i] = '\0';
				break;
			}

			//按删除键
			if(ch_passward[j][i] == 127)
			{
				//数组
				i-=2;       //回到要删除的字符的前一个字符位置
				if(i<=-1)   //防止用户一直按删除导致程序崩溃
				{
					i = -1;
				}
				//界面显示
				printf("\b");
				printf(" ");
				printf("\b");	
			}
		}
	}

	/*对比两次密码是否一致*/
	if(strcmp(ch_passward[0],ch_passward[1])!=0)
	{
		// system("clear");
		printf(RE"您输入的两次密码不一致，请重新输入\n"N);
		goto SA;
	}
	else
	{
		system("clear");
		//将新的密码复制给原密码数组
		strcpy(sys_passward,ch_passward[0]);
		printf(Y"密码修改成功，请重新登录系统\n"N);
		passward();
	}

}


void user(node_commodity *head_commodity,node_shop * head_shop,node_history *head_history,char *flic_name,char *flis_name)
{
	char key1;

	while (1)
	{
		// system("clear");
		show_user();
		scanf("%c",&key1);
		while (getchar()!='\n');
		switch (key1)
		{
			case '1' ://添加购买商品
			{ 
				// system("clear");
				display_commodity_list(head_commodity);
				while (1)
				{
					init_shop_head(head_shop,head_commodity);
					printf(Y"是否继续输入，继续请按【y】 退出【任意键】\n"N);
					if(my_getch()=='y')
					continue;
					else
					break;
				}
				
				
				break;
			}
			case '2' ://查看及操作购物车内容(并更新历史数据)
			{ 
				bool ism=display_shop_list(head_shop);
				if(!ism)
				{
					printf(Y"返回【任意键】\n"N);
					while (1)
					{
						if(my_getch()!=0)
						break;
					}
				}
				if(ism)
				{
					printf(Y"是否全部购买，购买请按【y】 退出【任意键】\n"N);
					char key2;
					scanf("%c",&key2);
					while (getchar()!='\n');
					switch (key2)
					{
						case 'y':
						{	
							//销毁购物车链表(链表头不销毁)
							destroy_link_list(head_commodity,head_shop,head_history);
							printf(Y"成功购买所有商品,欢迎下次光临！\n"N);
							write_history(head_history,flis_name);
							write_commodity_txt(head_commodity,flic_name);
							break;
						}
						default:break;
					}
					sleep(2);
					// system("clear");
				}
				break;
			}
			case '3' ://添修改购物车信息
			{ 
				bool ism=display_shop_list(head_shop);
				if(!ism)
				{
					printf(Y"返回【任意键】\n"N);
					if(my_getch()!=0)
					break;	
				}
				change_shop_list(head_commodity,head_shop);
				sleep(1);
				break;
			}
			case '0' ://退出用户模式
			{ 
				return;
			}																		
			default:printf(RE"您输入命令有误，请重新输入\n"N);break;
		}
	}
}

void admin(node_commodity *head_commodity,node_history *head_history,char *flic_name,char *flis_name)
{
	char key3;
	while (1)
	{
		
		show_admin();
	MM:
		scanf("%c",&key3);
		while (getchar()!='\n');
		switch (key3)
		{
			//输入账号密码登录进去
			case '1' ://录入商品(查看录入商品是否已经存在)
			{ 	
				while (1)
				{
					write_txt(head_commodity,flic_name);
					printf(Y"是否继续输入，继续请按【y】 退出【任意键】\n"N);
					if(my_getch()=='y')
					continue;
					else
					break;
				}
				system("clear");
				break;
			}
			case '2' ://搜索已有商品,并且更改信息
			{ 
				while (1)
				{
					change_commodity(head_commodity,flic_name);
					printf(Y"是否继续修改，继续请按【y】 退出【任意键】\n"N);
					if(my_getch()=='y')
					continue;
					else
					break;
				}
				system("clear");
				break;
			}
			case '3' ://查看购买历史(从shopping_history.txt读取购物历史信息,并且打印出)
			{ 
				display_history_list(head_history,flis_name);
				break;
			}
			case '4' ://修改管理员密码
			{ 
				ch_passwd();
				break;
			}
			case '0' ://退出用户模式
			{ 
				return;
			}																		
			default:printf(RE"您输入命令有误，请重新输入\n"N);goto MM;break;
		}

	}
}



