#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main( void )
{
	int n, i, k, cnt = 1;
	int a[1000] = { 0 };
	freopen("chess.in", "rt", stdin);
	freopen("chess.out", "wt", stdout);
	scanf("%i", &n);
	for (i = 0; i < n; i++)
		scanf("%i", &a[i]);
	i = 0;
	while (a[i] >= cnt++)
		i++;
	printf("%i\n", cnt - 2);
	for (i = 0; i < cnt - 2; i++)
		printf("%i %i\n", i + 1, i + 1);
}
