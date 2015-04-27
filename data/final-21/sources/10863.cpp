#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstdio>
#include <limits>
#include <cstdlib>
#include <set>
#include <map>
#include <queue>

#define vv vector
#define in cin
#define out cout
#define mp make_pair
#define px first
#define py second

using namespace std;

typedef long long int ll;

const double eps = 1e-7;
const int inf = numeric_limits<int>::max();

const int maxn = 100010;
const ll p = 107;

ll p_pow[maxn];

vv<ll> calc_hash(string s) {
	vv<ll> h(s.length());
	for (int i = 0; i < s.length(); ++i) {
		if (i) {
			h[i] = h[i - 1] * p;
		}
		h[i] += (s[i] - 'a' + 1);
	}
	return h;
}

ll get_hash(vv<ll> &h, int l, int r) {
	if (l) {
		return h[r] - h[l - 1] * p_pow[r - l + 1];
	} else {
		return h[r];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	freopen("inventory.in", "r", stdin);
	freopen("inventory.out", "w", stdout);	

	p_pow[0] = 1;
	for (int i = 1; i < maxn; ++i) {
		p_pow[i] = p_pow[i - 1] * p;
	}

	int n;
	in >> n;
	for (int i = 0; i < n; ++i) {
		string s;
		in >> s;
		int m = s.length();
		s += s;
		vv<ll> h = calc_hash(s);
		reverse(s.begin(), s.end());
		vv<ll> hr = calc_hash(s);
		int ans = -1;
		for (int j = 0; j < m; ++j) {
			ll h1 = get_hash(h, j, j + m - 1);
			ll h2 = get_hash(hr, m - j, 2 * m - j - 1);
			if (h1 == h2) {
				ans = j;
				break;
			}
		}
		out << ans << endl;
	}

	return 0;
}