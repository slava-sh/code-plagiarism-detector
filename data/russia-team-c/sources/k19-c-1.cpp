#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int maxn = 300000;

vector <int> road, g[maxn];
int n, a, b, mx[maxn], mn[maxn], ans, d[maxn];

bool dfs(int v, int p) {
	if (v == b) {
		road.push_back(v);
		return true;
	}

	for (int i = 0; i < (int)g[v].size(); i++) {
		if (p != g[v][i] && dfs(g[v][i], v)) {
			road.push_back(v);
			return true;
		}
	}

	return false;
}

void dfs1(int v, int l, int r) {
	d[v] = 1;
	int to;

	for (int i = 0; i < (int)g[v].size(); i++) {
		to = g[v][i];

		if (to == l)
			continue;
		if (to == r)
			continue;

		dfs1(to, - 1, v);

		d[v] = max(d[v], 1 + d[to]);
	}

	return;
} 

int main()
{
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i < n; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	cin >> a >> b;

	dfs(a, - 1);

	for (int i = 0; i < (int)road.size(); i++) {
		if (i == 0)
			dfs1(road[i], - 1, road[i + 1]);
		else if (i == (int)road.size() - 1)
			dfs1(road[i], road[i - 1], - 1);
		else dfs1(road[i], road[i - 1], road[i + 1]);
		mx[i] = max(i + d[road[i]], d[road[0]]);
	}

	reverse(road.begin(), road.end());

	for (int i = 0; i < (int)road.size(); i++)
		mn[i] = max(i + d[road[i]], d[road[0]]);

	for (int i = 0; i < (int)road.size() - 1; i++)
		ans = max(ans, min(mn[i], mx[(int)road.size() - i - 2]));

	cout << ans;
}              