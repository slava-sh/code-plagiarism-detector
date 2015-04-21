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
ll dp[200500][10];
int bin(ll a) {
	int l = 0, r = (int)del.size();
	while (l <= r) {
		int m = (l + r) >> 1;
		if (del[m] == a) {
			return m;
		}
		if (del[m] < a) {
			l = m + 1;
		}
		else {
			r = m - 1;
		}
	}
}

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
		if (!(n % i)) {
			del.push_back(i);
			if (i * i != n) {
				del.push_back(n / i);
			}
		}
	}
	del.push_back(n);
	sort(del.begin(), del.end());
	int m = (int)del.size(); 
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < k; ++j) {
			dp[i][j] = infl;
		}
	}
	for (int i = 0; i < m; ++i) {
		dp[i][0] = del[i] / 2 + del[i] % 2;
	}
	for (int j = 1; j < k; ++j) {
		for (int i = 0; i < m; ++i) {
			for (int q = 0; q <=i; ++q) {
				if (del[i] % del[q]) {
					continue;
				}
				ll a = del[i] / del[q];
				a = a/ 2 + a % 2;
				dp[i][j] = min(dp[i][j], dp[q][j - 1] * a);
			}
		}
	}
	cout << dp[m -1][k - 1];

	return 0;
}