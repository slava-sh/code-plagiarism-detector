#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double

const ll MAXN = 100100;

ll a[MAXN], n, k;

char check(ll x){
	if (a[0] < x) return false;
	ll r = a[0];
	for (ll i = 1; i < n; i++){
		ll nx = a[i] - r;
		r += max(nx, x);
		if (r > k) return false;
	}
	return true;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
#endif
	cin >> n >> k;
	for (ll i = 0; i < n; i++)
		cin >> a[i];

	sort(a, a + n);

	ll l = 0, r = k + 1;//k / n + k % n + 1;
	while (r > l){
		ll m = (l + r) / 2;
		if (check(m))
			l = m + 1;
		else
			r = m;
	}
	cout << l - 1;
	return 0;
}