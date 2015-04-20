#include <stdio.h>
#include <math.h>
#include <algorithm>

int main(void)
{
	int k[1000][3], nw, num, q[1000], ans[1000], i;
	
    freopen("dunes.in", "r", stdin);
	freopen("dunes.out", "w", stdout);

	scanf("%i %i", &nw, &num);

	for (i = 0; i < nw; i++)
	{
		scanf("%i %i %i", &k[i][0], &k[i][1], &k[i][2]);
	}

	for (i = 0; i < num; i++)
	{
		scanf("%i", &q[i]);
		ans[i] = 0;
	}

	for (i = 0; i < nw; i++)
	{
		for (int j = 0; j < num; j++)
		{
			if (q[j] < k[i][0] || q[j] > k[i][1])
				continue;
			else
			{
				if ((q[j] - k[i][0] + 1) % 2 == 0)
					ans[j] -= k[i][2];
				else
					ans[j] += k[i][2];
			}
		}
	}

	for (i = 0; i < num; i++)
	{
		printf("%i\n", ans[i]);
	}

	return 0;
}	