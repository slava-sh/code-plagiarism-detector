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

ll n, k;
ll mn = 1e18;

vector<ll> path;

void test() {
	ll cnt = 1;
	for (ll i = 0; i < path.size(); ++i) {
		cnt *= (path[i]+1)/2;
		//cout << path[i] << " ";
	}
	//cout << endl;
	//cout << cnt << endl;
	mn = min(mn, cnt);
}


void vm(ll i, ll c) {
	if (i == k-1) {
		path.push_back(c);
		test();
		path.pop_back();
		return;
	}
	ll st = floor(sqrtl(c));
	if (!path.empty()) {
		st = min(st, path.back());
	}
	for (int g = st; g >= 1; --g) {
		if (c % g != 0) {
			continue;
		}
		if (path.empty() || g <= path.back()) {
			path.push_back(g);
			vm(i+1, c/g);
			path.pop_back();
		}

		if (path.empty() || c/g <= path.back()) {
			path.push_back(c/g);
			vm(i+1, g);
			path.pop_back();
		}
	}
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> n >> k;

	vm(0, n);

	cout << mn << endl;

	return 0;
}