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
#include <unordered_map>

using namespace std;

typedef int ll;
typedef long double ld;

typedef pair<ll, ll> pll;

vector<vector<pair<pll, ll> > > g;
vector<vector<ll> > gp;
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
		g[s].push_back(pair<pll, ll>(pll(f, t), i));
		g[f].push_back(pair<pll, ll>(pll(s, t), i));
	}

	gp.resize(m);
	for (ll i = 0; i < n; ++i) {
		for (ll j = 0; j < g[i].size(); ++j) {
			for (ll k = i+1; k < g[i].size(); ++k) {
				if (abs(g[i][j].first.second -g[i][k].first.second)<=d) {
					gp[g[i][j].second].push_back(g[i][k].second);
					gp[g[i][k].second].push_back(g[i][j].second);
				}
			}
		}
	}

	ll T;
	cin >> T;
	for (ll t = 0; t < T; ++t) {
		ll s, f;
		cin >> s >> f;
		--s, --f;

		vector<bool> good(m, false);
		for (ll i = 0; i < g[f].size(); ++i) {
			good[g[f][i].second] = true;
		}

		queue<ll> q;
		vector<ll> d(m, 1e15);
		vector<ll> was(m, false);
		for (ll i = 0; i < g[s].size(); ++i) {
			ll v = g[s][i].second;
			q.push(v);
			d[v] = 0;
			was[v] = true;
		}
		ll res = -1;
		bool flag = true;
		while (!q.empty() && flag) {
			ll crnt = q.front();
			q.pop();
			for (ll i = 0; i < gp[crnt].size(); ++i) {
				ll to = gp[crnt][i];
				if (!was[to]) {
					q.push(to);
					d[to] = d[crnt]+1;
					was[to] = true;
					if (good[to]) {
						res = d[to]+2;
						flag = false;
					}
				}
			}
		}
		cout << res << endl;
	}
	return 0;
}