#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int k = 0, i, *a, n;
	freopen("chess.in", "rt", stdin);
	freopen("chess.out", "wt", stdout);
	scanf("%i", &n);
	a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
		scanf("%i", &a[i]);
	for (i = 1; i <= a[0]; i++)
		if (i > a[i - 1])
			break;
		else
			k++;
	printf("%i\n", k);
	for (i = 1; i <= k; i++)
		printf("%i %i\n", i, i);
	free(a);
	return 0;
}
