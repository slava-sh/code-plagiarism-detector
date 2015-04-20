#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int oldMain()
{
	FILE *in, *out;
	int n, i = 0, k;
	in = fopen("chess.in", "r");
	out = fopen("chess.out", "w");
	fscanf(in, "%d\r\n%d", &n, &k);
	for (; i < n; ++i)
		fscanf(in, " %d", &n);
	fprintf(out, "%d\r\n", i);
	for (k = 1; k <= i; ++k)
	{
		fprintf(out, "%d %d\r\n", k, k);
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
		if (height <= i)
		{
			i = height + 1;
			break;
		}
	}
	fprintf(out, "%d\n", i);
	while (i-- > 0)
	{
		fprintf(out, "%d %d\n", i + 1, i + 1);
	}
	fflush(out);
	return 0;
}