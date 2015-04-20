#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>


int main(void)
{
	int m, n, i, p = 0, v = 0, d = 0, resp = 0, resv = 0, pk = 1, vk = 1;
	long *a, l1, r1, l2, r2;
	freopen("game.in", "rt", stdin);
	freopen("game.out", "wt", stdout);
	scanf("%i %i", &n, &m);
	a = (long *)malloc(sizeof(long) * n);
	scanf("%li %li", &l1, &r1);
	scanf("%li %li", &l2, &r2);
	for (i = 0; i < n; i++)
	{
		scanf("%i", &a[i]);
		if (a[i] <= r1 && a[i] >= l1)
			if (a[i] <= r2 && a[i] >= l2)
				d++;
			else
				p++;
		else
			if (a[i] <= r2 && a[i] >= l2)
				v++;
	}
	for (i = 1; i <= m; i++)
	{
		if (i <= d)
		{
			if (v <= resv)
				vk = 0;
			if (p <= resp)
				pk = 0;
			if (i % 2 == 0)
				resv += 1 * vk;
			else
				resp += 1 * pk;
		}
		else
		{
			if (v <= resv - d / 2)
				vk = 0;
			if (p <= resp - (d - d / 2))
				pk = 0;
			if ((i + d % 2) % 2 == 0)
				resv += 1 * vk;
			else
				resp += 1 * pk;
		}
	}
	if (resp > resv)
		printf("Petya");
	else if (resv > resp)
		printf("Vasya");
	else
		printf("Draw");
	free(a);
	return 0;
}
