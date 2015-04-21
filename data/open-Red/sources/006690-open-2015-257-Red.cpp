#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <cstdio>
#include <memory.h>
#include <iostream>
#include <cmath>
#include <queue>

#pragma comment(linker, "/STACK:64000000")

using namespace std;

#define mp make_pair
#define pi M_PI

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pldld;

const int infi = (int)1e9 + 7;
const ll infl = (ll)1e18 + 7;
const ld eps = (ld)(1e-8);
const int it = 250000;

struct edge{
	int t, v, i, l, r, m;
	edge () {}
	edge(int t, int v, int m) : t(t), v(v), m(m), i(0), l(-1), r(-1) {}
};
bool operator < (edge a, edge b) {
	if (a.t != b.t) {
		return a.t < b.t;
	}
	if (a.v != b.v) {
		return a.v < b.v;
	}
	return a.m < b.m;
}
bool operator ==(edge a, edge b) {
	if (a.t == b.t && a.v == b.v && a.m == b.m) {
		return 1;
	}
	return 0;
}
vector <vector <edge> > g;
int bin(int k, edge a) {
	int l = 0, r = (int)g[k].size() - 1;
	while (l <= r) {
		int m = (l + r) >> 1;
		if (g[k][m] == a) {
			return m;
		}
		if (g[k][m] < a) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
}
vector <int> dist[100500];
pii och[1000500];
void del(int i, int j) {
	int l = g[i][j].l, r = g[i][j].r;
	if (r != -1) {
		g[i][r].l = l;
	}
	if (l != -1) {
		g[i][l].r = r;
	}
	//g[i][j].r = g[i][j].l =-1;
	return;
}


int main(){
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	int n, m, d;
	cin >> n >> m >> d;
	g.resize(n);
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		--a, --b;
		g[a].push_back(edge(t, b, i * 2));
		g[b].push_back(edge(t, a, i * 2 + 1));
	}
	for (int i = 0; i < n; ++i) {
		if (!g[i].empty()) {
			sort(g[i].begin(), g[i].end());
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < (int)g[i].size(); ++j) {
			g[i][j].i = bin(g[i][j].v, edge(g[i][j].t, i, g[i][j].m ^ 1));
		}
	}
	for (int i = 0; i < n; ++i) {
		dist[i].resize((int)(g[i].size()), 0);
	}
	int q;
	cin >> q;
	for (;q; --q) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < (int)g[i].size(); ++j) {
				dist[i][j] = infi;
				if (j) {
					g[i][j].l = j - 1;
				}
				else {
					g[i][j].l = -1;
				}
				if (j != (int)g[i].size() -1) {
					g[i][j].r = j + 1;
				}
				else {
					g[i][j].r = -1;
				}
			}
		}
		int l = 0, r = 0;
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		for (int i = 0; i < (int)g[a].size(); ++i) {
			och[r] = mp(g[a][i].v, g[a][i].i);
			r++;
			dist[g[a][i].v][g[a][i].i] = 1;
			del(a, i);
		}
		int e = 0;
		while (e < it && l < r) {
			++e;
			int v = och[l].first, i = och[l].second;
			for (int j = g[v][i].l, k = 0; j != -1 && g[v][i].t - g[v][j].t <= d && k <(int)g[v].size(); ++k, j = g[v][j].l) {
				if (dist[g[v][j].v][g[v][j].i] < infi) {
					continue;
				}
				och[r] = mp(g[v][j].v, g[v][j].i);
				r++;
				dist[g[v][j].v][g[v][j].i] = dist[v][i] + 1;
				del(v, j);
			}
			for (int j = g[v][i].r, k = 0; j != -1 && g[v][j].t - g[v][i].t <= d && k < (int)g[v].size(); j = g[v][j].r, ++k) {
				if (dist[g[v][j].v][g[v][j].i] < infi) {
					continue;
				}
				och[r] = mp(g[v][j].v, g[v][j].i);
				r++;
				dist[g[v][j].v][g[v][j].i] = dist[v][i] + 1;
				del(v, j);
			}
			if (dist[g[v][i].v][g[v][i].i] >= infi) {
				och[r] = mp(g[v][i].v, g[v][i].i);
				r++;
				dist[g[v][i].v][g[v][i].i] = dist[v][i] + 1;
				del(v, i);
			}
			++l;
		}
		int ans = infi;
		for (int i = 0; i < (int)g[b].size(); ++i) {
			ans = min(ans, dist[b][i]);
		}
		if (ans >= infi) {
			cout << -1 << endl;
		}
		else {
			cout << ans << endl;
		}
	}

	return 0;
}