#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct tagCHESS
{
	int n;
	int ChCl[1000];
} CHESS;

int main(void)
{
	FILE *FIn, *FOut;
	CHESS a;
	int i, h[5];

	if ((FIn = fopen("chess.in", "rt")) == NULL)
		return 0;
	if ((FOut = fopen("chess.out", "wt")) == NULL)
		return 0;
	fscanf(FIn, "%d", &a.n);
	for (i = 0; i < a.n; i++)
		fscanf(FIn, "%d", &a.ChCl[i]);
	fprintf(FOut, "%i %i", 1, 1);
	for (i = 1; (a.ChCl[i - 1] >= i) && (i <= a.n); i++)
		fprintf(FOut, "%i %i\n", i, i);
	fseek(FOut, 0, SEEK_SET);
	fprintf(FOut, "%i\n", i - 1);
	fclose(FIn);
	fclose(FOut);
}