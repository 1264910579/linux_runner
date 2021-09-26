#include<stdio.h>
#include <stdlib.h>
#include <time.h> //用到了time函数 
#include<conio.h>
void display(void); 
void key_scanf( char a,int b,int c );
int suiji(void);
int duibi(int e,int f,int g); 
 int main(void)
 {
 	int number1,number2;
 	char key;
 	int d;
 	int k;
    display();
	number1=suiji();	
 mm: key=getch();
 	if(key !='+' && key !='-' && key !='*' && key !='/')
	 {
	 printf("您输入有误，请重新输入\n");
	 goto mm;	
	 }
	
	
	number2=suiji();
	printf("随机数a值为%d，b值为%d\n",number1,number2);
	printf("请用户输入答案：\n");
	scanf("%d",&d);
	duibi(d,number1,number2); 
	key_scanf(key, number1,number2 );

	printf("最终得分是多少：%d\n",	duibi(d,number1,number2));
 	return 0;
  } 
  
  void display(void)
  {
  	printf("............\n");
  	printf("欢迎来到本次游戏\n");
  	printf("............\n");
  	printf("游戏模式有以下四个\n");
  	printf("[+],[-],[*],[/]\n");
  	printf("请输入游戏模式：\n");
  }
 void key_scanf( char c,int a,int b )
 {
 	switch(c)
 	{
	
 	case '+' :	
	 			printf("随机数a+b的正确值为%d\n",a+b); break;
	case '-' :	
				printf("随机数a-b的正确值为%d\n",a-b); break;	
	case '*' :	
				printf("随机数a*b的正确值为%d\n",a*b); break;
	case '/' :	
				printf("随机数a/b的正确值为%d\n",a/b); break;
 	 }
 	
 }
int suiji(void)
		{  
			int i,number;
			srand((unsigned) time(NULL)); //用时间做种，每次产生随机数不一样
			for (i=0; i<50; i++)
			{
			number = rand() % 101;  //产生0-100的随机数
			}   
			return number;
		}
int duibi(int e,int f,int g)
{
	int a=0;
	if(e==f+g)
	{
		printf("恭喜你，回答正确。");
		a+=10;
	}
	else 
	{
	printf("很遗憾，回答错误。");
	a-=10;	
	}
	return a;
}
