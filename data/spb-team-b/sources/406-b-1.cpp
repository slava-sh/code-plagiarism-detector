#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, i, j = 0;
	int arrey[1000] = { NULL };
	int tmp[1000] = { NULL };
	//FILE *in, *out;
	//in = fopen("chess.in", "r");
	//	out = fopen("chess.out", "w");
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arrey[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (tmp[j] != arrey[i])
		{
			tmp[j] == arrey[i];
			j++;
		}
	}
	printf("%d\n", j - 1);
	for (i = 1; i < j; i++)
	{
		printf("%d %d\n", i, i);
	}
	return 0;
}
