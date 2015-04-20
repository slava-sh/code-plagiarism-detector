#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

const int MAXN = 5002;
const int INF = 1000 * 1000 * 1001;
vector <int> t2;
int d[MAXN];
int p[MAXN];

vector <pair <int, int> > e[MAXN];

struct cmp
{
	bool operator() (int x, int y)
	{
		return (make_pair(d[x], x) < make_pair(d[y], y));
	}
};

set <int, cmp> st;

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		p[i] = -1;
		d[i] = INF;
		int tp;
		cin >> tp;
		if (tp == 1)
		{
			d[i] = 0, p[i] = i;
		}
		if (tp == 2)
		{
			t2.push_back(i);
		}
		st.insert(i);
	}
	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a--, b--;
		e[a].push_back(make_pair(b, c));
		e[b].push_back(make_pair(a, c));
	}
	for (int bb = 0; bb < n; bb++)
	{
		int v = *st.begin();
		st.erase(st.begin());
		if (d[v] == INF) break;
		for (int i = 0; i < e[v].size(); i++)
		{
			if (d[e[v][i].first] > d[v] + e[v][i].second)
				d[e[v][i].first] = d[v] + e[v][i].second, p[e[v][i].first] = p[v];
		}
	}
	d[n] = INF;
	int rs = n;
	p[n] = -1;
	for (int i = 0; i < t2.size(); i++)
	{
		if (d[t2[i]] < d[rs]) rs = t2[i];
	}
	if (rs != n) cout << p[rs] + 1 << " " << rs + 1 << " " << d[rs] << endl;
	else cout << -1 << endl;
	return 0;
}