#include<stdio.h>
#include<string.h>

int main()
	{
		
		int n,l,i;
		int j=1;
		while(j<4)
		{
		printf("��%d/3�β��� ",j);
		char ch[3000];
		printf("�������ַ���:");
		scanf("%s",ch);
		l=strlen(ch);
		
/***�����һλ�����һλ�Ƚϣ���һ����������һ���ͼ������У�i++�����i<len/2,��˵����;��break�ˣ���;�Ͳ������**/ 
		for(i=0;i<=l/2;i++)
		{
			if(ch[i]!=ch[l-i-1])
				break;
		}
		if(i<l/2)
		{
		printf("���ǻ���");
		}
		else
		{
		printf("�ǻ���");	
		}	
		for(i=0,n=1;i<l;i++)
		{ 
			if(ch[i]==ch[i+1])
			{
				n++;
			}
			else
			{
				 if(n==1)
				{	printf("%c",ch[i]);
					n=1;
				}
				 else
				{
				printf("%d%c",n,ch[i-1]);
				n=1;
				}
			}
		}
		j++;
		printf("\n");
	}	
		
	}

