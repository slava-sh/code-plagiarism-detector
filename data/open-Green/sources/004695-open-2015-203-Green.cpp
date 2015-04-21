#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	long long N, K;
	cin >> N >> K;
	vector<int> primes;
	while (N % 2 == 0)
	{
		N /= 2;
		K--;
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
			primes.push_back(k);
			N /= k;
		}
		k++;
	}
	int left = primes.size() - K;
	while (left > 0)
	{
		vector<int> help;
		for (size_t i = 0; i < primes.size() - 1; i += 2)
		{
			help.push_back(primes[i] * primes[i + 1]);
			left--;
			bool d = 0;
			if (left == 0)
			{
				d = 1;
				for (int q = i + 2; q < primes.size(); q++)
				{
					help.push_back(primes[q]);
				}
			}
			if (d)
				break;
		}
		primes.clear();
		primes = help;
		help.clear();
		sort(primes.begin(), primes.end());
	}
	long long ans = 1;
	for (size_t i = 0; i < primes.size(); i++)
		ans *= (primes[i] / 2 + primes[i] % 2);
	cout << ans << endl;
	return 0;
}