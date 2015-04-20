#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#define ll long long

using namespace std;

ll n, ans = 0, d[1000000], r, a[1000000], dl[100000], k = 1000000, j;

int main () {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	
	cin >> n >> r;

	for(int i = 1; i <= n; i++) {
		cin >> d[i];	
		a[i] = 0;
	}

	for(int i = n; i > 0; i--) {
		j = i - 1;
		while(d[i] - r <= d[j] && j > 0) {
			j--;
		}	
		ans += j;
	}

	cout << ans;
	return 0;
}
