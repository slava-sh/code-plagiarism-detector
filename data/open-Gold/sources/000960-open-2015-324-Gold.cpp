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
#include <functional>
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

ll n, k, c, d;
pair<ll, ll> a[MAXN];
ll diff[MAXN];
ll sum;	

ll check(int m) {
	int cnt = m * k;
	ll ans = c * (m - 1);
	for (int i = cnt - 1; i < n - 1; i++) {
		ans += diff[i] * d;
	}
	return ans;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> k >> c >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
		sum += (a[i].second - a[i].first) * d;
	}
	
	for (int i = 1; i < n; i++) {
		diff[i - 1] = a[i].first - a[i - 1].second;
	}
	sort(diff, diff + (n - 1), greater<ll>());
	
	int l = 1;
	int r = n / k + 1;
	while (r - l > 2) {
		int m1 = (l * 2 + r) / 3;
		int m2 = (l + r * 2) / 3;
		debug("l = %d, r = %d\nm1 = %d, m2 = %d;\n", l, r, m1, m2);
		debug("check(m1) = %d\ncheck(m2) = %d\n___________________\n", (int)check(m1), (int)check(m2));
		if (check(m1) < check(m2)) {
			r = m2;
		} else {
			l = m1;
		}
	}
	
	debug("l = %d, r = %d;\n", l, r);
	debug("check(l) = %d\ncheck(r) = %d\ncheck((l + r) / 2) = %d\n", (int)check(l), (int)check(r), (int)check((l + r) / 2));
	cout << sum + min({check(l), check(r), check((l + r) / 2)});
		
	return 0;
}
