#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <time.h>
using namespace std;

#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define INF 2e9
#define mod 1000000007
#define fi first
#define se second
#define fname "fence"
#define re return

typedef long long ll;

ll n, k, a[200000];

bool ok(ll x) {
	ll cnt = 0, kk = k;
	for(int i = 1; i <= n; i++) {
		ll p = max(x, a[i] - cnt);
		if(k - cnt < x) re 0;
		kk -= p;
		cnt += p;
	}
	re 1;
}

int main() {
	
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);

	cin >> n >> k;

	for(int i = 1; i <= n; i++)
		cin >> a[i];

	sort(a + 1, a + n + 1);
	
	ll l = -1, r = a[1] + 1;
	while(r - l > 1) {
		ll m = (l + r) / 2;
		if(ok(m)) l = m; else r = m;
	}
	cout << l;
}