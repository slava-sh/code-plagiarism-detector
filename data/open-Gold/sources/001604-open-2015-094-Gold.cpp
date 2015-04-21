#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
#define MOD 1000000007LL
#define P 5
using namespace std;
ll a[200500], b[200500];
ll sum[200500];
int main(void) {
	ll n, k, c, d;
	scanf("%lld%lld%lld%lld", &n, &k, &c, &d);
	for (int i = 0; i < n; ++i) {
		scanf("%lld%lld", &a[i], &b[i]);
	}
	ll ans = 1000000000000000000LL;
	for (int i = 1; i < n; ++i) {
		sum[i - 1] = a[i] - b[i - 1];
	}
	sort(sum, sum + n - 1);
	reverse(sum, sum + n - 1);
	for (int i = 1; i < n - 1; ++i)
		sum[i] += sum[i - 1];
	ll t = b[n - 1] - a[0];
	t *= d;
	ans = t;
	if ((k > 1) && (n > 1)) {
		ans -= sum[min(n - 2, k - 2)]; 
	}
	if (n > 1) {
		for (ll tk = 1;; ++tk) {
			ans = min(ans, t - sum[min(n - 2, tk * k + k - 2)] * d + tk * c);
			if (tk * k - 1 >= n - 2) break;
		}
	}
	cout << ans << endl;
}