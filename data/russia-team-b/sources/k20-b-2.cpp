#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define fname "che"
#define pb push_back
#define mp make_pair
#define F first
#define forp(i, a, b) for(int i = a; i <= b; ++i)
#define form(i, a, b) for(int i = a; i >= b; --i)

ll a[300001], f[300001];

int main() {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	ll ans = 0;
	ll n, d;
	cin >> n >> d;
	forp(i, 1, n)
		cin >> a[i];
	ll l = 1, r = 1, v = 1;
	while(true) {
		if(r > n || r == n && a[r] - a[l] <= d) break;
		if(a[r] - a[l] > d) {
			ans++; ++l; continue;
		} else {
			ans += l - 1;
			++r; continue;
		}
		v = r;
	}
	cout << ans; 
			
	return 0;
}