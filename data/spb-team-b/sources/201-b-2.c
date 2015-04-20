#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(void)
{
	FILE *F;
	FILE *F1;
	int n,i=0,x;
	int a[1000];
	memset(a, 0, sizeof(int) * 1000);
	if ((F = fopen("chess.in", "r")) == NULL)
		return 0;
	if ((F1 = fopen("chess.out", "w")) == NULL)
		return 0;
	fscanf(F, "%d", &n);
	for (x = 0; x < n; x++)
		fscanf(F, "%d", &a[x]);
	for (x = 0; x < a[i++]; x++)
		;
	fprintf(F1, "%d\n", x);
	for (i = 1; i <= x; i++)
		fprintf(F1, "%d %d\n", i, i);
	fclose(F);
	fclose(F1);
	return 0;
}