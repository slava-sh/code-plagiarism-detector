

#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;

long long gcd(long long a, long long b)
{
	while (a != 0 && b != 0)
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
	cin >> a >> b;

	long long g = gcd(a, b);
	long long ansa = min(a, b), ansb = max(a, b), ans = ansb - ansa;
	long long m = a * b;
	long long to = sqrt(m) + 10000;
	vector<long long> divisorsa;
	vector<long long> divisorsb;
	vector<long long> divisors;


	for (long long i = 1; i * i  <= a; ++i)
	{
		if (a % i == 0)
		{
			divisorsa.push_back(i);
			divisorsa.push_back(a / i);
		}
	}

	for (int i = 1; i * i <= b; ++i)
	{
		if (b % i == 0)
		{
			divisorsb.push_back(i);
			divisorsb.push_back(b / i);
		}
	}


	for (int i = 0; i < divisorsa.size(); i++)
		for (int j = 0; j < divisorsb.size(); j++)
			divisors.push_back(divisorsa[i] * divisorsb[j]);


	for (int i = 0; i < divisors.size(); i++)
	{
		long long x = divisors[i];
		long long y = m / x;
		if (x <= y && gcd(x, y) == g)
		{
			if (y - x < ans)
			{
				ansa = x;
				ansb = y;
				ans = y - x;
			}
		}
	}


	cout << ansa << ' ' << ansb;

	return 0;

}