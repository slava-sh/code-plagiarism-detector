/*
*   Copyright (C) 2014 All rights reserved.
*   
*   filename: 420B.cpp
*   author: doublehh
*   e-mail: sserdoublehh@foxmail.com
*   create time: 2014-04-22
*   last modified: 2014-04-22 20:36:14
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;
#define mp(x, y) make_pair(x, y)
#define X first
#define Y second
#define pb(x) push_back(x)
#define FOR(i, n) for (int i = 0; i < (n); i++)
#define FOR1(i, n) for (int  i = 1; i <= (n); i++)
#define foreach(it, s) for (__typeof((s).begin()) it = (s).begin(); it != (s).end(); it++)

const int maxn = 1e5+1;
int n, m;
char ty[maxn];
int id[maxn];
bool ok[maxn];
int state[maxn];

set<int> S;

int main()
{
	scanf("%d%d", &n, &m);
	FOR1 (i, n)
		ok[i] = 1;
	int cnt = 0;
	int diff = 0;
	FOR (i, m)
	{
		char op[2];
		scanf("%s%d", op, &id[i]);
		ty[i] = op[0];
		if (!state[id[i]])
		{
			if (ty[i] == '+')
				state[id[i]] = 1;
			else
			{
				state[id[i]] = 2;
				cnt++;
				S.insert(id[i]);
			}
		}
	}
	bool bad = 0;
	int j = 0;
	FOR (i, m)
	{
		if (cnt == 1)
		{
			int k = *S.begin();
			if (!j) j = k;
			else if (j != k)
				j = -1;
			bad = 1;
		}
		if (ty[i] == '+')
		{
			if (cnt)
				ok[id[i]] = 0;
			cnt++;
			S.insert(id[i]);
		}
		else
		{
			cnt--;
			if (cnt)
				ok[id[i]] = 0;
			S.erase(id[i]);
		}
	}
	if (cnt == 1)
	{
		int k = *S.begin();
		if (!j) j = k;
		else if (j != k)
			j = -1;
		bad = 1;
	}
	if (bad)
		FOR (i, m) if (id[i] != j)
			ok[id[i]] = 0;
	int ans = 0;
	FOR1 (i, n)
		if (ok[i])
			ans++;
	printf("%d\n", ans);
	FOR1 (i, n)
		if (ok[i])
			printf("%d ", i);
}
