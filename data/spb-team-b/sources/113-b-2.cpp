// Задача B

#include <stdio.h>

int main( void )
{
	int n;
	int mass[1000];
	int i;
	int answer = 0;
	FILE *IN, *OUT;

	if ((IN = fopen("chess.in", "rt")) == NULL)
		return 1;
	if ((OUT = fopen("chess.out", "wt")) == NULL)
	{
		fclose(IN);
		return 1;
	}

	fscanf(IN, "%i", &n);
	for (i = 0; i < n; i++)
		fscanf(IN, "%i", &mass[i]);
	for (i = 0; i < n; i++)
		if (mass[i] >= i+1)
			answer++;
	fprintf(OUT, "%i\n", answer);
	for (i = 0; i < n; i++)
		if (mass[i] >= i+1)
			fprintf(OUT, "%i %i\n", i+1, i+1);

	fclose(IN);
	fclose(OUT);
	return 0;
}