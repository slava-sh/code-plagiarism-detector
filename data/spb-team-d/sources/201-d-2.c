#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main(void)
{
	FILE *F;
	FILE *F1;
	long  li, ri;
	long a[200000];
	int n, m, i, xi;
	memset(a, 0, sizeof(long) * 200000);
	if ((F = fopen("dunes.in", "r")) == NULL)
		return 0;
	if ((F1 = fopen("dunes.out", "w")) == NULL)
		return 0;
	fscanf(F, "%d %d", &n, &m);
	for (i = 0; i < n; i++)
	{
		fscanf(F, "%li %li %d", &li, &ri, &xi);
		for (; li <= ri; li+=2)
		{
			a[li] += xi;
			if (li+1<=ri)
			   a[li+1] -= xi;
		}
	}
	for (i = 0; i < m; i++)
	{
		fscanf(F, "%li", &li);
		fprintf(F1, "%li\n", a[li]);
	}
	fclose(F);
	fclose(F1);
	return 0;
}