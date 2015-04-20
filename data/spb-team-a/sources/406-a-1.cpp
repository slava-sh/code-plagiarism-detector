#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

int main()
{
	__int64 t, i, c, j;
	char str[5];
	FILE *in, *out;
	in = fopen("abcd.in", "r");
	out = fopen("abcd.out", "w");
	fscanf(in, "%I64d", &t);
	for (i = 0; i < t; i++)
	{
		for (j = 0; j < 5; j++)
			fscanf(in, "%c", &str[j]);
		c = (10 * (str[1] - '0') + str[2] - '0') * (10 * (str[1] - '0') + str[2] - '0') + (10 * (str[3] - '0') + str[4] - '0') * (10 * (str[3] - '0') + str[4] - '0');
		if (c % 7 == 1)
			fprintf(out, "YES\n");
		else
			fprintf(out, "NO\n");
	}
	return 0;
}