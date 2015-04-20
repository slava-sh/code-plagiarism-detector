#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

long long gcd(long long a, long long b)
{
	while (a & b)
	{
		if (a > b) a %= b;
		else b %= a;
	}
	return a + b;
}

int main()
{
	freopen("gcm.in", "r", stdin);
	freopen("gcm.out", "w", stdout);

	long long a, b;
	scanf("%ll %ll", &a, &b);

	long long g = gcd(a, b);
	long long ansa = min(a, b), ansb = max(a, b), ans = ansb - ansa;
	long long m = a * b;
	long long to = sqrt(m) + 1000;


	for (long long x = min(a, b); x < to; ++x)
	{
		if (m % x == 0)
		{
			long long y = a * b / x;
			if (gcd(x, y) == g && x <= y)
			{
				if (y - x < ans)
				{
					ansa = x;
					ansb = y;
					ans = y - x;
				}
			}
		}
	}

	printf("ll ll", ansa, ansb);
	return 0;

}