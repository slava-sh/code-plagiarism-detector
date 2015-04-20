#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char *a, char *b)
{
	char c[21];
	strcpy(c, a);
	strcpy(a, b);
	strcpy(b, c);
}

int main(void)
{
	char s0[21][1000];
	char s1[21][1000];
	char s2[21][1000];
	int n, i, j;
	freopen("names.in", "rt", stdin);
	freopen("names.out", "wt", stdout);
	scanf("%i", &n);
	for (i = 0; i < n; i++)
		scanf("%s %s %s", s0[i], s1[i], s2[i]);
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			if (((strcmp(s0[i], s0[j]) == 0) || (strcmp(s0[i], s1[j]) == 0)) && j != i)
			{
				swap(s0[i], s1[i]);
				swap(s0[i], s2[i]);
			}
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = i; j < n; j++)
		{
			if (strcmp(s0[i], s0[j]) > 0)
			{
				swap(s0[i], s0[j]);
				swap(s1[i], s1[j]);
				swap(s2[i], s2[j]);
			}
		}
	}
	for (i = 0; i < n; i++)
		printf("%s %s %s\n", s0[i], s1[i], s2[i]);
	return 0;
}