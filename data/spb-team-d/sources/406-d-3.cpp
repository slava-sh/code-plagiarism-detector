#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 100000000


int main()
{
	__int64 n, m, l, r, x, i = 0, j = 0, q, c = 1;
	long long a[MAXLEN];
	FILE *in, *out;
	in = fopen("dunes.in", "r");
	out = fopen("dunes.out", "w");
	fscanf(in, "%I64d %I64d", &n, &m);
	while (i < n)
	{
		fscanf(in, "%I64d %I64d %I64d", &l, &r, &x);
		j = l;
		while (j <= r)
		{
			a[j-1] = a[j-1] + c * x;
			j++;
			c *= -1;
		}
		i++;
		c = 1;
	}
	for (i = 0; i < m; i++)
	{
		fscanf(in, "%I64d", &q);
		fprintf(out, "%I64d\n", a[q - 1]);
	}
	return 0;
}