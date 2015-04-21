#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define localn
#define task "paul"
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 100010

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



map< pair<ll, int>, ll> dp;

ll calc(ll n, int k){
	if (k == 1){
		return (n + 1) / 2;
	}
	if (dp.find(mp(n, k)) != dp.end()){
		return dp[mp(n, k)];
	}
	ll res = 1e18;
	for (ll i = 1; i * i <= n; i++){
		if (n % i == 0){
			res = min(res, (n / i + 1) / 2 * calc(i, k - 1));
			res = min(res, (i + 1) / 2 * calc(n / i, k - 1));
		}
	}
	dp[mp(n, k)] = res;
	return res;
}

int main(){
#ifdef local
	freopen(task ".in", "r", stdin);
	freopen(task ".out", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	ll n, k, m, ans = 1e18;

	cin >> n >> k;
	cout << calc(n, k);
	
	return 0;
}