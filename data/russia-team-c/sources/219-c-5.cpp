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
#define pii pair<int, int>
#define vii vector<pair<int, int> > 
#define FIN freopen("1.in", "r", stdin)
#define FOUT freopen("2.out", "w", stdout)
#define FILE FIN; FOUT
#define SRD srand((int)time(NULL))
#define abs(x) ((x)>0?(x):-(x))
#define sqr(x) (1ll*(x)*(x))
#define pw(x) (1ll<<(x))
#define SC(x) scanf("%d", &x)
#define CC(x) cout << x << endl
#define forr(i, l, r) for(int i = l; i <= r; i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef double DD;
typedef long double LD;

using namespace std;

#define N 2222

vi a[N];
int n, cnt, ans, mx, k, V, U;
bool col[N];

	inline void dfs2(int u, int pr)
	{
		if (col[u]) return;
		cnt++;
		mx = max(mx, cnt);
		for (int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			dfs2(v, u);
		}
		cnt--;
	}

	inline void dfs1(int u, int pr)
	{
		col[u] = true;
		k++;
		mx = 0;
		cnt = 0;
		dfs2(V, 0);
		ans = max(ans, min(k, mx));
		for(int i = 0; i<a[u].size(); i++)
		{
			int v = a[u][i];
			if (v == pr) continue;
			dfs1(v, u);
		}
		col[u] = false;
		k--;
	}

int main()
{
	//ios_base::sync_with_stdin(false);
//	FILE;
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
	CC(ans);	
	return 0;
}