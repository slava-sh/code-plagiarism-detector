#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main( void )
{
	int a, b, c, n, i;
	freopen("abcd.in", "rb", stdin);
	freopen("abcd.out", "wb", stdout);
	scanf("%i", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%i", &c);
		b = c % 100;
		a = c / 100;
		if ((a * a + b * b) % 7 == 1)
			printf("YES");
		else
			printf("NO");
		if (i != n - 1)
			printf("\n");
	}
}