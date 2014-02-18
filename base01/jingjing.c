#include <stdio.h>

int main(void)
{
	int date;
	while(scanf("%d", &date) == 1)
	{
		if (date == 1 || date == 3 || date == 5)
		{
			puts("NO");
		}else
		{

			puts("YES");
		}

	}
	return 0;
}
