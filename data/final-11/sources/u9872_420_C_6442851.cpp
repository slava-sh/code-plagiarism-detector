#pragma comment(linker, "/STACK:256000000")

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <functional>
#include <cstring>
#include <set>
#include <map>
#include <ctime>
#include <cassert>
#include <cinttypes>

using namespace std;

const int N = 300500;

map<int, int> g[N];
int s[N];
int n, p;
int f[N];
long long ans;

void update(int i, int val)
{
	for (; i < N; i = (i | (i + 1)))
		f[i] += val;
}

int sum(int i)
{
	int ret = 0;
	for (; i >= 0; i = (i & (i + 1)) - 1)
		ret += f[i];
	return ret;
}

int main()
{
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d %d", &n, &p);
	for (int i = 0; i < n; ++i)
	{
		int u, v;
		scanf("%d %d", &u, &v);
		++g[u][v];
		++g[v][u];
		++s[u];
		++s[v];
	}
	for (int i = 1; i <= n; ++i)
	{
		for (auto e : g[i])
		{
			const int j = e.first;
			if (j > i) continue;
			if (s[i] + s[j] - e.second >= p)
				++ans;
			if (s[i] + s[j] >= p)
				--ans;
		}
		if (s[i] >= p)
			ans += i - 1;
		else
			ans += sum(N - 1 - (p - s[i]));
		update(N - 1 - s[i], 1);
	}
	cout << ans << endl;
	return 0;
}