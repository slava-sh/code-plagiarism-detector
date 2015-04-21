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

	ll ans = 1;
	for (ll i = 0; i < z.size()-k; ++i) {
		ans *= z[i];
	}
	ans = (ans+1)/2;
	for (ll i = z.size()-k; i < z.size(); ++i) {
		ans *= (z[i]+1)/2;
	}

	cout << ans << endl;
	return 0;
}