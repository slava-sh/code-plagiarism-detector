#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#include <stdlib.h> 


int main(void)
{
	int i, j, n, m;
	int *N, *M;
	int a[1000];
	freopen("dunes.in", "rt", stdin);
	freopen("dunes.out", "wt", stdout);
	scanf("%i %i", &n, &m);
	N = (int*)malloc(sizeof(int) * 3 * n);
	for (i = 0; i < n; i++)
		scanf("%i %i %i", &N[3 * i], &N[3 * i + 1], &N[3 * i + 2]);
	M = (int*)malloc(sizeof(int) * m);
	for (i = 0; i < m; i++)
		scanf("%i", &M[i]);
	for (i = 0; i < M[m - 1] + 1; i++)
		a[i] = 0;
	for (i = 0; i < n; i++)
	{
		for (j = N[3 * i]; j <= N[3 * i + 1]; j++)
		{
			if (j % 2 == N[3 * i] % 2)
				a[j] += N[3 * i + 2];
			else
				a[j] -= N[3 * i + 2];
		}
	}
	for (i = 0; i < m; i++)
	{
		printf("%i\n", a[M[i]]);
	}
	free(N);
	free(M);
	return 0;
}
