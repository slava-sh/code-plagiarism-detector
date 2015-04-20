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
#define fname "fence"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
const int N = 100500;
int n, k, a[N], mn = 1000000000, ans = 0;

bool ok (int mid) {
	int l = 0;
	for (int i = 1; i <= n; i ++ ) {
		if (l + mid > k) return false;
		int ewe = max(0, a[i] - (l + mid));
		l += mid;
		l += ewe;
	}
	ans = max(ans, mid);
	return true;
}

int main() {
            
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	scanf ("%d%d", &n, &k);

	for (int i = 1; i <= n; i ++ ) {
		scanf ("%d", &a[i]);
		mn = min(mn, a[i]);
	}

	sort(a + 1, a + 1 + n);

	int l = 0, r = mn;

	while (l <= r) {
		int mid = (l + r) >> 1;
		if (ok(mid)) l = mid + 1;
		else r = mid - 1;
	}

	cout << ans;

	return 0;
}
