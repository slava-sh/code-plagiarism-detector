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

ll a[300010];

int main() {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	ll n, r;
	cin >> n >> r;
	ll  uk = 1;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
	}
	ll ans = 0;
	for (ll i = 1; i <= n; i++) {
		if (a[i] > a[uk] + r) {
			//ans += uk - 1;
			ans += n - i + 1;
			uk++;
			i--;
		}
	}
	cout << ans;
	return 0;
}