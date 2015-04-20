#include <stdio.h>

int main(void)
{
	int t, A, m;
	FILE *in, *out;

	in = fopen("abcd.in", "rt");
	out = fopen("abcd.out", "wt");

	fscanf(in, "%d", &t);

	for (m = 0; m < t; m++)
	{
		fscanf(in, "%d", &A);
		if (((A / 100) * (A / 100) + (A % 100) * (A % 100)) % 7 == 1)
			fprintf(out, "YES\n");
		else
			fprintf(out, "NO\n");
	}
	return 0;
}