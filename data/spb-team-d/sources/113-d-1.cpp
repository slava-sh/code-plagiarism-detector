// Задача F
#include <stdio.h>
#include <math.h>

typedef struct
{
	__int64 l, r;
	int x;
} poryv;


int main( void )
{
	int n,m;
	poryv poryvy[1000];
	int i, j;
	FILE *IN, *OUT;

	if ((IN = fopen("dunes.in", "rt")) == NULL)
		return 1;
	if ((OUT = fopen("dunes.out", "wt")) == NULL)
	{
		fclose(IN);
		return 1;
	}
	
	fscanf(IN, "%i", &n);
	fscanf(IN, "%i", &m);
	for (i = 0; i < n; i++)
	{
		fscanf(IN, "%I64d", &poryvy[i].l);
		fscanf(IN, "%I64d", &poryvy[i].r);
		fscanf(IN, "%i", &poryvy[i].x);
	}
	for (i = 0; i <= m; i++)
	{
		__int64 uch;
		int vys = 0;

		fscanf(IN, "%I64d", &uch);
		for (j = 0; j < n; j++)
		{
			if (poryvy[j].l <= uch && poryvy[j].r >= uch)
				if ((uch - poryvy[j].l) % 2)
					vys -= poryvy[j].x;
				else
					vys += poryvy[j].x;
		}
		fprintf(OUT, "%i\n", vys);
	}

	fclose(IN);
	fclose(OUT);
	return 0;
}










