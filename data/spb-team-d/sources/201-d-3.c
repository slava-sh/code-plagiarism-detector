#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *F;
	FILE *F1;
	long  current, count = 0 ;
	long x[1000][3];
	int n, m, i, j;
	memset(x, 0, sizeof(long) * 3000);
	if ((F = fopen("dunes.in", "r")) == NULL)
		return 0;
	if ((F1 = fopen("dunes.out", "w")) == NULL)
		return 0;
	fscanf(F, "%d %d", &n, &m);
	for (i = 0; i < n; i++)
	  fscanf(F, "%li %li %li", &x[i][0], &x[i][1], &x[i][2]);
	for (i = 0; i < m; i++)
	{
		fscanf(F, "%li", &current);
		for (j = 0; j < n; j++)
			if (current >= x[j][0] && current <= x[j][1])
			{
			if (((current - x[j][0]) % 2) == 0)
				count += x[j][2];
			else
				count -= x[j][2];
			}
		fprintf(F1, "%li\n", count);
		count = 0;
	}
	fclose(F);
	fclose(F1);
	return 0;
}