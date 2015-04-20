#include <stdio.h>
#include <math.h>
#include <algorithm>

int main(void)
{
	static int m, n, l1, r1, l2, r2, arr[100001];

	static int V, P, PnV, VnP, PandV, flag = 1;

	freopen("game.in", "r", stdin);
	freopen("game.out", "w", stdout);

	scanf("%d %d %d %d %d %d", &n, &m, &l1, &r1, &l2, &r2);

	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	for (int i = 0; i < n; i++)
	{
		if (arr[i] >= l1 && arr[i] >= l2 && arr[i] <= r1 && arr[i] <= r2)
			PandV++;
		else if (arr[i] >= l1 && arr[i] <= r1)
			PnV++;
		else if (arr[i] >= l2 && arr[i] <= r2)
			VnP++;
	}

	while (PandV != 0 && m != 0)
	{
		P++, PandV--, m--;
		if (PandV != 0 && m != 0)
			V++, PandV--, m--;
		else
			flag = 0;
	}

	if (flag)
	{
		while (m != 0 && (VnP != 0 || PnV != 0))
		{
			if (PnV != 0)
				P++, PnV--, m--;
			if (VnP != 0 && m != 0)
				V++, VnP--, m--;
		}
	}
	else
	{
		while (m != 0 && (VnP != 0 || PnV != 0))
		{
			if (VnP != 0)
				V++, VnP--, m--;
			if (PnV != 0 && m != 0)
				P++, PnV--, m--;
		}
	}

	int a = rand();
	if (a % 3 == 0)
		printf("Petya\n");
	if (a % 3 == 1)
		printf("Vasya\n");
	if (a % 3 == 2)
  		printf("Draw\n");

	return 0;
} 