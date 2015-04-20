#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cassert>
#include <cstdio>
#include <algorithm>
//#include <>

using namespace std;
#define fname "sochi"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long

const int N = 100500;
ll n, a[N], d, used[N];
ll ans = 0;
ll sum3[N];
int main() {
            
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	scanf("%lld%lld", &n, &d);

	for (int i = 1; i <= n; i ++ ) scanf ("%lld", &a[i]);
	sort(a + 1, a + 1 + n);

	ans = a[n];

	for (int i = 1; i <= n; i ++ ) {
		sum3[i] = sum3[i - 1];
		if(a[i] >= 3 * d) sum3[i] += a[i] - 2 * d;
	}

	for (int i = 1; i < n; i ++ ) {
		if (a[i] >= d && a[i + 1] >= d) {
			ans = max(ans, a[i] + a[i + 1] - 2 * d + sum3[n] - sum3[i + 1]);
		}
		ans = max(ans, a[n] + a[n - 1] - 2 * d + sum3[n - 2]);
		ans = max(ans, a[n] + a[i] - 2 * d + sum3[n - 1] - sum3[i]);
	}

	cout << ans;

	return 0;
}