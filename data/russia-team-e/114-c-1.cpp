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

#define FILENAME "dwarfs"

const int maxn = 200005;

vector<int> gr[maxn];
bool inpath[maxn];
vector<int> path;
int dep[maxn], maxdep[maxn];
int n;

bool find(int cur, int pr, int y)
{
//	cout << "find " << cur << endl;
	if (cur == y)
	{
		inpath[cur] = true;
		path.push_back(cur);
		return true;
	}
	for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i] != pr)
	{
		if (find(gr[cur][i], cur, y))
		{
//			cout << "found " << cur << endl;
			inpath[cur] = true;
			path.push_back(cur);
			return true;
		}
	}
	return false;
}

int go(int cur, int pr)
{
	int ans = 1;
	for (int i = 0; i < (int)gr[cur].size(); i++) if (gr[cur][i] != pr && !inpath[gr[cur][i]])
	{
		ans = max(ans, 1 + go(gr[cur][i], cur));
	}
	return ans;
}

int main() 
{
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--, b--;
		gr[a].push_back(b);
		gr[b].push_back(a);
	}
	int x, y;
	scanf("%d%d", &x, &y);
	x--, y--;
	find(x, -1, y);
	int m = path.size();
	for (int i = 0; i < m; i++)
	{
		dep[i] = go(path[i], -1);
//		cout << i << ' ' << path[i] << ' ' << dep[i] << endl;
	}
	maxdep[m - 1] = dep[m - 1];
	for (int i = m - 2; i >= 0; i--) maxdep[i] = max(maxdep[i + 1], (m - 1) - i + dep[i]);
	int curm = dep[0];
	int answer = 0;
	for (int i = 0; i < m - 1; i++)
	{
		answer = max(answer, min(curm, maxdep[i + 1]));
		curm = max(curm, (i + 1) + dep[i + 1]);
	}
	cout << answer << endl;

	return 0;
}