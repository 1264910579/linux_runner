#include<stdio.h>
#include<math.h>
int cishu(int b);

int main ()
{
	int a;
	printf("������һ�����ݣ�");
	scanf("%d",&a);
	printf("0��n(����n)������2������%d�Σ�",cishu(a));
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
