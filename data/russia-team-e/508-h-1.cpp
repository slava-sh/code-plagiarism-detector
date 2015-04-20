#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#pragma comment(linker, "/STACK:256000000");
using namespace std;

/*(int a[200][200];
int n, m, t;
long long hf()
{
	long long h = 0;
	for (i = 0; i <*/

vector<pair<long long, long long>> b[1000000];
int p[1000000];

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	
	//cin >> n >> m >> t;
	int n, m;
	cin >> n >> m;
	long long d[1000000];
	set<pair<long long, long long>> q;
	for (int i = 0; i < 1000000; i++)
		d[i] = 1000000000000000, p[i] = -1;
	long long a[1000000];
	for (int i = 0; i < n; i++)
	{

		cin >> a[i];
		if (a[i] == 1)
		{
			d[i] = 0;
			q.insert(make_pair(0, i));
			p[i] = i;
		}
	}
	for (int i = 0; i < m; i++)
	{
		long long x, y, z;
		cin >> x >> y >> z;
		x--, y--;
		b[x].push_back(make_pair(y, z));
		b[y].push_back(make_pair(x, z));
	}
	bool was[1000000];
	for (int i = 0; i < 1000000; i++)
		was[i] = false;
	while (!q.empty())
	{
		long long dist = q.begin()->first;
		long long v = q.begin()->second;
		q.erase(q.begin());
		if (was[v]) continue;
		was[v] = true;
		d[v] = dist;
		for (int i = 0; i < b[v].size(); i++)
			if (d[b[v][i].first] > d[v] + b[v][i].second)
			{
				d[b[v][i].first] = d[v] + b[v][i].second;
				q.insert(make_pair(d[v] + b[v][i].second, b[v][i].first));
				p[b[v][i].first] = p[v];
			}
	}

	long long ans = 1000000000000000;
	int mx = -1, my = -1;
	for (int i  = 0; i < n; i++)
		if (a[i] == 2)
			if (d[i] < ans)
			{
				mx = p[i] + 1;
				my = i + 1;
				ans = d[i];
			}
			if (mx == -1)
				cout << -1;
			else
				cout << mx << ' ' << my << ' ' << ans;


	return 0;
}