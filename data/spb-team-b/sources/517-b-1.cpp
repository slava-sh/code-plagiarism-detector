#include <stdio.h>
#include <conio.h>

#define MAX_ARRAY_SIZE 1001

int main(void)
{
	int i, n, a[MAX_ARRAY_SIZE], count = 0;
	FILE *in, *out;

	in = fopen("chess.in", "rt");
	out = fopen("chess.out", "wt");

	fscanf(in, "%i", &n);

	for (i = 0; i < n; i++)
		fscanf(in, "%i", &a[i]);

	for (i = 0; i < n; i++)
		if (i <= a[i])
		    count++;
	fprintf(out, "%i\n", count);

	for (i = 0; i < n; i++)
		if (i <= a[i])
			fprintf(out, "%i %i\n", i + 1, i + 1);
	return 0;
}