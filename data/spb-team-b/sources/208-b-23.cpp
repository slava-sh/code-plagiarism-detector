#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main123()
{
	FILE *in, *out;
	long long n, i = 0, k;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%I64d\n%I64d", &n, &k);
	for (; i < n, i < k; ++i)
		fscanf(in, " %I64d", &k);
	if (k == n) i = n;
	fprintf(out, "%I64d\n", i);
	for (k = 1; k <= i; ++k)
	{
		fprintf(out, "%I64d %I64d\n", k, k);
	}
	fflush(out);
	return 0;
}

int main()
{
	FILE *in, *out;
	int cols, i, height;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d\n", &cols);
	for (i = 0; i < cols; ++i)
	{
		fscanf(in, "%d", &height);
		if (height <= (i + 1))
			break;
	}
	fprintf(out, "%d", i);
	while (i-- > 0)
	{
		fprintf(out, "\n%d %d", i + 1, i + 1);
	}
	fflush(out);
	return 0;
}