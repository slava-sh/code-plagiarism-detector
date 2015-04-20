#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *in, *out;
	int n, i, k;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d\n%d", &n, &k);
	for (i = 1; i < n; ++i)
	{
		fscanf(in, " %d", &n);
		if (i >= n)
		{
			break;
		}
	}
	fprintf(out, "%d\n", i);
	for (k = 1; k <= i; ++k)
	{
		fprintf(out, "%d %d\n", k, k);
	}
	fflush(out);
	return 0;
}