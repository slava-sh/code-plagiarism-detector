/* 10-15-A, B */

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main(void)
{
	FILE *InF, *OutF;
	__int64 n, i, a[1000];

	InF = fopen("chees.in", "r");
	if (InF == NULL)
		return 1;

	OutF = fopen("chees.out", "w");
	if (OutF == NULL)
		return 1;

	fscanf(InF, "%I64d", &n);
	for (i = 0; i < n; i++)
		fscanf(InF, "%I64d", &a[i]);

	for (i = 0; i < a[i]; i++)
		if (a[i] == i)
		{
		    frintf(OutF, "%I64d\n", i);
		    break;
	    }
	for (i = 0; i <= a[i] && i < n; i++)
		if (a[i] == i)
		{
		    frintf(OutF, "%I64d %I64d\n", i + 1);
		    break;
		}

	fclose(InF);
	fclose(OutF);
	return 0;
}