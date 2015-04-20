/* 10-15-A, A */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	FILE *InF, *OutF;
	__int64 n, t, i;

	InF = fopen("abcd.in", "r");
	if (InF == NULL)
		return 1;

	OutF = fopen("abcd.out", "w");
	if (OutF == NULL)
		return 1;

	fscanf(InF, "%I64d", &n);

	for (i = 0; i < n; i++)
	{
		fscanf(InF, "%I64d", &t);
		if (((t / 100) * (t / 100) + (t % 100) * (t % 100)) % 7 == 1)
			fprintf(OutF, "YES\n");
		else
			fprintf(OutF, "NO\n");
	}

	fclose(InF); 
	fclose(OutF);
	return 0;
}