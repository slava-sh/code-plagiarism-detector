#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
typedef long long ll;

using namespace std;

ll a[100010];
ll n, k;

bool f(long long m) {
	long long uk = 0;
	for (long long i = 0; i < n; i++) {
		if (a[i] - uk >= m) {
			uk = a[i];
			continue;
		}
		if (uk + max(m, a[i] - uk) < k) {
			uk = uk + max(m, a[i] - uk);
		} else {
			return 0;
		}
	}
	return 1;
}

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	ll l = 0, r = 1000000000;
	cin >> n >> k;
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		r = min(r, a[i]);
	}
	r++;
	sort(a + 0, a + n);
	//reverse(a + 0, a + n);
	while (r - l > 1) {
		ll m = (l + r) / 2;
		if (f(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l;
	return 0;
}