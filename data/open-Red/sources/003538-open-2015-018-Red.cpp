#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <map>
#include <queue>

using namespace std;

const int INF = (int)1e9 + 1;

vector<int> used;
vector<vector<pair<int, int> > > gr;
vector<vector<int> > grT;
vector<int> level;
queue<pair<int, pair<int, int> > > que;
int n, m, d;

void dfs() {
	while (!que.empty()) {
		int v = que.front().first;
		int t = que.front().second.first;
		int pos = que.front().second.second;
		que.pop();
		if (v == 4) {
			v = 4;
		}
		int j = upper_bound(grT[v].begin(), grT[v].end(), t - d - 1) - grT[v].begin();
		for (int i = j; i < (int)grT[v].size() && grT[v][i] <= t + d; ++i) {
			if (!used[gr[v][i].second]) {
				used[gr[v][i].second] = true;
				level[gr[v][i].first] = min(level[gr[v][i].first], pos + 1);
				que.push(make_pair(gr[v][i].first, make_pair(grT[v][i], pos + 1)));
			}
		}
	}
}

int main() {
	
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> m >> d;
	gr.resize(n);
	grT.resize(n);
	used.resize(2 * m);
	level.resize(n);
	int num = 0;
	for (int i = 0; i < m; ++i) {
		int a, b, c;
		cin >> a >> b >> c;
		a--;
		b--;
		gr[a].push_back(make_pair(b, num++));
		gr[b].push_back(make_pair(a, num++));
		grT[a].push_back(c);
		grT[b].push_back(c);
	}

	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int a, b;
		cin >> a >> b;
		a--;
		b--;
		for (int j = 0; j < 2 * m; ++j) {
			used[j] = false;
		}
		for (int j = 0; j < n; ++j) {
			level[j] = INF;
		}
		level[a] = 0;
		for (int j = 0; j < (int)gr[a].size(); ++j) {
			que.push(make_pair(gr[a][j].first, make_pair(grT[a][j], 1)));
			used[gr[a][j].second] = true;
			level[gr[a][j].first] = 1;
		}

		dfs();

		if (level[b] == INF) {
			cout << -1 << endl;
		} else {
			cout << level[b] << endl;
		}
	}

	return 0;
}