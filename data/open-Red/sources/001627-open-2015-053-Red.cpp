#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <memory>
#include <string>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define sz(a) (int)a.size()

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef pair <int, int> ii;
typedef pair <ll, int> li;
typedef pair <int, ll> il;
typedef pair <ll, ll> lll;
typedef vector <ii> vii;
typedef vector <ll> vll;
typedef double db;
typedef long double ldb;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef set <int> si;
typedef set <ii> sii;
typedef set <ll> sl;
typedef set <lll> sll;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <db> vdb;
typedef vector <ldb> vldb;
typedef vector <si> vsi;

const int inf = (int)1e9 + 7;
const int N = (int)4e5 + 4;
const int M = 1000;
const ldb eps = 1e-12;

vii g[N];
int d[N];
int e[N];
bool u[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 1; i <= m; ++i)
	{
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		--a; --b;
		e[2 * i - 1] = c;
		e[2 * i] = c;
		g[a].pb(mp(b, 2 * i - 1));
		g[b].pb(mp(a, 2 * i));
	}
	int p;
	scanf("%d", &p);
	for (int i = 0; i < p; ++i)
	{
		int s, t;
		scanf("%d %d", &s, &t);
		--s; --t;
		for (int i = 0; i <= 2 * m; ++i)
			d[i] = inf;
		d[0] = 0;
		queue <ii> q;
		q.push(mp(s, 0));
		int ans = inf;
		for (; !q.empty(); q.pop())
		{
			ii v = q.front();
			d[v.second]++;
			u[v.second] = 0;
			for (int i = 0; i < sz(g[v.first]); ++i)
				if (d[g[v.first][i].second] > d[v.second] && (v.second == 0 || abs(e[g[v.first][i].second] - e[v.second]) <= k))
				{
					d[g[v.first][i].second] = d[v.second];
					if (!u[g[v.first][i].second])
					{
						u[g[v.first][i].second] = 1;
						q.push(g[v.first][i]);
					}
					if (g[v.first][i].first == t && ans > d[g[v.first][i].second])
						ans = d[g[v.first][i].second];
				}
			d[v.second]--;
		}
		if (ans == inf)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}
	return 0;
}