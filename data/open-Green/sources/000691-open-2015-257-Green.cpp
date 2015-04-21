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

ll ar[10];
vector <ll> del;
int dv;

int main(){
	freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	ll n;
	int k;
	cin >> n  >> k;
	for (int i = 0; i < k; ++i) {
		ar[i] = 1;
	}
	for (ll i = 2; i * i <= n; ++i) {
		while (!(n % i)) {
			if (i & 1LL) {
				del.push_back(i);
			}
			else {
				++dv;
			}
			n /= i;
		}
	}
	if (n != 1) {
		if (n & 1LL) {
			del.push_back(n);
		}
		else {
			++dv;
		}
	}
	int t = 0;
	for (int i = 0; i < (int)del.size(); ++i) {
		ar[t] *= del[i];
		t = (t + 1) % k;
	}
	t= k - 1;
	for (; dv; --dv) {
		ar[t] *= 2LL;
		t = (t - 1 + k) % k;
	}
	ll ans = 1;
	for (int i = 0; i < k; ++i) {
		ans *= (ar[i] / 2LL + ar[i] % 2LL);
	}
	cout << ans;
	return 0;
}