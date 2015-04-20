#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

typedef struct tagWIND
{
	int l, r, x;
} WIND;

int main(void)
{
	FILE *FIn, *FOut;
	int n, m, i, j, numuch, vs, Uch;
	WIND Wind[1000];

	if ((FIn = fopen("dunes.in", "rt")) == NULL)
		return 0;
	if ((FOut = fopen("dunes.out", "wt")) == NULL)
		return 0;
	fscanf(FIn, "%d%d", &n, &m);
	for (i = 0; i < n; i++)
		fscanf(FIn, "%d%d%d", &Wind[i].l, &Wind[i].r, &Wind[i].x);
	for (i = 0; i < m; i++)
	{
		vs = 0;
		fscanf(FIn, "%d", &Uch);
		for (j = 0; j < n; j++)
		{
			if (Uch >= Wind[j].l && Uch <= Wind[j].r)
				if ((Uch - Wind[j].l) % 2 == 0)
					vs += Wind[j].x;
				else
					vs -= Wind[j].x;
		}
		fprintf(FOut, "%i\n", vs);
	}
	fclose(FIn);
	fclose(FOut);
	return 0;
}