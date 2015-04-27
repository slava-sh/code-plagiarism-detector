#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <set>
#include <iostream>
#include <cassert>
#include <algorithm>

 using namespace std;

#define foreach(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int N = 2000 + 10;
const int MOD = 1e9 + 7;

int n, m;
int top, tot, totColor;
int cnt[N];
int low[N], dfn[N], instack[N], stack[N], color[N];
vector<int> adj1[N];
vector<int> adj2[N];

int tarjan(int u, int f)
{
	low[u] = dfn[u] = tot ++;
	stack[++ top] = u; instack[u] = true;
	foreach(it, adj1[u]) {
		int v = *it;
		if (v == f) continue;
		if (dfn[v] < 0) {
			low[u] = min(low[u], tarjan(v, u));
		} else if (instack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		int v;
		do {
			v = stack[top --];
			color[v] = totColor;
			instack[v] = false;
		} while (v != u);
		totColor++;
	}
	return low[u];
}

int dfs(int u, int f, long long &ans)
{
	int ret = 0;
	foreach(it, adj2[u]) {
		int v = *it;
		if (v == f) continue;
		ret += dfs(v, u, ans);
	}
	ans += (long long)ret * cnt[u];
	return ret + cnt[u];
}

bool vis[2][N];

long long calc(int root)
{
	vector<int> vec;
	long long ins = 0;
	foreach(it, adj2[root]) {
		vec.push_back(dfs(*it, root, ins));
	}
	memset(vis, 0, sizeof vis);

	vis[0][0] = true;
	for(int i = 0; i < vec.size(); ++ i) {
		int cur = i & 1;
		int nxt = cur ^ 1;
		memset(vis[nxt], 0, sizeof vis[nxt]);

		for(int j = 0; j <= m; ++ j) {
			if (vis[cur][j]) {
				vis[nxt][j + vec[i]] = true;
				vis[nxt][j] = true;
			}
		}
	} 

	long long ret = 0;
	for(int i = 0; i <= m; ++ i) {
		if (vis[vec.size() & 1][i]) {
			long long a = i;
			long long b = m - cnt[root] - a;
			long long c = cnt[root];
			ret = max(ret, a * c + a * b + c * b);
		}
	}
	return ret + ins;
}

void solve()
{
	cin >> n >> m;
	int u, v;
	for(int i = 0; i < m; ++ i) {
		scanf("%d%d", &u, &v);
		--u, --v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	for(int i = 0; i < n; ++ i) {
		low[i] = dfn[i] = -1;
		instack[i] = false;
	}
	tot = top = 0;
	tarjan(0, -1);
	set<pair<int, int> > edges;
	for(int i = 0; i < n; ++ i) {
		cnt[color[i]] ++;
		foreach(it, adj1[i]) {
			int j = *it;
			if (color[i] != color[j]) {
				if (edges.count(make_pair(color[i], color[j]))) continue;
				edges.insert(make_pair(color[i], color[j]));
				edges.insert(make_pair(color[j], color[i]));
				adj2[color[i]].push_back(color[j]);
				adj2[color[j]].push_back(color[i]);
			}
		}
	}

	long long ret = 0;
	m = n;
	n = totColor;
	for(int i = 0; i < n; ++ i) {
		ret = max(ret, calc(i));
	}
	for(int i = 0; i < n; ++ i) {
		ret += (long long)cnt[i] * cnt[i];
	}
	cout << ret << endl;
}

int main()
{
	solve();
	return 0;
}
