#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main( void )
{
	int a, b, c, n, i;
	char p[5];
	freopen("abcd.in", "rt", stdin);
	freopen("abcd.out", "wt", stdout);
	scanf("%i", &n);
	for (i = 0; i < n; i++)
	{
	  scanf("%s", p);
		a = (p[0] - 48) * 10 + p[1] - 48;
	  b = (p[2] - 48) * 10 + p[3] - 48;
		if ((a * a + b * b) % 7 == 1)
			printf("YES");
		if ((a * a + b * b) % 7 != 1)
			printf("NO");
		if (i != n - 1)
			printf("\n");
	}		
}