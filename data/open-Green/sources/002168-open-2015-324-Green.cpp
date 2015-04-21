#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <list>
#include <bitset>
#include <cstring>
#include <string>
// C++11 Headers
#include <tuple>
#include <initializer_list>
// *C++11 Headers

#ifdef DEBUG
	#define debug printf
	#define reader scanf
#else
	#define debug ;
	#define reader ;
#endif

#define ll long long

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;

ll fast_pow(ll a, int k) {
	ll b = a;
	ll x = 1;
	while (k > 0) {
		if (k % 2) {
			x *= b;
			k--;
		} else { 
			b *= b;
			k /= 2;
		}
	}
	return x;
}

ll n, k;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
		
	cin >> n >> k;
	
	while (n % 2 == 0 && k > 0) {
		k--;
		n /= 2;
	}
	
	ll ans = 1;
	while (k > 0) {
		ll best = 1;
		for (int i = 2; fast_pow(i, k + 1) <= n; i++) {
			if (n % i == 0) {
				best = i;
			}
		}
		ans *= (best + 1) / 2;
		n /= best;
		k--;
	}
	
	cout << ans * (n + 1) / 2 << '\n';
		
	return 0;
}
