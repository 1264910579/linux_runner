#include<stdio.h>
#include<math.h>
int cishu(int b);

int main ()
{
	int a;
	printf("请输入一个数据：");
	scanf("%d",&a);
	printf("0到n(包括n)中数字2出现了%d次：",cishu(a));
	return 0;
}

int cishu(int b)
{	
	int zongcishu=0;
	int e;
	int sum=0;
	int d=b;
	int k;
	int j;
	for(e=1;e<=d;e++)
	{	j=e;
			do
		{
			if(e/10>0)
			{
			sum++;
			e/=10;
			}
		}while(e/10);
		k=j/pow(10,sum-1);
		k=k%10;
		if(k==2)
		{
	
		zongcishu++;
			}
	}
	return sum;
	
}
