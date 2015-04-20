#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main( void )
{
	int a, b, c, n, i;
	freopen("abcd.in", "rt", stdin);
	freopen("abcd.out", "wt", stdout);
	scanf("%i", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%i", &c);
		b = c % 100;
		a = c / 100;
		if ((a * a + b * b) % 7 == 1)
			printf("YES\n");
		else
			printf("NO\n");
	}
}