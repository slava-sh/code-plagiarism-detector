#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()
{
	FILE *in, *out;
	int n, i = 0, k;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d\r\n%d", &n, &k);
	for (; i < n; ++i)
		fscanf(in, " %d", &n);
	fprintf(out, "%d\r\n", i);
	for (k = 0; k < i; ++k)
	{
		fprintf(out, "%d %d\r\n", k + 1, k + 1);
	}
	fflush(out);
	return 0;
}