#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void GetDigits(int Number, int *A, int *B, int *C, int *D)
{
	*D = Number % 10;
	Number /= 10;
	*C = Number % 10;
	Number /= 10;
	*B = Number % 10;
	Number /= 10;
	*A = Number % 10;
	Number /= 10;
}

int main(void)
{
	FILE *in, *out;
	int n, a, b, c, d;
	char *Str[4];
	if ((in = fopen("abcd.in", "r")) == NULL)
		return -1;
	if ((out = fopen("abcd.out", "w")) == NULL)
		return -1;
	fscanf(in, "%i\n", &n);

	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%d\n", &a);
		GetDigits(a, &a, &b, &c, &d);
		int ab = a * 10 + b, cd = c * 10 + d;
		if ((ab * ab + cd * cd) % 7 == 1)
			fprintf(out, "%s\n", "YES");
		else
			fprintf(out, "%s\n", "NO");
	}
	fclose(in);
	fclose(out);
	return 0;
}