#include <stdio.h>

typedef struct tagWIND
{
	int l, r, x;
} WIND;

WIND setWind(int l, int r, int x)
{
	WIND wnd;
	wnd.l = l, wnd.r = r, wnd.x = x;
	return wnd;
}

int main(void)
{
	FILE *file_in, *file_out;
	WIND wnd[1000];
	int x, n, m, i, j, q, sum, l, r;
	file_in = fopen("dunes.in", "rt");
	file_out = fopen("dunes.out", "wt");
	
	fscanf(file_in, "%d%d", &n, &m);

	for (i = 0; i < n; i++)
	{
		fscanf(file_in, "%d%d%d", &l, &r, &x);
		wnd[i] = setWind(l - 1, r - 1, x);
	}

	for (i = 0; i < m; i++)
	{
		fscanf(file_in, "%d", &q);
		q--;
		sum = 0;
		for (j = 0; j < 1000; j++)
			if (q >= wnd[j].l && q <= wnd[j].r)
				if ((q - l) % 2)
					sum += wnd[j].x;
				else
					sum -= wnd[j].x;
		fprintf(file_out, "%d\n", sum);
	}

	return 0;
}