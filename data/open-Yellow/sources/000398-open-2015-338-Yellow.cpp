#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <map>
#include <set>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <climits>
#include <queue>
#include <sstream>

#define mp make_pair
#define fs first
#define sc second

typedef long long ll;
typedef long double ld;

using namespace std;

const int MAXN = 1000010;
ll a[MAXN];
const ll INF = (1ll << 50);
int main()
{
	ios_base::sync_with_stdio(0);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, ans = 0;
	scanf("%d", &n);
	a[0] = a[n + 1] = INF;
	for (int i = 1; i <= n; i++)
	{
		int nw;
		scanf("%d", &nw);
		a[i] = nw;
		if (a[i] != a[i - 1]) ans++;
	}
	int q;
	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		int p, c;
		scanf("%d%d", &p, &c);
		if (a[p] != a[p - 1]) ans--;
		if (a[p + 1] != a[p]) ans--;
		a[p] = c;
		if (a[p] != a[p - 1]) ans++;
		if (a[p] != a[p + 1]) ans++;
		printf("%d\n", ans);
	}
	return 0;
}