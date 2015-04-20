#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX 10000
int main(void)
{
	FILE *Fin;
	FILE *Fout;
	Fin = fopen("dunes.in", "r");
	Fout = fopen("dunes.out", "w");
	int n, m, s[1000];
	int i, j, p = 1;
	int c, z;
	fscanf(Fin, "%i %i", &n, &m);
	long long l[MAX], r[MAX], x[MAX];
	int a[1000];
	int big;
	for (i = 0; i < n; i++)
	{
		fscanf(Fin, "%I64d %I64d %I64d", &l[i], &r[i], &x[i]);
	}
	for (i = 0; i < m; i++)
		fscanf(Fin, "%i", &s[i]);
	c = m - 1;
	big = s[m];
	for (i = 0; i < big; i++)
		a[i] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = l[i]; j <= r[i]; j++)
		{
			a[j-1] += p * x[i];
			p *= -1;
		}
		p = 1;
	}
	for (i = 0; i < m; i++)
	{
		z = s[i] - 1;
		fprintf(Fout, "%i", a[z]);
		fprintf(Fout, "\n");
	}
    fclose(Fin);
    fclose(Fout);
	return 0;
}
