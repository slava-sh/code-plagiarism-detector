#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>


struct Wind{
	int st;
	int fi;
	int v;
};

void main(void)
{
	FILE *F, *P;
	int i, n, k, m, t, p;
	Wind ms[1000];

	F = fopen("dunes.in", "r");
	P = fopen("dunes.out", "w");

	fscanf(F, "%i", &n);
	fscanf(F, "%i", &m);
	
	for (i = 0; i < n; i++)
	{
		ms[i].st = 0;
		ms[i].fi = 0;
		ms[i].v = 0;
	}

	for (i = 0; i < n; i++)
	{
		fscanf(F, "%i", &ms[i].st);
		fscanf(F, "%i", &ms[i].fi);
		fscanf(F, "%i", &ms[i].v);
	}

	for (i = 0; i < m; i++)
	{
		p = 0;
		fscanf(F, "%i", &t);
		for (k = 0; k < n; k++)
		{
			if (t >= ms[k].st && t <= ms[k].fi)
			{
				if ((t - ms[k].st) % 2 == 0)
					p += ms[k].v;
				else
					p -= ms[k].v;
			}
		}
		fprintf(P, "%i\n", p);
	}
	fclose(F);
	fclose(P);
}