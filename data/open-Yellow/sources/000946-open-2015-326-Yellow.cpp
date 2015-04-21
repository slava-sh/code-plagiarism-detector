#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

typedef int ll;
typedef long double ld;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	ll n;
	cin >> n;
	vector<ll> a(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
	}

	ll m;
	cin >> m;
	ll last = 1;
	for (ll i = 1; i < n; ++i) {
		if (a[i] != a[i-1]) {
			++last;
		}
	}
	for (ll t = 0; t < m; ++t) {
		ll p, c;
		cin >> p >> c;
		--p;
		ll z = last;
		if (c == a[p]) {
			cout << z << endl;
			continue;
		}
		if (p > 0 && a[p-1] != a[p] && a[p-1] == c) {
			--z;
		}
		if (p+1 < n && a[p+1] != a[p] && a[p+1] == c) {
			--z;
		}
		if (p > 0 && a[p-1] == a[p]) {
			++z;
		}
		if (p+1 < n && a[p+1] == a[p]) {
			++z;
		}
		a[p] = c;
		
		cout << z << endl;
		last = z;
	}

	return 0;
}