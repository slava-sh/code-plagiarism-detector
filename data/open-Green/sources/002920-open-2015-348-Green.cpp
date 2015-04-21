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



int main(){
#ifdef local
	freopen(task ".in", "r", stdin);
	freopen(task ".out", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	ll n, k, m, ans = 1e18;

	cin >> n >> k;
	m = n;

	/*map<ll, int> p;
	for (ll i = 2; i * i <= m; i++){
		while (m % i == 0){
			p[i]++;
			m /= i;
		}
	}

	ll ans = 1;
	ll cur = pow(n, 1 / (ld)k);
	for (int i = 0; i < k; i++){
		ll num = p.rbegin()->first;
		if (num >= cur){
			ans *= (num + 1) / 2;
			if (p.rbegin())
		}
	}*/

	ll cur = pow(n, 1 / (ld)k);
	for (ll i = max(cur - 1000, 1ll); i <= min(cur + 1000, n); i++){
		int it = k;
		ll m = n;
		ll cur_ans = 1;
		for (ll j = i; j * j <= m && it; j++){
			while (m % j == 0 && it){
				cur_ans *= (j + 1) / 2;
				m /= j;
				it--;
			}
		}
		if (m != 1 && it){
			cur_ans *= (m + 1) / 2;
		}
		else if (m != 1){
			cur_ans = 1e18;
		}
		ans = min(ans, cur_ans);
	}

	cout << ans;
	
	return 0;
}