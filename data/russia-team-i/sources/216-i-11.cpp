#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
typedef long long ll;

using namespace std;

map<int, set<int> > mp;

ll a[111111];

int main(){
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	ll n, d;
	cin >> n >> d;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	ll uk = n + 1;// укакзатель на первое >= 3d
	ll x = n + 1;// укакзатель на первое >= d, <= 3d
	bool b = 1, bb = 1;
	if (n == 1) {
		cout << a[1];
		return 0;
	}
	if (a[n] < d) {
		cout << a[n];
		return 0;
	}	
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (a[i] >= 3 * d) {
			uk = i;
			break;
		}
		if (a[i] >= d && b) {
			x = i;
			b = 0;
		}
	}	
	if (uk > n) {
		ll v = n - x + 1;
		if (v >= 2) {
			cout << max(a[n] - d + a[n - 1] - d, a[n]);
			return 0;
		}
		if (v == 1) {
			cout << a[n];
		return 0;
		}
	}
	if (x > n) {
		for (ll i = uk; i <= n; i++) 
			ans += a[i] - d - d;
		ans += d + d;
		cout << max(ans, a[n]);
		return 0;
	}
	for (ll i = uk; i <= n; i++) 
		ans += a[i] - d - d;
	if (uk - x >= 2) {
		cout << max(ans + d + d, ans + a[uk - 1] - d + a[uk - 2] - d);
		return 0;
	}
	if (uk - x == 1) {
		ans += a[uk - 1] - d + d;
		cout << max(ans, a[n]);
		return 0;
	}
	if (uk - x == 0) {
		ans += d + d;
		cout << max(ans, a[n]);
		return 0;
	}
}
	
	
	/*if (x == 0) {
		ans += a[n] - d;
		ans += a[n - 1] - d;
		for (ll i = 1; i <= n -2; i++)
			ans += a[i] - d- d;
		cout << ans;
		return 0;
	}
	if (uk - x >= 2)
		p = a[uk - 1], k = a[uk - 2];
	if (uk - x == 1 || n - x == 0) {
		p = a[x];
		o = 2;
	}
	if (uk - x == 0)
		b = 0;
	if (b) {
		if (n - uk == 0) {
			cout << a[n];
			return 0;
		}
		ans += a[n] - d;
		ans += a[n - 1] - d;
		for (ll i = uk; i <= n - 2; i++)
			ans += a[i] - d - d;
		cout << ans; 
		return 0;
	}
	if (uk == 0) {
		if (o == 2) {
			cout << p;
			return 0;
		}
		cout << a[n] - d + a[n - 1] - d;
		return 0;
	}
	if (o == 2) {
		ans += p - d;
		ans += a[n] - d;
		for (ll i = uk; i <= n - 1; i++) 
			ans += a[i] - d - d;
		cout << ans;
		return 0;
	}
	ans += p - d + k - d;
	for (ll i = uk; i <= n; i++)
		ans += a[i] - d - d;
	cout << ans;
	return 0;
}*/