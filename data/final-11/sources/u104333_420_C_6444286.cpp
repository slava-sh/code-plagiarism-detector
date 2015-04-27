#include <cmath>
#include <map>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>
#include <bitset>
#include <memory.h>
#include <functional>
#include <queue>
#include <fstream>
#include <ctime>
#include <deque>
#include <utility>
#include <stack>
#include <sstream>
#include <list>
#include <cctype> 
#include <numeric>
#include <iomanip>
#include <assert.h>
using namespace std;
#define sqr(_) ((_)*(_))

typedef long long LL;

typedef pair<int, int> Pii;
#define x first
#define y second
#define mp make_pair
#define pb push_back

const int MAXN = 3 * 100000 + 10;

int n, p, d[MAXN], id[MAXN], pos[MAXN];
map<int, int> h[MAXN];
typedef map<int, int>::iterator mit;

bool cmp(int a, int b)
{
	return d[a] < d[b];
}
void init()
{
	scanf("%d%d", &n, &p);
	for (int i = 1; i <= n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		++h[x][y], ++h[y][x];
		++d[x], ++d[y];
		id[i] = i;
	}
	sort(id + 1, id + n + 1, cmp);
	for (int i = 1; i <= n; ++i)
		pos[id[i]] = i;
}
void solve()
{
	LL Tohka = 0;
	for (int i = 1, r = n + 1; i <= n; ++i)
	{
		for (; d[id[r - 1]] + d[id[i]] >= p && r > i; --r);
		r = max(r, i + 1);
		Tohka += n + 1 - r;
		for (mit it = h[id[i]].begin(); it != h[id[i]].end(); ++it)
			if (pos[it -> x] >= r && d[id[i]] + d[it -> x] - it -> y < p)
				--Tohka;
	}
	cout << Tohka << endl;
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin), freopen("output.txt", "w", stdout);
#endif
	
	init();
	solve();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

