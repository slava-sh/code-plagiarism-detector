#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
	FILE *Fin;
	FILE *Fout;
	Fin = fopen("dunes.in", "r");
	Fout = fopen("dunes.out", "w");
	int n, m, s[1000];
	int i, j, p = 1;
	int c;
	fscanf(Fin, "%i %i", &n, &m);
	int l[n], r[n], x[n];
	int a[1000];
	int max;
	for (i = 0; i < n; i++)
	{
		fscanf(Fin, "%i %i %i", &l[i], &r[i], &x[i]);
	}
	for (i = 0; i < m; i++)
		fscanf(Fin, "%i", &s[i]);
	c = m - 1;
	max = s[c];
	for (i = 0; i < max; i++)
		a[i] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = l[i]; j < r[i]; j++)
		{
			a[j] += p * x[j];
			p *= -1;
		}
		p = 1;
	}
	for (i = 0; i < m; i++)
	{
		fprintf(Fout, "%i", a[s[i]]);
		fprintf(Fout, "\n");
	}
	fclose(Fin);
	fclose(Fout);
	return 0;
}