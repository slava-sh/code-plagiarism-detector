#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 1001

typedef struct tagDUNE
{
	long long height;
	long long number;
} DUNE;

typedef struct tagWINDBLOW
{
	long long L, R;
	int power;
} WINDBLOW;

int main( void )
{
	int n, m, x, i, k;
	DUNE Dunes[MAX_ARRAY_SIZE];
	WINDBLOW Wind[MAX_ARRAY_SIZE];
	long long l, r, j, tmp;
	FILE *in, *out;

	in = fopen("dunes.in", "rt");
	out = fopen("dunes.out", "wt");

	fscanf(in, "%d%d", &n, &m);

    for (i = 0; i < m; i++)
	    Dunes[i].height = 0;

	for (i = 0; i < n; i++)
	{
		fscanf(in, "%I64d %I64d %d", &l, &r, &x);
		Wind[i].L = l;
		Wind[i].R = r;
		Wind[i].power = x;
	}

	for (i = 0; i < m; i++)
	{
		fscanf(in, "%I64d", &tmp);
		Dunes[i].number = tmp;
	}

	for (i = 0; i < n; i++)
	{
		if (Wind[i].L >= Dunes[0].number)
		{
			k = Wind[i].L - 1;
			while (Wind[i].R >= Dunes[k].number)
			{
				Dunes[k].height += ((Wind[i].L - Dunes[k].number) & 1) ? -Wind[i].power : Wind[i].power;
				k++;
			}
		}
	}

	for (i = 0; i < m; i++)
		fprintf(out, "%I64d\n", Dunes[i].height);

	fclose(in);
	fclose(out);

	return 0;
}