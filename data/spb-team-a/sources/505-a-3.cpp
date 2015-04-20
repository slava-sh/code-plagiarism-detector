#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void main(void)
{
	FILE *F, *P;
	int a, b, code, t, i;

	F = fopen("abcd.in", "r");
	P = fopen("abcd.out", "w");
	
	fscanf(F, "%i", &t);
	
	for (i = 0; i < t; i++)
	{
		fscanf(F, "%i", &code);
		a = code / 100;
		b = code % 100;
		if ((a*a + b*b) % 7 == 1)
			fprintf(P, "YES\n");
		else
			fprintf(P, "NO\n");
	}
	fclose(F);
	fclose(P);
}