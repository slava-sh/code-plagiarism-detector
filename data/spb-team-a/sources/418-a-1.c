#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main( void )
{
	FILE *FIn, *FOut;
	int n, i, ch;

	if ((FIn = fopen("abcd.in", "rt")) == NULL)
		return 0;
	if ((FOut = fopen("abcd.out", "wt")) == NULL)
		return 0;
	fscanf(FIn, "%i", &n);
	for (i = 0; i < n; i++)
	{
		fscanf(FIn, "%i", &ch);
		if (((int)(ch / 100) * (int)(ch / 100) + (ch % 100) * (ch % 100)) % 7 == 1)
			fprintf(FOut, "YES\n");
		else
			fprintf(FOut, "NO\n");
	}
	fclose(FIn);
	fclose(FOut);
	return 0;
}