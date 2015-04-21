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

typedef pair<ll, ll> pll;

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

vector<map<ll, ll> > res;

void vm1(ll i, ll c, ll last = 1e18) {
	if (i == k) {
		return;
	}
	ll st = min<ll>(floor(sqrtl(c)), last);
	vector<pll> fnd;
	for (int g = st; g >= 1; --g) {
		if (c % g != 0) {
			continue;
		}
		if (g <= last) {
			ll crnt = (g+1)/2;
			if (i > 0) {
				crnt *= res[i-1][c];
			}
			if (res[i].find(c/g) == res[i].end()) {
				res[i][c/g] = crnt;
			} else {
				res[i][c/g] = min(res[i][c/g], crnt);
			}
			fnd.push_back(pll(c/g, g));
		}

		if (c/g <= last) {
			ll crnt = (c/g+1)/2;
			if (i > 0) {
				crnt *= res[i-1][c/g];
			}
			if (res[i].find(g) == res[i].end()) {
				res[i][g] = crnt;
			} else {
				res[i][g] = min(res[i][g], crnt);
			}
			fnd.push_back(pll(g, c/g));
		}
	}

	for (ll z = 0; z < fnd.size(); ++z) {
		vm1(i+1, fnd[z].first, fnd[z].second);
	}
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

	res.resize(k);
	//vm(0, n);
	vm1(0, n);

	//cout << mn << endl;

	cout << res[k-1][1] << endl;	
	return 0;
}