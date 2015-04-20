#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>

using namespace std;

typedef long long LL;

const int maxn = 200000;
const long long inf = 1000ll * 1000 * 1000 * 1000 * 1000;

LL n, m, a[maxn], s, cur, v, to, t, c, p[maxn], d[maxn], need[maxn];
vector <LL> g[maxn], w[maxn];
priority_queue <pair <LL, LL> > q;

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);

	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> a[i];
			
	for (int i = 0; i < m; i++) {
		cin >> s >> t >> c;

		g[s].push_back(t);
		w[s].push_back(c);

		g[t].push_back(s);
		w[t].push_back(c);
	} 

	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			q.push(make_pair(0ll, i));
			p[i] = i;
		} else {
			d[i] = inf;
		}
		if (a[i] == 2)
			need[i] = true;
	} 

	while (!q.empty()) {
		cur = - q.top().first;
		v = q.top().second;

		q.pop();

		if (cur > d[v])
			continue;

		for (int i = 0; i < (int)g[v].size(); i++) {
			to = g[v][i];

			if (d[to] > d[v] + w[v][i]) {
				p[to] = p[v];
				d[to] = d[v] + w[v][i];
				q.push(make_pair(- d[to], to));
			}
		} 
	}

	LL pos = - 1;

	for (int i = 1; i <= n; i++)
		if (need[i] && (pos == - 1 || d[pos] > d[i]))
			pos = i;

	if (pos == - 1 || d[pos] == inf)
		cout << - 1;
	else
		cout << p[pos] << ' ' << pos << ' ' << d[pos];

	return 0;
}
