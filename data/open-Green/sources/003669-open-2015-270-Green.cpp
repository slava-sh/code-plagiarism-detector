#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

ll n;
int k;
ll mm[6][10000];
vector<pair<ll, int> > gg[10000];

vector<ll> vv;

int main() {
	cin >> n >> k;
	while (k > 1 && n % 2 == 0)
		--k, n /= 2;
	if (k == 1) {
		cout << (n + 1) / 2;
		return 0;
	}

	int mx = (k / 2) + (k % 2);

	for (ll i = 1; i * i <= n; ++i) {
		if (n % i == 0) {
			if (i * i != n)
				vv.push_back(i), vv.push_back(n / i);
			else
				vv.push_back(i);
		}
	}
	sort(vv.begin(), vv.end());


	for (int i = 0; i < (int)vv.size(); ++i)
		mm[0][i] = vv[i] + 1;

	for (int j = 0; j < (int)vv.size(); ++j) {
		int now = 0;
		ll k = n / vv[j];
		for (int j1 = 0; j1 <= j; ++j1) {
			if (vv[j1] > k)
				break;
			if (n % (vv[j] *  vv[j1]) != 0)
				continue;
			while (vv[now] != vv[j] * vv[j1])
				++now;
			gg[j].push_back({j1, now});
		}
	}

	for (int i = 1; i < mx; ++i)
		for (int j = 0; j < (int)vv.size(); ++j)
			mm[i][j] = n * (1 << k);

	for (int i = 1; i < mx; ++i) {
		for (int j = 0; j < (int)vv.size(); ++j) {
			for (int j1 = 0; j1 < (int)gg[j].size(); ++j1)
				mm[i][gg[j][j1].second] = min(mm[i][gg[j][j1].second], mm[i - 1][j] * (vv[j1] + 1));
		}
	}
	ll ans = n * (1 << k);
	int a = mx - 1;
	int b = k - mx - 1;

	for (int i = 0; i < (int)vv.size(); ++i) {
		for (int j = 0; j < (int)gg[i].size(); ++j)
			if (vv[i] * vv[gg[i][j].first] == n)
				ans = min(ans, mm[a][i] * mm[b][gg[i][j].first]);
	}

	cout << ans / 4;






	return 0;
}

