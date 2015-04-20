


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, i, k = 0, j = 1;
	int arrey[1000] = { NULL };
	int tmp[1000] = { NULL };
	FILE *in, *out;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(in, "%d", &arrey[i]);
	}
	for (i = 0; i < n; i++)
	{
		if (arrey[i] >= j)
		{
			k++;
			j++;
		}
	}
	fprintf(out, "%d\n", k);
	while (k != 0)
	{
		fprintf(out, "%d %d\n", k, k);
		k--;
	}
	return 0;
}
