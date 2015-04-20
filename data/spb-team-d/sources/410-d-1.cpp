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
	int i, j, i1 = 1;
	int l[n], r[n], x[n];
	int a[1000];
	int max;
	fscanf(Fin, "%i %i", &n, &m);
	for (i = 0; i < n; i++)
	{
		scanf(Fin, "%i %i %i", &l[i], &r[i], &x[i]);
	}
	for (i = 0; i < m; i++)
		fscanf(Fin, "%i", &s[i]);
	max = s[m - 1];
	for (i = 0; i < max; i++)
		a[i] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = l[i]; j < r[i]; j++)
		{
			a[j] += i1 * x[j];
			i1 *= -1;
		}
		i1 = 1;
	}
	for (i = 0; i < m; i++)
		fprintf(Fout, "%i\n", a[s[i]]);
	fclose(Fin);
	fclose(Fout);
	return 0;
}