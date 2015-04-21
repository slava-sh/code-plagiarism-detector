#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

typedef long long ll;

ll n;
int k;
map < pair < ll, int >, ll > mem;
map < pair < ll, int >, ll > :: iterator it;

ll get(ll n, int k) {
	if (k == 1) return (n + 1LL) / 2LL;
	it = mem.find(mp(n, k));
	if (it != mem.end()) return it -> S;
	ll res = (ll)1e18;
	for (ll i = 2LL; i * i <= n; i++)
		if (n % i == 0LL) {
			ll d1 = i;
			ll d2 = n / i;
			ll k1 = (n / d1 + 1LL) / 2LL;
			ll k2 = (n / d2 + 1LL) / 2LL;
			res = min(res, k1 * get(n / d1, k - 1));
			res = min(res, k2 * get(n / d2, k - 1));
		} 	
	mem.insert(mp(mp(n, k), res));
	return res;
}

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scf("%lld%d", &n, &k);
	prf("%lld\n", get(n, k));
	return 0;
}