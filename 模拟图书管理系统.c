#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<conio.h>
#define BKCONT 50



typedef struct book
{
	char name[20];               //书名成员
	char writer[20];             //作者成员
	char number[20];             //编号成员
	int  hot;                    //热度成员
	int  sc;                     //库存成员
	float price;	             //价格成员
}BOOK;




void show(void);
void passward(void);
void key_scan(void);
void ch_passwd(void);
void add_book(void);
void search_book(void);
void hot_book(void);
void back_book(void);

char sys_passward[10] = "123456";
BOOK bks[BKCONT];



int main(void)
{
	//密码登录函数
	passward();
	while(1)
	{
		
		//界面显示函数
		show();
		//按键选择函数
		key_scan();	
	}

	
	return 0;
}


/***********************************************
*函数名    ：show
*函数功能  ：显示图书管理系统的主界面
*函数参数  ：无
*函数返回值：无
*函数描述  ：
***********************************************/
void show(void)
{
	printf("-------------------------------------------------\n");
	printf("|          欢迎来到图书管理系统                 |\n");
	printf("-------------------------------------------------\n");
	printf("|        【1】检索      【2】还书               |\n");
	printf("|        【3】热度排行榜【4】添加新书           |\n");
	printf("|        【5】密码修改  【0】退出程序           |\n");
	printf("-------------------------------------------------\n");
	printf("请选择：");
	
}



/***********************************************
*函数名    ：passward
*函数功能  ：密码登录函数
*函数参数  ：无
*函数返回值：无
*函数描述  ：
***********************************************/
void passward(void)
{
	int i = 0;
	char user_passward[10];
	int cont = 0;
	
	printf("请输入系统登录密码\n");
STAR:	
	for(i=0;i<10;i++)
	{
		user_passward[i] = getch();
		//按回车和删除不显示*
		if(user_passward[i] != 13 && user_passward[i] != 8)
		{
			printf("*");
		}
		
		//按回车结束输入 添加结束字符
		if(user_passward[i] == 13)
		{
			//将回车替换为结束符
			user_passward[i] = '\0';
			break;
		}

		//按删除键
		if(user_passward[i] == 8)
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
		system("cls");
		cont++;
		if(cont == 5)
		{
			printf("密码输入错误次数达到5次，请按任意键退出系统\n\a\a\a");
			getch();
			exit(1);
		}
		printf("密码错误，请重新输入\n");
		goto STAR;
	}
	
	system("cls");
}







/************************************************
*函数名    ：key_scan
*函数功能  ：按键识别函数
*函数参数  ：无
*函数返回值：无
*函数描述  ：无
***************************************************/
void key_scan(void)
{
	char key;
STAR:
	key = getch();
	system("cls");
	switch(key)
	{
		case '1':search_book();break;
		case '2':back_book();break;
		case '3':hot_book();break;
		case '4':add_book();break;
		case '5':ch_passwd();break;
		case '0':exit(1);break;
		default:printf("您输入命令有误，请重新输入\n");goto STAR;break;
		
	}
	
	system("cls");
}


/************************************************
*函数名    ：ch_passwd
*函数功能  ：修改密码
*函数参数  ：无
*函数返回值：无
*函数描述  ：无
***************************************************/
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
		printf("\n请输入第%d次密码\n",j+1);
		for(i=0;i<10;i++)
		{
			ch_passward[j][i] = getch();
			//按回车和删除不显示*
			if(ch_passward[j][i] != 13 && ch_passward[j][i] != 8)
			{
				printf("*");
			}
			
			//按回车结束输入 添加结束字符
			if(ch_passward[j][i] == 13)
			{
				//将回车替换为结束符
				ch_passward[j][i] = '\0';
				break;
			}

			//按删除键
			if(ch_passward[j][i] == 8)
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
		system("cls");
		printf("您输入的两次密码不一致，请重新输入\n");
		goto SA;
		
	}
	else
	{
		system("cls");
		//将新的密码复制给原密码数组
		strcpy(sys_passward,ch_passward[0]);
		printf("密码修改成功，请重新登录系统\n");
		passward();
	}

}




/************************************************
*函数名    ：add_book
*函数功能  ：添加新书函数
*函数参数  ：无
*函数返回值：无
*函数描述  ：进入此函数可以添加新书到数组中
***************************************************/
void add_book(void)
{
	
	static int i = 0;
	
	while(i<BKCONT)
	{
		printf("请输入第%d本书名:\n",i+1);
		scanf("%s",bks[i].name);
		printf("请输入第%d本作者名:\n",i+1);
		scanf("%s",bks[i].writer);
		printf("请输入第%d本编号:\n",i+1);
		scanf("%s",bks[i].number);
		printf("请输入第%d本热度:\n",i+1);
		scanf("%d",&bks[i].hot);
		printf("请输入第%d本库存:\n",i+1);
		scanf("%d",&bks[i].sc);
		printf("请输入第%d本价格:\n",i+1);
		scanf("%f",&bks[i].price);
		i++;
		
		printf("是否继续输入，继续请按【y】 退出【任意键】\n");
		if(getch() != 'y')
		{
			break;
		}		
	}
	
	system("cls");

}




