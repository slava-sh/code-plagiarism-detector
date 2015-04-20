#include <stdio.h>
#include <math.h>
#include <algorithm>

int arr[200000], p;

int P(int n)
{
	int sum = 0;
	for (int i = 0; i < p; i++)
	{
		if (arr[n + i] > i + 1)
			return -2;
		else
			sum += i + 1 - arr[n + i];
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
		scanf("%d", &arr[i]);

	for (int i = 0; i <= n - p; i++)
	{
		if (arr[i] == 1 || arr[i] == 0)
		{
			long long po = P(i);
			if ((po < sum || sum == -1) && po != -2)
				sum = po;
		}
	}

	printf("%I64d", sum);

	return 0;
} 