#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	__int64 n, k, a[1000] = { NULL }, c[1000] = {NULL}, q = 0, suma = 0, i, sumc = 0;
	FILE *in, *out;
	in = fopen("conquest.in", "r");
	out = fopen("conquest.out", "w");
	fscanf(in, "%I64d", &n);
	k = n;
	for (i = 1; i <= n; i++)
	{
		fscanf(in, "%I64d %I64d", &a[i], &c[i]);
	}
	while (k > 0)
	{
		for (i = 0; i <= k - 1; i++)
		{
			suma += a[i];
		}
		while (a[k] >= suma + q)
		{
			q++;
			sumc += c[k];
			a[k]--;
		}
		k--;
		suma = 0;
	}
	fprintf(out, "%I64d", sumc);
	return 0;
}
