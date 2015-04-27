#if 1
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <functional>
#include <cstring>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <ctime>
#include <cassert>
#include <sstream>
#include <iostream>
#include <bitset>

using namespace std;

typedef long long LL;
typedef long double LD;
typedef pair<int , int> pii;
typedef vector <int> veci;
typedef vector <veci> graph;
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const int inf = 1000 * 1000 * 1000;
const LL inf64 = LL(inf) * inf;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
#define iss istringstream
#define oss ostringstream
#define dbg(x) {cerr << #x << " = " << x << endl;}
#define dbgv(x) {cerr << #x << " ={"; for (int _i = 0; _i < x.size(); _i++) {if (_i) cerr << ", "; cerr << x[_i];} cerr << "}" << endl;}
#define NAME "problem"

struct edge_t
{
	int u, v, d;
	edge_t() {}
	edge_t(int u, int v, int d) : u(u), v(v), d(d) {}
	friend bool operator < (const edge_t &a, const edge_t &b)
	{
		return a.d < b.d;
	}
};

int diff(const string &s, const string &t)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i)
		if (s[i] != t[i])
			++cnt;
	return cnt;
}

const int maxn = 1111;
int dp[maxn];
void dinit()
{
	for (int i = 0; i < maxn; ++i)
		dp[i] = i;
}
int dfind(int x) { return dp[x] == x ? x : dp[x] = dfind(dp[x]); }
void dunion(int x, int y) { dp[dfind(x)] = dfind(y); }

string gen(int m)
{
	string s;

	for (int i = 0; i < m; ++i)
	{
		int ch = rand() % 53;
		if (ch == 52)
			ch = '.';
		else if (ch >= 26)
			ch = ch - 26 + 'A';
		else
			ch = ch + 'a';
		s += char(ch);
	}
	return s;
}
void gen()
{
	int n = 10, m = 10;
	int k = 1000;
	int w = 1;
	cout << n << " " << m << " " << k << " " << w << endl;
	for (int i = 0; i < k; ++i)
	{
		for (int i = 0; i < n; ++i)
		{
			string s = gen(m);
			cout << s << endl;
		}
	}
	exit(0);
}
int main()
{
//	gen();
	clock_t tstart = clock();
	//freopen("input.txt", "r", stdin); //freopen("output.txt", "w", stdout);
	//freopen(NAME ".in","r",stdin);freopen(NAME ".out","w",stdout);

	int n, m, k, w;
	cin >> n >> m >> k >> w;
	vector< string > a(k);
	for (int i = 0; i < k; ++i)
	{
		string s;
		for (int i = 0; i < n; ++i)
		{
			string t;
			cin >> t;
			s += t;
		}
		a[i] = s;
	}

	vector< edge_t > edges;
	for (int i = 0; i < k; ++i)
	{
		edges.pb(edge_t(0, i + 1, n * m));
		for (int j = i + 1; j < k; ++j)
		{
			int cnt = diff(a[i], a[j]);
			cnt *= w;
			edges.pb(edge_t(i + 1, j + 1, cnt));			
		}
	}

	dbg("edges gen ok");
	sort(edges.begin(), edges.end());
	dbg("sort ok");
	vector<edge_t> good;
	int cost = 0;
	dinit();
	for (int i = 0; i < edges.size(); ++i)
	{
		if (dfind(edges[i].u) != dfind(edges[i].v))
		{
			good.pb(edges[i]);
			cost += edges[i].d;
			dunion(edges[i].u, edges[i].v);
		}
	}

	dbg("mst ok");
	vector< vector<int> > g(k + 1);
	swap(good, edges);
	for (int i = 0; i < edges.size(); ++i)
	{
		g[edges[i].u].pb(edges[i].v);
		g[edges[i].v].pb(edges[i].u);
	}

	vector<int> d(g.size(), -1);
	vector<int> pr(g.size(), -1);
	queue<int> q;
	q.push(0);
	d[0] = 0;
	while (q.size())
	{
		int u = q.front(); q.pop();
		for (int i = 0; i < g[u].size(); ++i)
		{
			int v = g[u][i];
			if (d[v] != -1)
				continue;
			d[v] = d[u] + 1;
			pr[v] = u;
			q.push(v);				
		}
	}

	vector<pii> ord(d.size());
	for (int i = 0; i < d.size(); ++i)
		ord[i] = mp(d[i], i);
	sort(ord.begin(), ord.end());

	cout << cost << endl;
	for (int i = 1; i < d.size(); ++i)
	{
		cout << ord[i].Y << " " << pr[ord[i].Y] << endl;
	}

	dbg((clock() - tstart) / LD(CLOCKS_PER_SEC));
	return 0;
}
/*************************
*************************/
#endif
