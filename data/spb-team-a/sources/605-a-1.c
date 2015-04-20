#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	int b, c = 1, flag = 1;
	scanf("%i", &b);
	while (flag != 0)
	{ 
		printf("%i", (b + c) / 2);
		fflush(stdout);
		scanf("%i", &flag);
		if (flag == 1)
			c = (b + c) / 2 + 1;
		if (flag == -1)
			b = (b + c) / 2 - 1;
	}
}