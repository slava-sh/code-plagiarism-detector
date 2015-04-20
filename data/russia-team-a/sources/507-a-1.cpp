#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
#include <queue>

#define ll long long
#define mp make_pair

#define TASKNAME "binary"

using namespace std;

const int maxn = 1e3+10;

vector<vector<pair<int, int> > > g(maxn);

vector<bool> used(maxn+2);
int n;

void dfs(int v) {
	used[v] = 1;
	for (int i = 0; i < g[v].size(); i++) {
		int to = g[v][i].first;
		if (!used[to]) {
			dfs(to);
		}
	}
}

int ok = 1;
vector<int> col(maxn, -1);


void check() {
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			int e = g[i][j].second;
			int to = g[i][j].first;
			int ncol = col[i];
			if (e == 1)
				ncol = !col[i];
			if (col[to] == -1)
				col[to] = ncol;
			if (col[to] != ncol) {
				ok = 0;
			}
		}
	}
}

const int md = (int)1e9 + 7;

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		if (x > n - i) {
			cout << 0;
			return 0;
		} else if (x > -1) {
			for (int j = 0; j < x; j++) {
				g[j].push_back(mp(i + j, 0));
				g[i + j].push_back(mp(j, 0));
			}
			if (i + x != x) {
				g[x].push_back(mp(i + x, 1));
				g[i + x].push_back(mp(x, 1));
			}
		}
	}

	
	vector<int> comp;

	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			comp.push_back(i);
			dfs(i);
			col[i] = 0;
		}
	}

	check();
	
	if (ok) {
		int sz=comp.size();
		int ans = 1;
		for (int i = 0; i < sz; i++)
		{
			ans <<= 1;
			ans %= md;
		}
		cout << ans;
	} else {
		cout << 0;
	}

	return 0;
}