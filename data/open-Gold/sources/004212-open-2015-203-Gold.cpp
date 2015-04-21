#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef unsigned long long ll;

int main()
{
	int N, K, C, D;
	cin >> N >> K >> C >> D;
	ll cost = 0;
	vector<pair<int, int> > vis(N);
	multiset<int> spend;
	for (int i = 0; i < N; i++)
	{
		cin >> vis[i].first >> vis[i].second;
		cost += (vis[i].second - vis[i].first) * D;
		if (i != 0)
			spend.insert(vis[i].first - vis[i - 1].second);
	}
	ll lamps = N / K + ((N % K) > 0);
	lamps--;
	cost += lamps * C;
	if (N % K > 0 && N > K)
	{
		ll sum = 0;
		for (int i = 0; i < N % K; i++)
		{
			sum += *spend.begin();
			spend.erase(spend.begin());
		}
		if (sum * D < C)
		{
			cost -= C;
			cost += sum * D;
			lamps--;
		}
		else
		{
			cout << cost << endl;
			return 0;
		}
	}
	for (int i = 0; i < lamps; i++)
	{
		ll sum = 0;
		for (int q = 0; q < K; q++)
		{
			sum += *spend.begin();
			spend.erase(spend.begin());
		}
		if (sum * D < C)
		{
			cost -= C;
			cost += sum * D;
			lamps--;
		}
		else
		{
			cout << cost << endl;
			return 0;
		}
	}
	cout << cost << endl;
	return 0;
}