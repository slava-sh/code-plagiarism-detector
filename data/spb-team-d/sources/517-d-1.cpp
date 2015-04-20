#include <stdio.h>

#define MAX_ARRAY_SIZE 1000

int main( void )
{
	int n, m, x, i;
	long long Dune[MAX_ARRAY_SIZE] = {0}, l, r, j, tmp;
	FILE *in, *out;

	in = fopen("dunes.in", "rt");
	out = fopen("dunes.out", "wt");

	fscanf(in, "%d%d", &n, &m);

	for (i = 0; i < n; i++)
	{
		fscanf(in, "%I64d %I64d %d", &l, &r, &x);
		for (j = l; j <= r; j++)
			Dune[j] += ((l - j) & 1) == 0? x : -x;
	}

	for (i = 0; i < m; i++)
	{
		fscanf(in, "%I64d", &tmp);
		fprintf(out, "%I64d\n", Dune[tmp]);
	}

	fclose(in);
	fclose(out);

	return 0;
}