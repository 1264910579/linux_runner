#include<stdio.h>
#include<conio.h>
int main()
	{
		int i;
		int j;
		int a[6];
		int zan;
		for(i=0;i<6;i++)
		{
		scanf("%d\t",a+i);		
		}	
		for(i=1;i<6;i++)
		{
			for(j=0;j<6-i;j++)
			{
				if(a[j]>a[j+1])	
				{
				zan=a[j];
				a[j]=a[j+1];
				a[j+1]=zan;			
				}				
			}
		}
			for(i=0;i<6;i++)
			{
				printf("%d\t",a[i]);
			}
	}
		
		
		


