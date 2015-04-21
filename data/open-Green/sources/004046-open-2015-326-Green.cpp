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

	ll n, k;
	cin >> n >> k;
	vector<ll> z;
	for (ll i = 2; i*i<=n; ++i) {
		while (n % i == 0) {
			z.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		z.push_back(n);
	}

	bool gd = true;
	while (z.size() > k || gd) {
		ll bst = 1e15;
		ll bi = 0, bj = 1;
		for (ll i = 0; i < z.size(); ++i) {
			for (ll j = i+1; j < z.size(); ++j) {
				ll delta = (i*j+1)/2-(i+1)/2*(j+1)/2;
				if (delta < bst) {
					bst = delta;
					bi = i;
					bj = j;
				}
			}
		}
		gd = bst < 0;
		if (z.size() > k) {
			z[bi] = z[bi]*z[bj];
			z[bj] = 1;
			z.erase(z.begin()+bj);
		} else if (gd) {
			z[bi] = z[bi]*z[bj];
			z[bj] = 1;
		}
	}

	ll ans = 1;
	for (ll i = 0; i < z.size(); ++i) {
		ans *= (z[i]+1)/2;
	}

	cout << ans << endl;
	return 0;
}