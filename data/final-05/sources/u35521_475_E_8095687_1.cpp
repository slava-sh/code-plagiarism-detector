#include <bits/stdc++.h>

using namespace std;

#define forforfor(e,x) for(__typeof((x).begin()) e=(x).begin(); e!=(x).end(); ++e)

const int MAX_N = 2000 + 10;
const int MODILE = 1e9 + 7;

int cnt_n, cnt_y;
int verh, vsego, vsegoCvet;
int kolvo[MAX_N];
int niz[MAX_N], dfn[MAX_N], instack[MAX_N], zta[MAX_N], color[MAX_N];
vector<int> adj1[MAX_N];
vector<int> adj2[MAX_N];

int dfs(int u, int f, long long &ans)
{
	int ret = 0;
	forforfor(it, adj2[u]) {
		int v = *it;
		if (v == f) continue;
		ret += dfs(v, u, ans);
	}
	ans += (long long)ret * kolvo[u];
	return ret + kolvo[u];
}

bool vis[2][MAX_N];
long long calc(int root)
{
	vector<int> vec;
	long long ins = 0;
	forforfor(it, adj2[root]) {
		vec.push_back(dfs(*it, root, ins));
	}
	memset(vis, 0, sizeof vis);

	vis[0][0] = true;
	for(int i = 0; i < vec.size(); ++ i) {
		int cur = i & 1;
		int nxt = cur ^ 1;
		memset(vis[nxt], 0, sizeof vis[nxt]);

		for(int j = 0; j <= cnt_y; ++ j) {
			if (vis[cur][j]) {
				vis[nxt][j + vec[i]] = true;
				vis[nxt][j] = true;
			}
		}
	} 

	long long ret = 0;
	for(int i = 0; i <= cnt_y; ++ i) {
		if (vis[vec.size() & 1][i]) {
			long long a = i;
			long long b = cnt_y - kolvo[root] - a;
			long long c = kolvo[root];
			ret = max(ret, a * c + a * b + c * b);
		}
	}
	return ret + ins;
}

int tarjan(int u, int f)
{
	niz[u] = dfn[u] = vsego ++;
	zta[++ verh] = u; instack[u] = true;
	forforfor(it, adj1[u]) {
		int v = *it;
		if (v == f) continue;
		if (dfn[v] < 0) {
			niz[u] = min(niz[u], tarjan(v, u));
		} else if (instack[v]) {
			niz[u] = min(niz[u], dfn[v]);
		}
	}
	if (niz[u] == dfn[u]) {
		int v;
		do {
			v = zta[verh --];
			color[v] = vsegoCvet;
			instack[v] = false;
		} while (v != u);
		vsegoCvet++;
	}
	return niz[u];
}

void ccc(set<pair<int, int> >& edges)
{
    for(int i = 0; i < cnt_n; ++ i) {
		kolvo[color[i]] ++;
		forforfor(it, adj1[i]) {
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

}



void solve()
{
	cin >> cnt_n >> cnt_y;
	int u, v;
	for(int i = 0; i < cnt_y; ++ i) {
		scanf("%d%d", &u, &v);
		--u, --v;
		adj1[u].push_back(v);
		adj1[v].push_back(u);
	}
	for(int i = 0; i < cnt_n; ++ i) {
		niz[i] = dfn[i] = -1;
		instack[i] = false;
	}
	vsego = verh = 0;
	tarjan(0, -1);
	set<pair<int, int> > edges;

    ccc(edges);

	long long ret = 0;
	cnt_y = cnt_n;
	cnt_n = vsegoCvet;
	for(int i = 0; i < cnt_n; ++ i) {
		ret = max(ret, calc(i));
	}
	for(int i = 0; i < cnt_n; ++ i) {
		ret += (long long)kolvo[i] * kolvo[i];
	}
	cout << ret << endl;
}

int main()
{
	solve();
	return 0;
}
