#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


long long ans;

void recurs(int N, int level, long long now)
{
	if (level == 1)
	{
		ans = min(ans, now * (N / 2 + N % 2));
		return;
	}
	int k = 2;
	while (k <= floor(sqrt(1.0 * N)))
	{
		if (N % k == 0)
		{
			long long lev_ppl = (N / k) / 2 + (N / k) % 2;
			recurs(k, level - 1, now * lev_ppl);
			if (k * k != N)
			{ 
				lev_ppl = k / 2 + k % 2;
				recurs(N / k, level - 1, now * lev_ppl);
			}
		}
		k++;
	}
}

int main()
{
	long long N;
	int K;
	cin >> N >> K;
	ans = N;
	recurs(N, K, 1);
	cout << ans << endl;
	return 0;
}