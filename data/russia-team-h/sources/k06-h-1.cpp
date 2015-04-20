#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <utility>

#define pb(x) push_back(x)
#define fi first
#define se second
#define mp make_pair
#define FNAME "secure"

using namespace std;

typedef long long ll;

const ll INF = 1e18;
const int MAX_N = 10500;

int n, m;
int clr[MAX_N];
vector < int > g[MAX_N];
vector < int > w[MAX_N];
ll d[MAX_N];
int p[MAX_N];
set < pair < ll, int > > s;

void out(int x) {
	if (clr[x] == 1) {
		cout << x + 1 << " ";
		return;
	}
	out(p[x]);
}

void solve() {
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;++i)
		d[i] = INF;
	for (int i = 0;i < n;++i) {
		scanf("%d", &clr[i]);
		if (clr[i] == 1) {
			d[i] = 0;
			s.insert(mp(0, i));
		}
	}
	for (int i = 0;i < m;++i) {
		int f, t, c;
		scanf("%d%d%d", &f, &t, &c);
		--f; --t;
		g[f].pb(t);
		g[t].pb(f);
		w[f].pb(c);
		w[t].pb(c);
	}
	while (!s.empty()) {
		int x = s.begin() -> se;
		s.erase(s.begin());
		for (int i = 0;i < g[x].size();++i) {
			if (d[g[x][i]] > d[x] + w[x][i]) {
				s.erase(mp(d[g[x][i]], g[x][i]));
				d[g[x][i]] = d[x] + w[x][i];
				p[g[x][i]] = x;
				s.insert(mp(d[g[x][i]], g[x][i]));
			}
		}
	}
	int x = -1;
	for (int i = 0;i < n;++i)
		if (clr[i] == 2 && (x == -1 || d[x] > d[i])) {
			x = i;
		}
	if (x == -1 || d[x] == INF) {
		cout << -1;
		return;
	}
	out(x);
	cout << x + 1 << " " << d[x];
	return;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
