#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


int main()
{
	__int64 n, i, sum = 0, a[100000] = { NULL }, j, k, c;
	FILE *in, *out;
	in = fopen("merlin.in", "r");
	out = fopen("merlin.out", "w");
	fscanf(in, "%I64d", &n);
	for (i = 0; i < n; i++)
		fscanf(in, "%I64d", &a[i]);
	for (j = 0; j < n - 1; j++)
	{
		for (k = j; k < n; k++)
		{
			if (a[k] < a[j])
			{
				c = a[k];
				a[k] = a[j];
				a[j] = c;
			}
		}
	}
	for (i = 0; i < n; i++)
		sum += a[i];
	i--;
	while (i +1 > 0)
	{
		if (sum > a[i] * (i + 1)|| sum == a[i] * (i + 1))
		{
			fprintf(out, "%I64d", n - i-1);
			return 0;
		}
		i--;
	}
	return 0;
}