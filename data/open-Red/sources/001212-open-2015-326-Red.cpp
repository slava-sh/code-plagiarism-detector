#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef int ll;
typedef long double ld;

typedef pair<ll, ll> pll;

vector<vector<pll> > g;
ll n, m, d;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m >> d;

	g.resize(n);

	for (ll i = 0; i < m; ++i) {
		ll s, f, t;
		cin >> s >> f >> t;
		--s, --f;
		g[s].push_back(pll(f, t));
		g[f].push_back(pll(s, t));
	}

	ll T;
	cin >> T;
	for (ll t = 0; t < T; ++t) {
		ll s, f;
		cin >> s >> f;
		--s, --f;
		queue<pll> q;
		vector<map<ll, bool> > was(n);
		vector<map<ll, ll> > dist(n);
		q.push(pll(s, -2e9));
		bool flag = true;

		ll res = 2e9;
		while (!q.empty() && flag) {
			pll c = q.front();
			q.pop();
			for (ll i = 0; i < g[c.first].size(); ++i) {
				pll to = g[c.first][i];
				if (!was[to.first][to.second] && (abs(to.second-c.second) <= d || c.second == -2e9)) {
					was[to.first][to.second] = true;
					dist[to.first][to.second] = dist[c.first][c.second]+1;
					q.push(to);
					if (to.first == f) {
						flag = false;
						res = dist[to.first][to.second];
						break;
					}
				}
			}
		}
		if (res != 2e9) {
			cout << res << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}