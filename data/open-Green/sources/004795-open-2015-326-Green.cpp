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
#include <sys/timeb.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main() {
	timeb st, ed;
	ftime(&st);
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

	ll bans = 1e18;
	
	ll cntr = 0;
	while (true) {
		++cntr;
		if (cntr & 3 == 0) {
			ftime(&ed);
			if (ed.time*1000-st.time*1000+ed.millitm-st.millitm>5500) {
				break;
			}
		}
		auto oz = z;
		while (z.size() > k) {
			ll bst = 1e18;
			ll bi = rand()%z.size(), bj = rand()%z.size();
			while (bj == bi) {
				bj = rand()%z.size();
			}
			
			bool gd = (bst < 0);

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
		if (ans < bans) {
			bans = ans;
		}
		z = oz;
	}

	cout << bans << endl;
	return 0;
}