/************************************************
*函数名    ：search_book
*函数功能  ：检索图书
*函数参数  ：无
*函数返回值：无
*函数描述  ：三种方式查找图书
***************************************************/
void search_book(void)
{
	char k;
	int i = 0;
	char book_name[30] = {0};
	char book_num[30] = {0};
	int cont = 0;
	int q;
	
	
	printf("-------------------------------------------------\n");
	printf("|                搜索方式如下                    |\n");
	printf("-------------------------------------------------\n");
	printf("|               【1】全部检索                    |\n");
	printf("|               【2】按书名检索                  |\n");
	printf("|               【3】按作者检索                  |\n");
	printf("|               【0】返回值主界面                |\n");
	printf("-------------------------------------------------\n");
	printf("请选择：");
SR:	
	k = getch();
	system("cls");
	if(k == '1')                    //全部检索
	{
		while(bks[i].name[0] != '\0')
		{
			printf("书名:%s\n作者:%s\n编号:%s\n热度:%d\n库存:%d\n价格:%0.2f\n",
				bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
				printf("\n");
			i++;
		}
		printf("按任意键返回主界面\n");
		getch();	
	}
	
	else if(k == '2')               //按书名检索
	{
		RT:
		system("cls");
		printf("请输入要查找的书名：\n");
		scanf("%s",book_name);
		//遍历所有有效书
		while(bks[i].name[0]!= '\0')
		{
			if(strcmp(bks[i].name,book_name) == 0)
			{
				q = i;
				//打印符合条件的书
				printf("书名:%s\n作者:%s\n编号:%s\n热度:%d\n库存:%d\n价格:%0.2f\n",
				bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
				printf("\n");
				cont++;
			}
			i++;
		}
		
		
		//根据找到书的本数处理
		if(cont == 0)                                             //没有书
		{
			printf("没有符合要求的书，正在通知管理员\n");
			printf("按【y】重新查找，按【其他键】返回值主界面\n");
			if(getch() == 'y')
			{
				goto RT;
			}
		}
		else if(cont == 1)                                       //一本书
		{
			printf("找到%d本符合要求的书\n",cont);
			printf("借阅请按【j】,返回主界面请按【其他键】\n");
			if(getch()=='j')
			{
				if(bks[q].sc == 0)
				{
					printf("此图书已经被借完，请等待...按任意键返回主界面\n");
					getch();
				}
				else
				{
					bks[q].hot++;
					bks[q].sc--;
					printf("借阅成功，按任意键返回主界面\n");
					getch();
				}	
			}
			
		}
		else                                                     //多本书
		{
			printf("找到%d本符合要求的书\n",cont);
			printf("借阅请按【j】,返回主界面请按【其他键】\n");
			if(getch() == 'j')
			{
				printf("请输入您要借阅的编号\n");
				QST:
				scanf("%s",book_num);
				i = 0;
				while(bks[i].name[0] != '\0')
				{
					if(strcmp(bks[i].number,book_num) == 0)
					{
						break;
					}
					i++;
				}
				//i的值就是此编号的书的下标
				//验证用户输入的编号是否正确
				if(strcmp(bks[i].name,book_name) == 0)
				{
					if(bks[i].sc == 0)
					{
						printf("此图书已经被借完，请等待...按任意键返回主界面\n");
						getch();
					}
					else
					{
						bks[i].hot++;
						bks[i].sc--;
						printf("借阅成功，按任意键返回主界面\n");
						getch();
					}
					
				}
				else
				{
					printf("您输入的编号有误，请重新输入\n");
					goto QST;
				}

			}
		}
	}
	
	
	else if(k == '3')               //按作者名检索
	{
		
	}
	else if(k == '0')
	{
		//回到主界面
		return;
	}
	else
	{
		printf("您输入的命令有误，请重新输入\n");
		goto SR;
	}

}


/************************************************
*函数名    ：hot_book
*函数功能  ：热度排序
*函数参数  ：无
*函数返回值：无
*函数描述  ：
***************************************************/
void hot_book(void)
{
	int n = 0;
	int i = 0;
	int j;
	BOOK temp;
	
	
	//计算出有效书的本输
	while(bks[i].name[0]!= '\0')
	{
		n++;
		i++;
	}
	//n出来就是有效书的本数
	//排序
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<n-i;j++)
		{
			if(bks[j].hot < bks[j+1].hot)
			{
				//交换元素的位置
				temp = bks[j];
				bks[j] = bks[j+1];
				bks[j+1] = temp;
				
			}
			
		}
	}
	
	i = 0;
	//打印排序后的数组
	while(bks[i].name[0] != '\0')
	{
		printf("书名:%s\n作者:%s\n编号:%s\n热度:%d\n库存:%d\n价格:%0.2f\n",
			bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
			printf("\n");
		i++;
	}
	printf("按任意键返回主界面\n");
	getch();	
}


/************************************************
*函数名    ：back_book
*函数功能  ：还书函数
*函数参数  ：无
*函数返回值：无
*函数描述  ：无
***************************************************/
void back_book(void)
{
	int i = 0;
	int cont = 0;
	char book_num[30];
BSTA:
	printf("请输入您要还书的编号\n");
	scanf("%s", book_num);
	while(bks[i].name[0] != '\0')
	{
		if(strcmp(bks[i].number,book_num) == 0)
		{
			cont++;
			printf("书名:%s\n作者:%s\n编号:%s\n热度:%d\n库存:%d\n价格:%0.2f\n",
			bks[i].name,bks[i].writer,bks[i].number,bks[i].hot,bks[i].sc,bks[i].price);
			break;
		}
		i++;
	}
	//i就是此编号的书的下标
	if(cont == 0)    
	{ 
		printf("您输入的编号有误，请重新输入\n");
		goto BSTA;
	}
	else
	{
		printf("确认请按【y】,返回按【其他键】");
		if(getch() == 'y')
		{
			bks[i].sc++;
			printf("还书成功,继续还书按【b】,返回界面按【其他键】\n");
			if(getch() == 'b')
			{
				cont  = 0;
				goto BSTA;
			}	
		}
	}

}


