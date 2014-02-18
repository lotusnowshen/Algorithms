#include <stdio.h>


int main(void)
{	
	int year;
	while(scanf("%d", &year) == 1 )
	{
		if (year%100==0 && year%400 || year%4 || year%3200==0)
		{
			puts("N");
		}else{
			puts("Y");
		}
	}
	return 0;
}
