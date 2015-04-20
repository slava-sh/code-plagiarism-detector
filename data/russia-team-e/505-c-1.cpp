#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>
#include <deque>
#include <cstdlib>
using namespace std;

#define ll long long
#define ld long double
const int MAX_N = 200005;
const int INF = 2000000000;

vector<int> e[MAX_N];
int d[MAX_N];
deque<int> q;
int from[MAX_N];
int n;
vector<int> ans_way;
int a[MAX_N];
int max_pref[MAX_N];

void bfs(int s, int t)
{
	q.clear();
	for (int i = 0; i < n; i++)
	{
		d[i] = INF;
		from[i] = -1;
	}

	d[s] = 0;
	q.push_back(s);
	while ((int)q.size() != 0)
	{
		int v = q[0];
		q.pop_front();
		for (int i = 0; i < (int)e[v].size(); i++)
			if (d[e[v][i]] > d[v] + 1)
			{
				d[e[v][i]] = d[v] + 1;
				from[e[v][i]] = v;
				q.push_back(e[v][i]);
			}
	}

	ans_way.push_back(t);
	int p = t;
	while (from[p] != -1)
	{
		p = from[p];
		ans_way.push_back(p);
	}
	reverse(ans_way.begin(), ans_way.end());

	return;
}

int max_deep = 0;

void dfs(int v, int deep)
{
	d[v] = 1;
	max_deep = max(max_deep, deep);
	for (int i = 0; i < (int)e[v].size(); i++)
		if (d[e[v][i]] == 0)
			dfs(e[v][i], deep + 1);
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
#endif
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		x--;
		y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	int s, t;
	scanf("%d%d", &s, &t);
	s--;
	t--;

	bfs(s, t);

	int sz = (int)ans_way.size();
	for (int i = 0; i < n; i++)
		d[i] = 0;
	for (int i = 0; i < sz; i++)
		d[ans_way[i]] = 1;

	for (int i = 0; i < sz; i++)
	{
		max_deep = 0;
		dfs(ans_way[i], 0);
		a[i] = max_deep;
	}


	max_pref[sz - 1] = a[sz - 1];
	int now_d = 1;
	for (int i = sz - 2; i >= 0; i--)
	{
		max_pref[i] = max(max_pref[i + 1], a[i] + now_d);
		now_d++;
	}

	int ans = 0;
	now_d = 0;
	for (int i = 0; i < sz; i++)
	{
		int max_left = max_pref[i + 1];
		int now_ans = min(a[i] + now_d, max_left);
		ans = max(ans, now_ans);
		now_d++;
	}

	printf("%d", ans + 1);

	return 0;
}