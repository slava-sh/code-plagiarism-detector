#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

int main()
{
	long long N, K;
	cin >> N >> K;
	multiset<int> primes;
	while (N % 2 == 0)
	{
		if (K == 1)
			break;
		N /= 2;
		K--;
	}
	if (K == 1)
	{
		cout << N / 2 + N % 2 << endl;
		return 0;
	}
	if (N == 1)
	{
		cout << 1 << endl;
		return 0;
	}
	int k = 3;
	while (N != 1)
	{
		while (N % k == 0)
		{
			primes.insert(k);
			N /= k;
		}
		k++;
	}
	int left = primes.size() - K;
	while (left > 0)
	{
		int a = *primes.begin();
		primes.erase(primes.begin());
		int b = *primes.begin();
		primes.erase(primes.begin());
		primes.insert(a * b);
		left--;
	}
	long long ans = 1;
	int op = primes.size();
	for (size_t i = 0; i < op; i++)
	{
		int a = *primes.begin();
		primes.erase(primes.begin());
		ans *= (a / 2 + a % 2);
	}
	cout << ans << endl;
	return 0;
}