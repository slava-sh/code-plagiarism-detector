#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *in, *out;
	int n, i = 0, k;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d\n%d", &n, &k);
	for (; i < n; ++i)
		fscanf(in, " %d", &n);
	fprintf(out, "%d\n", i);
	for (k = 0; k < i; ++k)
	{
		fprintf(out, "%d %d\n", k + 1, k + 1);
	}
	fflush(out);
	return 0;
}