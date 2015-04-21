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

vector<ll> cul;
ll n;

void longest(vector<ll> &crnt, ll cres, ll &res) {
	if (cul == crnt) {
		res = max(res, cres);
		return;
	}
	for (ll i = 1; i < n; ++i) {
		if (crnt[i-1] >= crnt[i]) {
			swap(crnt[i-1], crnt[i]);
			longest(crnt, cres+1, res);
			swap(crnt[i-1], crnt[i]);
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n;

	vector<ll> a(n);
	cul.resize(n);
	for (ll i = 0; i < n; ++i) {
		cin >> a[i];
		--a[i];
		cul[i] = i;
	}

	ll best = -1, besti = -1, bestj = -1;
	longest(a, 0, best);

	for (ll i = 0; i < n; ++i) {
		for (ll j = i + 1; j < n; ++j) {
			ll cres = -1;
			swap(a[i], a[j]);
			longest(a, 0, cres);
			swap(a[i], a[j]);
			if (cres < best) {
				best = cres;
				besti = i+1;
				bestj = j+1;
			}
		}
	}

	cout << besti << " " << bestj << endl;

	return 0;
}