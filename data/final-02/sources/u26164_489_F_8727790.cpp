#include <iostream>
#include <cassert>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <queue>
#include <deque>
#include <map>
#include <stack>
#include <set>
#include <iomanip>
#include <string>
#include <utility>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <vector>                              
using namespace std;
#define fname ""
#define ull unsigned long long
#define ll long long
#define INF 1000*1000*1000
#define F first
#define S second
#define mp make_pair
#define pb push_back
const int N = 600;
int n, a[N][N], m, mod;
int row[N], col[N];
int d[N][N], was[N][N];

ll calc(int c1, int c2) {
	if (was[c1][c2]) return d[c1][c2];
	was[c1][c2] = 1;
	ll ret = 0;
	if (c1 >= 2) {
		ll cnt = (c1 * 1ll * (c1 - 1) / 2) % mod;
		ret += (calc(c1 - 2, c2) * cnt) % mod;
		ret %= mod;
	}
	if (c2 >= 2) {
		ll cnt = (c2 * 1ll * (c2 - 1) / 2) % mod;
		ret += (calc(c1 + 2, c2 - 2) * cnt) % mod;
		ret %= mod;
	}
	if (c1 >= 1 && c2 >= 1) {
		ll cnt = (c1 * 1ll * c2) % mod;
		ret += (calc(c1, c2 - 1) * cnt) % mod;
		ret %= mod;
	}
	return d[c1][c2] = ret;
}


int main ()
{
	#ifndef ONLINE_JUDGE
	freopen (fname"in","r",stdin);
	freopen (fname"out","w",stdout);
	#endif

	scanf("%d%d%d\n", &n, &m, &mod);

	for (int i = 1; i <= m; ++ i) {
		for (int j = 1; j <= n; ++ j) {
			char ch;
			scanf("%c", &ch);
			a[i][j] = ch - '0';
			if (a[i][j]) row[i]++, col[j]++;
		}
		scanf("\n");
	}
	
	int c2 = 0, c1 = 0;

	for (int i = 1; i <= n; ++ i) {
		if (col[i] == 0) c2++;
		if (col[i] == 1) c1++;
	}

	was[0][0] = 1;
	d[0][0] = 1;

	cout << calc(c1, c2) % mod;

	return 0;
}