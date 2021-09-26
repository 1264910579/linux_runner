#include<stdio.h>
#include<string.h>

int main()
	{
		
		int n,l,i;
		int j=1;
		while(j<4)
		{
		printf("第%d/3次测试 ",j);
		char ch[3000];
		printf("请输入字符串:");
		scanf("%s",ch);
		l=strlen(ch);
		for(i=0;i<=l/2;i++)
		{
			if(ch[i]!=ch[l-i-1])
				break;
		}
		if(i<l/2)
		{
		printf("不是回文");
		}
		else
		{
		printf("是回文");	
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

