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
const ll INF = 1000ll * 1000ll * 1000ll * 1000ll * 1000ll * 2000ll;
const int MAXN = 300001;
ll a[MAXN];
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	ll c, d;
	scanf("%d%d%lld%lld", &n, &k, &c, &d);
	ll ad = 0, ans = INF, cur = 0, pb = -INF;
	for (int i = 0; i < n; i++)
	{
		ll st, fn;
		scanf("%lld%lld", &st, &fn);
		if (i != 0) a[i - 1] = (st - pb) * d;
		ad += (fn - st) * d;
		pb = fn;
	}
	n--;
	sort(a, a + n);
	cur = (n / k) * c;
	ans = cur;
	for (int i = 0; i < n; i++)
	{
		cur += a[i];
		if ((n - i) % k == 0) cur -= c;
		ans = min(ans, cur);
	}
	cout << ans + ad << endl;
	return 0;
}