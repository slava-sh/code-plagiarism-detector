#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
using namespace std;

const int N = (int)3e5;
int deep[N];
int listV[N];
int indV = 0;
int used[N];
int cc = 1;
vector <int> g[N];

bool findLine(int v, int e, int pos)
{
	listV[pos] = v;
	if (v == e)
	{
		indV = pos + 1;
		return true;
	}
	used[v] = 1;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (!used[to])
		{
			if (findLine(to, e, pos + 1))
				return true;
		}
	}
	return false;
}

int findDeep(int v)
{
	int ans = 0;
	used[v] = cc;
	for (int i = 0; i < (int)g[v].size(); i++)
	{
		int to = g[v][i];
		if (used[to] != cc)
		{
			ans = max(ans, findDeep(to) + 1);
		}
	}
	return ans;
}

int main()
{
	freopen ("dwarfs.in", "r", stdin);
	freopen ("dwarfs.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int a, b;
	scanf("%d%d", &a, &b);
	findLine(a, b, 0);

	for (int i = 0; i < indV; i++)
	{
		cc++;
		int prevV = (i == 0 ? listV[i] : listV[i - 1]);
		int nextV = (i == indV - 1 ? listV[i] : listV[i + 1]);
		used[prevV] = used[nextV] = cc;
		deep[i] = findDeep(listV[i]) + 1;
	}

	int ans = 0;
	int curMax = deep[0];
	for (int i = 1; i < indV; i++)
	{
		ans = max(ans, min(curMax, indV - i - 1 + deep[i]));
		curMax = max(curMax, deep[i] + i);
	}
	printf("%d", ans);

	return 0;
}