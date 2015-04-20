#include <stdio.h>
#include <conio.h>

#define MAX_ARRAY_SIZE 1001

int main(void)
{
	int i, n, a[MAX_ARRAY_SIZE], count = 0;
	FILE *in, *out;

	in = fopen("chess.in", "rt");
	out = fopen("chess.out", "wt");

	fscanf(in, "%d", &n);

	for (i = 0; i < n; i++)
		fscanf(in, "%d", &a[i]);

	for (i = 1; i <= n; i++)
		if (i <= a[i - 1])
		    count++;
	fprintf(out, "%d\n", count);

	for (i = 0; i < n; i++)
		if (i <= a[i])
			fprintf(out, "%d %d\n", i + 1, i + 1);
	return 0;
}