#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main( void )
{
	FILE *FIn, *FOut;
	int n, i, ch, a1, a2;

	if ((FIn = fopen("abcd.in", "rt")) == NULL)
		return 0;
	if ((FOut = fopen("abcd.out", "wt")) == NULL)
		return 0;
	fscanf(FIn, "%i", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(FIn, "%i", &ch);
		a1 = (int)(ch / 100);
		a2 = ch % 100;
		if ((a1 * a1 + a2 * a2) % 7 == 1)
			fprintf(FOut, "YES\n");
		else
			fprintf(FOut, "NO\n");
	}
	fclose(FIn);
	fclose(FOut);
	return 0;
}