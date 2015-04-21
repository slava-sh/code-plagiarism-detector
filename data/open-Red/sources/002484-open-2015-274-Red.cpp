#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <algorithm>

using namespace std;

const int INF = 1000 * 1000 * 1000 + 7;

int main()
{
	// ios::sync_with_stdio(false);
	// cin.tie(NULL);

	// ifstream cin("");
	// ofstream cout("");
	int n, m, d;
	cin >> n >> m >> d;

	vector<vector<pair<int, int> > > G(n);
	for (int i = 0; i < m; ++i)
	{
		int u, v, w;
		cin >> u >> v >> w;
		--u;
		--v;
		G[u].push_back(make_pair(v, w));
		G[v].push_back(make_pair(u, w));
	}

	int q;
	cin >> q;
	for (int t = 0; t < q; ++t)
	{
		int u, v;
		cin >> u >> v;
		--u;
		--v;
		set<pair<int, int> > used;
		queue<pair<int, int> > Q;
		Q.push(make_pair(u, INF));
		used.insert(make_pair(u, INF));

		map<pair<int, int>, int> D;
		D[make_pair(u, INF)] = 0;

		bool found = false;
		while (!Q.empty())
		{
			pair<int, int> current = Q.front();
			Q.pop();
			int now = current.first, temp = current.second;

			// cout << now << endl;
			if (now == v)
			{
				cout << D[make_pair(now, temp)] << endl;
				found = true;
				break;
			}
			for (int i = 0; i < G[now].size(); ++i)
			{
				int next = G[now][i].first, new_temp = G[now][i].second;
				if (temp != INF && abs(temp - new_temp) > d)
					continue;
				if (used.count(make_pair(next, new_temp)) == 0)
				{
					used.insert(make_pair(next, new_temp));
					D[make_pair(next, new_temp)] = D[make_pair(now, temp)] + 1;
					Q.push(make_pair(next, new_temp));
				}
			}
		}
		if (!found)
			cout << -1 << endl;

	}
}