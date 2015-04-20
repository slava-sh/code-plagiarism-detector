#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main( void )
{
	int n, i, k, cnt = 1;
	int a[10000] = { 0 };
	freopen("chess.in", "rt", stdin);
	freopen("chess.out", "wt", stdout);
	scanf("%i", &n);
	for (i = 1; i <= n; i++)
		scanf("%i", &a[i]);
	i = 1;
	while (a[i] >= i)
		i++;
	printf("%i\n", i - 1);
	cnt = i - 1;
	for (i = 0; i < cnt; i++)
		printf("%i %i\n", i + 1, i + 1);
}
