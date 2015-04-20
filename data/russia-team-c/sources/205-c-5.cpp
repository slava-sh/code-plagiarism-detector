#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <cstdio>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

vector <vector < int > > g;
vector <bool> was;
vector <int> pyt, ans, ans1;
int b, e;
int n;

bool New(int v, vector <int> & pyt)
{
	if (was[v]) return false;
	was[v] = true;
	if (v == e) return true;
	for (int i = 0; i < g[v].size(); i++)
	{
		pyt.push_back(g[v][i]);
		if ( New(g[v][i], pyt))
			return true;
		pyt.pop_back();
	}
	return 0;
}

int Go(int v, vector <int> &pr)
{
	if (was[v]) return -1;
	was[v] = true;
	int ans = 0;
	for (int i = 0; i < g[v].size(); i++)
	{
		if (g[v][i] != pr[v])
		{
		int y = Go(g[v][i], pr);
		if (ans < y + 1)
		{
			ans = y + 1;
		}
		}
	}
	return ans;
}
void Dfs(vector <int> &pr, int v, int pr1)
{
	if (was[v]) return;
	was[v] = true;
	pr[v] = pr1;
	for (int i = 0; i < g[v].size(); i++)
	{
		Dfs(pr, g[v][i], v);
	}	

}
void Find(vector <int> &pyt, vector <int> & ans)
{
	int dist = 0;
	vector <int> len;
	vector <int > pr;
	pr.resize(n);
	was.assign(n ,0);
	Dfs(pr, pyt[pyt.size() -1], -1);
	was.assign(n, false);
	ans.resize(n);
	ans[0] = Go( pyt[0], pr) + 1;
	for (int i = 1; i < pyt.size() - 1; i++)
	{
		dist++;
		int v = pyt[i];
		ans[ i ] = max(ans[i - 1], dist);
		for (int j = 0; j < g[v].size(); j++)
		{
			was.assign(n, 0);
			if (g[v][j] != pyt[i + 1])
		        ans[ i ] = max ( ans[i], dist + 2 + Go( g[v][j], pr));
		}
	}
}
int main() {
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	cin >> n;
	g.resize(n);
	for (int i = 0; i  < n - 1; i++)
	{
		int x, y;
		cin >> x >> y;
		x--;
		y--;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	cin >> b >> e;
	b--; e--;
	pyt.clear();
	pyt.push_back(b);
	was.assign(n, false);

	New(b, pyt);
	Find(pyt, ans);
	reverse(pyt.begin(), pyt.end());
	Find(pyt, ans1);
	int m = 0;
	for (int i = 0; i < pyt.size() - 1; i++)
	{
		m = max(m, min(ans[i], ans1[pyt.size() - 2 - i]));
	}
	cout << max(1 ,m);
	return 0;
}