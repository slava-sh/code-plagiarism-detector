#define _CRT_SECURE_NO_DEPRECATE
#define _USE_MATH_DEFINES

#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <iterator>
#include <cstdio>
#include <memory.h>
#include <iostream>
#include <cmath>
#include <queue>

#pragma comment(linker, "/STACK:64000000")

using namespace std;

#define mp make_pair
#define pi M_PI

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<double, double> pdd;
typedef pair<ld, ld> pldld;

const int infi = (int)1e9 + 7;
const ll infl = (ll)1e18 + 7;
const ld eps = (ld)(1e-8);
const int it = 1000000;

pll ar[200500];
ll uch[200500];
ll sum[200500];

int main(){
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	ll n, k, c, d;
	cin >> n >> k >> c >> d;
	for (int i = 0; i < n; ++i) {
		cin >> ar[i].first >> ar[i].second;
	}
	if (n == 1) {
		cout << (ar[0].second - ar[0].first) * d;
		return 0;
	}
	ll l = ar[0].second;
	for (int i = 1; i < n; ++i) {
		uch[i - 1] = ar[i].first - l;
		l = ar[i].second;
	}
	sort(uch, uch + n - 1);
	reverse(uch, uch + n - 1);
	for (int i = 0; i < n - 1; ++i) {
		if (i) {
			sum[i] += sum[ i - 1];
		}
		sum[i] += uch[i] * d;
	}
	ll ans = infl * 8LL;
	ll s = (ar[n - 1].second - ar[0].first) * d;
	for (ll i = 1; i <= n; ++i) {
		ll q = (k - 1) * i + i - 1;
		q = min(q, n - 1);
		ll a = s + i * c - c;
		if (q) {
			a -= sum[q - 1];
		}
		ans = min(ans, a);
	}
	cout << ans;

	return 0;
}