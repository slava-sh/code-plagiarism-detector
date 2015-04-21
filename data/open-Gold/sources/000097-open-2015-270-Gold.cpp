#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 300000;

vector<ll> vv;
ll c, d;
int n, k;
int a[MAXN];
int b[MAXN];
ll len;

int main() {
	scanf("%d%d%lld%lld", &n, &k, &c, &d);
	for (int i = 0; i < n; ++i)
		scanf("%d%d", &a[i], &b[i]), len += b[i] - a[i];
	for (int i = 0; i < n - 1; ++i)
		vv.push_back(a[i + 1] - b[i]);
	sort(vv.rbegin(), vv.rend());
	ll ans = 1000000000ll * d;
	ll sum = 0;
	for (int i = 0; i < (int)vv.size(); ++i)
		sum += vv[i];
	int now = 0;
	for (int x = 0; x * k <= n; ++x) {
		while (now < (int)vv.size() && now < (x + 1) * k - 1)
			sum -= vv[now], ++now;
		ans = min(ans, sum * d + x * c);
	}
	cout << ans + len * d;
	return 0;
}

