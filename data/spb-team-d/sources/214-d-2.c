/* 10-15-A, B */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	FILE *InF, *OutF;
	__int64 i, j, n, m, x[1000], d[1000];
	long long r[1000];
	long long l[1000];
	long long q[1000];

	InF = fopen("dunes.in", "r");
	if (InF == NULL)
		return 1;

	OutF = fopen("dunes.out", "w");
	if (OutF == NULL)
		return 1;

	fscanf(InF, "%I64d%I64d", &n, &m);
	
	for (i = 0; i < m; i++)
		d[i] = 0;

	for (i = 0; i < n; i++)
		fscanf(InF, "%lli%lli%I64d", &l[i], &r[i], &x[i]);

	for (i = 0; i < m; i++)
		fscanf(InF, "%I64d", &q[i]);

	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			if (q[i] >= l[j] && q[i] <= r[j])
				if ((q[i] - l[j]) % 2 == 0)
					d[i] += x[j];
				else
					d[i] -= x[j];

	for (i = 0; i < m; i++)
		fprintf(OutF, "%lli\n", d[i]);

	fclose(InF);
	fclose(OutF);
	return 0;
}