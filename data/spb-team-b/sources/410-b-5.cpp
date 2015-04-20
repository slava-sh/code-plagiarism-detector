#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main(void)
{
	FILE *Fin;
	FILE *Fout;
	Fin = fopen("chess.in", "r");
	Fout = fopen("chess.out", "w");
	int n, g, x, k = 1, l = 1, i = 0, h;
	int a[1001];
	fscanf(Fin, "%i", &n);
	g = 1;
	while (g <= n)
	{
		fscanf(Fin, "%i", &x);
		a[g] = x;
		g++;
	}
	while (k <= n && l <= a[k])
	{
		k++;
		i++;
		l++;
	}
	fprintf(Fout, "%i", i);
	h = 1;
	while (h <= i)
	{	
		fprintf(Fout, "\n");
		fprintf(Fout, "%i %i", h, h);
		h++;
	}
	fclose(Fin);
	fclose(Fout);
	return 0;
}