#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <stdio.h>

void main(void)
{
	FILE *F, *P;
	int i, n, k;

	F = fopen("chess.in", "r");
	P = fopen("chess.out", "w");

	fscanf(F, "%i", &n);

	for (i = 1; i <= n; i++)
	{
		fscanf(F, "%i", &k);
		if (k < i)
			break;
	}
	fprintf(P, "%i\n", i - 1);
	for (k = 1; k < i; k++)
		fprintf(P, "%i %i\n", k, k);
	fclose(F);
	fclose(P);
}