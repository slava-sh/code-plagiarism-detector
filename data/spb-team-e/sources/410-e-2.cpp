#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


int main(void)
{
	FILE *Fin;
	FILE *Fout;
	Fin = fopen("game.in", "r");
	Fout = fopen("game.out", "w");
	struct
	{
		int h;
		int f;
	}Stolb;
	int x, i, m, n, r1, l1, r2, l2, Petya = 0, Vasya = 0, hod = 1;
	Stolb a[100001];
	fscanf(Fin, "%i %i", &n, &m);
	fscanf(Fin, "%i", &l1, &r1);
	fscanf(Fin, "%i", &l2, &r2);
	for (i = 0; i < n; i++)
	{
		fscanf(Fin, "%i", &x);
		a[i].h = x;
		a[i].f = 0;
	}
	while (m)
	{
		for (k = 0; k < n; k++)
		{
			if (a[k].h > l2 && a[k].h < r2 && a[k].h > l1 && a[k].h < r1)
			{
				if (a[k].h > l2 && a[k].h < r2 && a[k].h > l1 && a[k].h < r1 && hod = 1)
				{
					a[k].f = 1;
					Petya++;
				}
				if (a[k].h > l2 && a[k].h < r2 && a[k].h > l1 && a[k].h < r1 && hod = -1)
				{
					a[k].f = 1;
					Vasya++;
				}
				hod = -hod;
			}
			if (a[k].h > l2 && a[k].h < r2 && (a[k] <l2 || a[k] > r2) && hod = -1)
			{
				a[k].f = 1;
				Vasya++;
				hod = -hod;
			}
			if (a[k].h > l1 && a[k].h < r1 && (a[k] <l1 || a[k] > r1) && hod = 1)
			{
				a[k].f = 1;
				Petya++;
				hod = -hod;
			}
			if (a[k] < l2 && a[k] > r2 && a[k] <l1 && a[k] > r1)
			{
				hod = -hod;
				k--;
			}
		}
	}
	if (Petya = Vasya)
		fprintf(Fout, "Draw");
	if (Petya > Vasya)
		fprintf(Fout, "Petya");
	if (Petya < Vasya)
		fprintf(Fout, "Vasya");
	fclose(Fin);
	fclose(Fout);
	return 0;
}