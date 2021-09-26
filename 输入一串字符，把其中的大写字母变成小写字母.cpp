#include<stdio.h>


int main()


{ 	
	int i=0;
	char a[10];
	printf("ÇëÊäÈëÒ»´®×Ö·û´®£º");
	gets(a);
	while(a[i] != '\0')
	{
		if( a[i]>=65 && a[i]<=90)	
		{
			a[i] = a[i]+32 ;		
		}
		
		i++;
	 } 

	puts(a); 
	


	return 0;
}


