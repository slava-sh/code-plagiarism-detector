#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void swap(char *a, char *b)
{
	char c[23];
	strcpy(c, a);
	strcpy(a, b);
	strcpy(b, c);
}

int main(void)
{
	char s[3][21][1000];
	int n, i, j;
	freopen("names.in", "rt", stdin);
	freopen("names.out", "wt", stdout);
	scanf("%i", &n);
	for (i = 0; i < n; i++)
		scanf("%s %s %s", s[0][i], s[1][i], s[2][i]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (((strcmp(s[0][i], s[0][j]) == 0) || (strcmp(s[0][i], s[1][j]) == 0)) && j != i)
			{
				swap(s[0][i], s[1][i]);
				swap(s[0][i], s[2][i]);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (strcmp(s[0][i], s[0][j]) > 0)
			{
				swap(s[0][i], s[0][j]);
				swap(s[1][i], s[1][j]);
				swap(s[2][i], s[2][j]);
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%s %s %s\n", s[0][i], s[1][i], s[2][i]);
	return 0;
}