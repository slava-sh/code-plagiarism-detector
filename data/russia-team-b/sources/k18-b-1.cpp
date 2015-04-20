#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#define ll long long

using namespace std;

ll n, ans = 0, d[300001], r;

int main () {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	cin >> n >> r;

	for(int i = 1; i <= n; i++) {
		cin >> d[i];	
	}
	for(int i = n; i >= 1; i--) {
		ll j = i - 1;
		while(d[i] - d[j] <= r && j > 0) {
			j--;	
		}
		ans += j;
	}
	cout << ans;
	return 0;
}
