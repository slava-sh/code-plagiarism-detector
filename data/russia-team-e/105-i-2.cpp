#include <iostream>
#include <algorithm>
using namespace std;

const int maxN = 100100;

bool cmp (int a, int b)
{
	return a > b;
}

int mas0[maxN], mas1[maxN], mas2[maxN];
int ind0, ind1, ind2, d, n, a;
long long sum;

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	scanf("%d%d", &n, &d);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a);
		if (a <= 2 * d)
		{
			mas0[ind0++] = a;
		}
		else if (a > 2 * d && a < 3 * d)
		{
			mas1[ind1++] = a;
		}
		else if (a >= 3 * d)
		{
			mas2[ind2++] = a;
		}
	}

	sort(mas0, mas0 + ind0, cmp);
	sort(mas1, mas1 + ind1, cmp);

	if (ind1 == 0 && ind2 == 0)
	{
		printf("%d", mas0[0]);
		return 0;
	}

	for (int i = 0; i < ind2; i++)
		sum += mas2[i];

	if (ind2 != 0)
		sum -= 2 * (long long)d * (ind2 - 1);

	if (ind1 > 0)
	{
		if (sum != 0)
			sum -= 2 * d;
		sum += mas1[0];
	}
	if (ind1 > 1)
	{
		sum += mas1[1] - 2 * d;
	}

	printf("%lld", sum);

	return 0;
}