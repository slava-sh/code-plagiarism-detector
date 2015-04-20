#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int NOD(int a, int b)
{
	int i, nod = 1, min;

	if (a < b)
		min = a;
	else
		min = b;
	for (i = 1; i <= min; i++)
		if (a % i == 0 && b % i == 0)
			nod *= i;
	return nod;
}

int NOK(int a, int b)
{
	return (int)a / NOD(a, b) * b;
}


int Minus(int a, int b)
{
	if (a > b)
		return a - b;
	if (a < b)
		return b - a;
}

int main(void)
{
	FILE *FIn, *FOut;
	int i, j, max, a, b, min, x, y, nod, nok;

	if ((FIn = fopen("gcm.in", "rt")) == NULL)
		return 0;
	if ((FOut = fopen("gcm.out", "wt")) == NULL)
		return 0;
	fscanf(FIn, "%d%d", &a, &b);
	if (a > b)
		max = a, min = a - b;
	else
		max = b, min = b - a;
	nod = NOD(a, b);
	nok = NOK(a, b);
	for (i = 1; i <= max; i++)
		for (j = 1; j <= max; j++)
			if (nod == NOD(i, j) && nok == NOK(i, j) && min > Minus(i, j))
				x = i, y = j;
	if (x > y)
	  fprintf(FOut, "%d %d", x, y);
	else
	  fprintf(FOut, "%d %d", y, x);
	fclose(FIn);
	fclose(FOut);
}