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
#define fill(x, a) memset(x, a, sizeof(x))
#define vi vector<int>
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
#define CCS(x) cout << x << " "
#define forr(i, l, r) for(int i = l; i <= r; i++)

typedef long long LL;
typedef unsigned long long ULL;
typedef double DD;
typedef long double LD;

using namespace std;

#define N 5055

int n, m, col[N], w[N][N], d[N], a1, a2, pred[N];
bool used[N];
vi a[N], c[N];

int main()
{
	//ios_base::sync_with_stdin(false);
	//FIN;
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	SC(n); SC(m);
	forr(i, 1, n) SC(col[i]);
	forr(i, 1, m)
	{
		int x, y, z;
		SC(x); SC(y); SC(z);
		a[x].pb(y); a[y].pb(x);
		c[x].pb(z); c[y].pb(z);
	}   
	fill(w, 63);
	int inf = w[0][0];
	forr(i, 1, n) if (col[i] == 1)
	{
		for(int j = 0; j<a[i].size(); j++)
		{
			int v = a[i][j];
			if (w[0][v] > c[i][j])
			{
				w[0][v] = c[i][j];
				pred[v] = i;
			}
		}
	}
	w[0][0] = 0;
	forr(i, 1, n) d[i] = w[0][i];
	used[0] = true;
	forr(it, 1, n)
	{
		int mn = inf, u = 0;
		forr(i, 1, n) if (col[i] != 1 && !used[i] && d[i] < mn)
		{
			mn = d[i];
			u = i;
		}
		used[u] = true;
		for(int j = 0; j<a[u].size(); j++)
		{
			int v = a[u][j];
			if (col[v] == 1) continue;
			if (d[v] > d[u] + c[u][j])
			{
				d[v] = d[u] + c[u][j];
				pred[v] = u;
			}
		}
	}
	int ans = inf;
	forr(i, 1, n) if (col[i] == 2 && d[i] != inf) 
		if (ans > d[i])
		{
			ans = d[i];
			a2 = i;
		}
        a1 = a2;
	while (a1 > 0)
	{
		if (col[a1] == 1) break;
		a1 = pred[a1];
	}

	if (ans == inf) {CC("-1"); return 0;}
	CCS(a1); CCS(a2); CC(ans);
	return 0;
}