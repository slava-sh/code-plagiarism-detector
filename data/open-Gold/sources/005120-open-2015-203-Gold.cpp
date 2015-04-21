#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstdio>

using namespace std;

typedef unsigned long long ll;

int main()
{
	//freopen("input.txt", "r", stdin);
	int N, K, C, D;
	cin >> N >> K >> C >> D;
	ll cost = 0;
	vector<pair<int, int> > vis(N);
	multiset<int> spend;
	for (int i = 0; i < N; i++)
	{
		cin >> vis[i].first >> vis[i].second;
		if (i != 0)
			spend.insert(-(vis[i].first - vis[i - 1].second));
	}
	cost = (vis[N - 1].second - vis[0].first) * D;
	int otr = 1;
	for (int i = 0; i < K - 1; i++)
	{
		if (spend.empty())
		{
			cout << cost << endl;
			return 0;
		}
		else
		{
			ll l = *spend.begin();
			l *= -1;
			spend.erase(spend.begin());
			cost -= l * D;
		}
	}
	while (true)
	{
		ll summ = 0;
		for (int i = 0; i < K; i++)
		{
			if (spend.empty())
			{
				if (summ * D > C)
				{
					cost -= summ * D;
					cost += C;
				}
				cout << cost << endl;
				return 0;
			}
			else
			{
				ll l = *spend.begin();
				l *= -1;
				spend.erase(spend.begin());
				summ += l;
			}
		}
		if (summ * D > C)
		{
			cost -= summ * D;
			cost += C;
		}
		else
		{
			cout << cost << endl;
			return 0;
		}
	}
	return 0;
}