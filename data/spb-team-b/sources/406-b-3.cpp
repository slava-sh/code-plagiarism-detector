#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int n, i, j = 1;
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
	tmp[0] = arrey[0];
	for (i = 0; i < n; i++)
	{
		if (tmp[j-1] != arrey[i])
		{
			tmp[j] = arrey[i];
			j++;
		}
	}
	if (n == 0)
	{
		fprintf(out, "0");
		return 0;
	}
	if (n == 1)
	{
		fprintf(out,"1 \n");
		fprintf(out,"1 1");
		return 0;
	}
	fprintf(out, "%d\n", j - 1);
	for (i = 1; i < j; i++)
	{
		fprintf(out, "%d %d\n", i, i);
	}
	return 0;
}