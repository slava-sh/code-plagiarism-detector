#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void main(void)
{
	int m, n, a, i, j, p;
	int k[3][1000];
	freopen("dunes.in", "rt", stdin);
	freopen("dunes.out", "wt", stdout);
	scanf("%i %i", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%i %i %i", &k[0][i], &k[1][i], &k[2][i]);
  
	for (i = 0; i < m; i++)
	{
		scanf("%i", &a);
		p = a;
		for (j = 0; j < n; j++)
		{
			if (p <= k[1][j] && p >= k[0][j])
			{
				if ((p - k[0][j]) % 2 == 0)
					a += k[2][j];
				else
					a -= k[2][j];
			}
		}
		printf("%i\n", a - p);
	}
}