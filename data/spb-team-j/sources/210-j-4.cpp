#include <stdio.h>
#include <math.h>
#include <algorithm>

int arr[200001], p, V, po[200001];

int P()
{
	int sum = 0;
	for (int i = 0; i < p; i++)
	{
		if (arr[V + i] > i + 1)
		{
			V += i;
            return -2;
		}
		else
			sum += i + 1 - arr[V + i];
	}
	return sum;
}

int main(void)
{
	int n;
	long long sum = -1;
    
    freopen("seq.in", "r", stdin);
	freopen("seq.out", "w", stdout);

	scanf("%d%d", &n, &p);

	for (int i = 0; i < n; i++)
	{
		po[i] = -2;
        scanf("%d", &arr[i]);
	}



	for (V = 0; V <= n - p; V++)
	{
		if (arr[V] == 1 || arr[V] == 0)
		{
			if (V != 0 && po[V - 1] != -2)
				if (arr[V + p - 1] <= p)
				{
				    po[V] = po[V - 1] - arr[V + p - 1] + 1;
					if (arr[V - 1] == 0)
						po[V]--;
				}
                else
					po[V] = -2;
			else
			{
				po[V] = P();
			}
		}
		if ((po[V] < sum || sum == -1) && po[V] != -2)
			sum = po[V];
	}

	printf("%I64d", sum);

	return 0;
} 