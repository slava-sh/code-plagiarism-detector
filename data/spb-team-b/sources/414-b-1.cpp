#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	FILE *in, *out;
	int n, m, count = 0;
	static int Fields[1000][1000];

	if ((in = fopen("chess.in", "r")) == NULL)
		return -1;
	if ((out = fopen("chess.out", "w")) == NULL)
		return -1;
	fscanf(in, "%i", &n);
	for (int i = 0; i < n; i++)
	{
		fscanf(in, "%i", &m);
		for (int j = 0; j < m; j++)
		{
			if (i == j)
				count++;
			Fields[i][j] = 1;
		}
	}
	fprintf(out, "%i\n", count);
	for (int i = 0; i < count; i++)
		fprintf(out, "%i %i\n", i + 1, i + 1);
	fclose(in);
	fclose(out);
	return 0;
}