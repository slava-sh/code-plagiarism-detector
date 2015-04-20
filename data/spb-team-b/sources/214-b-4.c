/* 10-15-A, B */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	FILE *InF, *OutF;
	__int64 n, i, a[1000];

	InF = fopen("chess.in", "r");
	if (InF == NULL)
		return 1;

	OutF = fopen("chess.out", "w");
	if (OutF == NULL)
		return 1;

	fscanf(InF, "%I64d", &n);

	for (i = 0; i < n; i++)
		fscanf(InF, "%I64d", &a[i]);
	
	for (i = 0; i + 1 < n; i++)
		if (a[i] - 1 == i)
		{
		  fprintf(OutF, "%I64d\n", i + 1);
		  break;
		}
    
	i = 0;
	while ((a[i] - 1) != i)
		fprintf(OutF, "%I64d %I64d\n", i + 1, i + 1), i++;
	fprintf(OutF, "%I64d %I64d\n", i + 1, i + 1);

    fclose(InF);
	fclose(OutF);
	return 0;
}