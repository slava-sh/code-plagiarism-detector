/* 10-15-A, B */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	FILE *InF, *OutF;
	__int64 a, i, j, c, n;
	long long  d = 0, m = 0;

	InF = fopen("conquest.in", "r");
	if (InF == NULL)
		return 1;

	OutF = fopen("conquest.out", "w");
	if (OutF == NULL)
		return 1;

	fscanf(InF, "%I64d", &n);
	for (i = 0; i < n; i++)
	{ 
		fscanf(InF, "%I64d %I64d", &a, &c);
		for (j = 0; j < a; j++)
		{
			if (d > a)
				d++;
			else
			{
				m += c;
				d++;
			}
		}
	}    
	
	fprintf(OutF, "%lli", m);
	fclose(InF);
	fclose(OutF);
	return 0;
}