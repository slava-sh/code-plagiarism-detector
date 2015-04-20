#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define fname "che."
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long 

const int MAXN = 300500;
const int INF = 1 << 30;

ll n, k, a[MAXN], ans;
map < ll, ll > ind;
int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
		cin >> n >> k;
		for (ll i = 1; i <= n; i++)
			cin >> a[i];
		for (ll i = n; i >= 1; i--)
			ind[a[i]] = i;
		for (ll i = 1; i <= n; i++) {
			ll x = ind[*upper_bound(a + 1, a + n + 1, a[i] + k)];
			if (x != 0) {
				ans += n - x + 1;
			}
		}
		cout << ans;
			
	
	return 0;
}
