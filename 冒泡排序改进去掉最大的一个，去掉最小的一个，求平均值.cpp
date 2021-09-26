#include<stdio.h>


float pingjun(int *p);

int main()
{	
	int j; 
	int i=0;
	int zancun;
	int a[10];
	for(i=0;i<=10;i++)
	{
		printf("请输入一组数据：");
		scanf("%d",&a[i]);		
	}
	printf("%f",pingjun(a));
//	for(i=1;i<10;i++)
//	{
//		for(j=0;j<10-i;j++)
	//	{
	//		if(a[j]<a[j+1])	
	//		{
	//	
		//		zancun=a[j];
		//		a[j]=a[j+1];
		//		a[j+1]=zancun;	
		//	}		
	//	}		
//	}	

}

float pingjun(int a[10])
{	int	j;
	int i;
	int zancun;
	int sum=0;
	for(i=1;i<10;i++)
	{
		for(j=0;j<10-i;j++)
	{
			if(a[j]<a[j+1])	
			{
		
				zancun=a[j];
				a[j]=a[j+1];
			a[j+1]=zancun;	
		}		
	}
			
	}	
for(i=1;i<10;i++)
{
	sum=sum+a[i];
	
	
}
	
	return sum/8;
	}

