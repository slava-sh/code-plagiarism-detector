#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>

int main(void)
{
	int n, *a, i, max, res = 0, n1, j = 0;
	long long sum = 0, t;
	freopen("merlin.in", "rt", stdin);
	freopen("merlin.out", "wt", stdout);
	scanf("%i", &n);
	a = (int *)malloc(sizeof(int) * n);
	for (i = 0; i < n; i++)
	{
		scanf("%i", &a[i]);
		sum += a[i];
		if (a[i] != a[0])
			j = 1;
	}
	max = 0;
	n1 = n;
	if (j)
		while (1)
		{
			res++;
			t = sum / --n;
			for (i = 0; i < n1; i++)
				if (a[i] > a[max])
					max = i;
			a[max] = -228;
			for (i = 0; i < n1; i++)
				if (a[i] > a[max])
					max = i;
			if (a[max] < t)
				break;
		}
	printf("%i", res);
	return 0;
}