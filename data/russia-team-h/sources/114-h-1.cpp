#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <cassert>
#include <ctime>

using namespace std;

typedef long long ll;
typedef long double ld;

#define LLD "%I64d"

#define FILENAME "secure"

const int inf = 1e9;
const int maxn = 5005;

vector<int> gr[maxn], len[maxn];
pair<int, int> d[maxn];
bool was[maxn];
int a[maxn];
int n, m;

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) scanf("%d", &a[i]);

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		a--, b--;
		gr[a].push_back(b);
		len[a].push_back(c);
		gr[b].push_back(a);
		len[b].push_back(c);
	}

	for (int i = 0; i < n; i++)
	{
		if (a[i] == 1) d[i] = make_pair(0, i);
		else d[i] = make_pair(inf, -1);
		was[i] = false;
	}

	while (true)
	{
		int cur = -1;
		pair<int, int> dcur = make_pair(inf, -1);
		for (int i = 0; i < n; i++) if (!was[i] && d[i] < dcur)
		{
			cur = i;
			dcur = d[i];
		}
		if (cur == -1) break;
//		cout << cur << ' ' << dcur.first << ' ' << dcur.second << endl;
		was[cur] = true;
		if (a[cur] == 2)
		{
			printf("%d %d %d\n", d[cur].second + 1, cur + 1, d[cur].first);
			return 0;
		}
		for (int i = 0; i < (int)gr[cur].size(); i++)
		{
			int nd = d[cur].first + len[cur][i];
			d[gr[cur][i]] = min(d[gr[cur][i]], make_pair(nd, d[cur].second));
		}
	}
	printf("-1\n");

	return 0;
}