#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <time.h>
#include <cmath>
#include <memory.h>
#include <functional>
#include <sstream>
#include <string>
#include <cstring>
#include <iomanip>

#define pb push_back
#define mp make_pair
#define S second
#define F first
#define SS stringstream
#define vi vector<int>
#define fill(x, a) memset(x, a, sizeof(x))
#define pii pair<int, int>
#define vii vector<pair<int, int> > 
#define FIN freopen("1.in", "r", stdin)
#define FOUT freopen("1.out", "w", stdout)
#define FILE FIN; FOUT
#define SRD srand((int)time(NULL))
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) (1ll*(x)*(x))
#define pw(x) (1ll<<(x))
#define SC(x) scanf("%d", &x)
#define CC(x) cout << x << endl
#define forr(i, l, r) for(int i = l; i <= r; i++)
#define ALL(x) x.begin(), x.end()

typedef long long LL;
typedef unsigned long long ULL;
typedef double DD;
typedef long double LD;

using namespace std;

#define N 222222

vi a[N];
int dep, depth[N], K, n, mx[N], timer, tin[N], tout[N], U, V;
bool ok[N], found;

	inline void dfs1(int u, int pr)
	{
		dep++;
		timer++;
		tin[u] = timer;
		depth[u] = dep;
		for(int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			dfs1(v, u);
		}
		dep--;
		timer++;
		tout[u] = timer;
	}

	inline bool ancestor(int u, int v)
	{
		return tin[u] <= tin[v] && tout[u] >= tout[v];
	}

	inline void dfs(int u, int pr)
	{
		vii b;
		b.clear();
		int dd = 0, child = 0;
		mx[u] = depth[u];
		for(int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			dfs(v, u);
			mx[u] = max(mx[u], mx[v]);
			if (ok[v]) ok[u] = true;
			child++;
			if (ancestor(v, V) && ok[v]) dd = mx[v];
		}
		if (u == V)
		{
			if (child > 0 && mx[u]-depth[u]+1 >= K) ok[u] = true;
		}
		if (ok[u] && depth[u]-1 >= K) {found = true; return;}
		if (u == V) return;
		if (!ancestor(u, V)) return;
		if (dd > 0 && dd-depth[u]+1 >= K) {ok[u] = true; return;}
		if (dd == 0) dd = depth[V];
		dd -= depth[u];
		if (dd+1 >= K) {ok[u] = true; return;}
		for(int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			if (ancestor(v, V)) continue;
			int d = mx[v]-depth[u], c = ok[v];
			if (!c)
			{
				if (dd + d + 1 >= K) {ok[u] = true; return;}
			}                                        
		}
	}	

	inline void _dfs(int u, int pr)
	{
		int cnt = 0;
		for(int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			if (ok[v]) cnt++;
		}
		for(int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			int d = mx[v], o = ok[v];
			cnt -= o;
			if (d >= K && cnt > 0) {found = true; return;}
			cnt += o;
		}
		if (ok[u] && depth[u]-1 >= K) {found = true; return;}
		for(int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			_dfs(v, u);
			if (found) return;
		}
	}
	
	inline bool check(int k)
	{
		if (k <= 1) return true;
		fill(ok, 0);
		fill(mx, 0);
		K = k;
		found = false;
		dfs(U, 0);  
		_dfs(U, 0);
		return found;
	}

int main()
{
	//FILE;
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	SC(n);
	forr(i, 1, n-1)
	{
		int x, y;
		SC(x); SC(y);
		a[x].pb(y); a[y].pb(x);
	}
	SC(U); SC(V);
	dfs1(U, 0);
	int l = 1, r = n;
	while (r > l)
	{
		int m =(l+r+1)/2;             
		if (check(m)) l = m; else r = m-1;
	}
	CC(l);
	return 0;
}