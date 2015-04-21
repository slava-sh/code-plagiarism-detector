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

typedef long long ll;
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
	for (ll t = 0; t < m; ++t) {
		ll p, c;
		cin >> p >> c;
		--p;
		a[p] = c;
		ll z = 1;
		for (ll i = 1; i < n; ++i) {
			if (a[i] != a[i-1]) {
				++z;
			}
		}
		cout << z << endl;
	}

	return 0;
}