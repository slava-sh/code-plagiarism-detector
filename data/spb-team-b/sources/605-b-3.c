#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	int n, i, k;
	int a[1000] = {0};
	freopen("chess.in", "rt", stdin);
	freopen("chess.out", "wt", stdout);
	scanf("%i", &n);
	for (i = 0; i < n; i++)
		scanf("%i", &a[i]);
	i = 0;
	while (a[i] >= i + 1)
		i++;
  n = i;
	printf("%i\n", n);
	for (i = 0; i < n; i++)
	  printf("%i %i\n", i + 1, i + 1);
}