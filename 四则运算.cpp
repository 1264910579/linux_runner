#include<stdio.h>
#include <stdlib.h>
#include <time.h> //�õ���time���� 
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
	 printf("��������������������\n");
	 goto mm;	
	 }
	
	
	number2=suiji();
	printf("�����aֵΪ%d��bֵΪ%d\n",number1,number2);
	printf("���û�����𰸣�\n");
	scanf("%d",&d);
	duibi(d,number1,number2); 
	key_scanf(key, number1,number2 );

	printf("���յ÷��Ƕ��٣�%d\n",	duibi(d,number1,number2));
 	return 0;
  } 
  
  void display(void)
  {
  	printf("............\n");
  	printf("��ӭ����������Ϸ\n");
  	printf("............\n");
  	printf("��Ϸģʽ�������ĸ�\n");
  	printf("[+],[-],[*],[/]\n");
  	printf("��������Ϸģʽ��\n");
  }
 void key_scanf( char c,int a,int b )
 {
 	switch(c)
 	{
	
 	case '+' :	
	 			printf("�����a+b����ȷֵΪ%d\n",a+b); break;
	case '-' :	
				printf("�����a-b����ȷֵΪ%d\n",a-b); break;	
	case '*' :	
				printf("�����a*b����ȷֵΪ%d\n",a*b); break;
	case '/' :	
				printf("�����a/b����ȷֵΪ%d\n",a/b); break;
 	 }
 	
 }
int suiji(void)
		{  
			int i,number;
			srand((unsigned) time(NULL)); //��ʱ�����֣�ÿ�β����������һ��
			for (i=0; i<50; i++)
			{
			number = rand() % 101;  //����0-100�������
			}   
			return number;
		}
int duibi(int e,int f,int g)
{
	int a=0;
	if(e==f+g)
	{
		printf("��ϲ�㣬�ش���ȷ��");
		a+=10;
	}
	else 
	{
	printf("���ź����ش����");
	a-=10;	
	}
	return a;
}
