#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *in, *out;
	int n, a, i, k;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d\n", &n);
	for (i = 1; ; ++i)
	{
		fscanf(in, "%d ", &n);
		if (i > n)
		{
			break;
		}
	}
	fprintf(out, "%d\n", i - 1);
	for (k = 1; k < i; ++k)
	{
		fprintf(out, "%d %d\n", k, k);
	}
	fclose(out);
	return 0;
}