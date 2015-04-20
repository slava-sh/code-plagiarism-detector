#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <cstdio>
#define ll long long

using namespace std;

int n, ans = 0, d, r, a[100000], o = 1, k = 0, b[100000];

int main () {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	
	cin >> n >> d;

	for(int i = 1; i <= n; i++) {
		cin >> a[i];	
	}

	for(int i = 1; i <= n; i++) {
		if(a[i] < 3*d && a[i] >= 2*d) {
			b[o] = a[i];
			o++;
	   	} else if(a[i] >= 3*d){ 
			k++;
			ans += a[i];
		}	
	}

	sort(b + 1, b + o + 1);
	
	int ma;
	int m;
	if(o > 2) {
		ma = b[o];
		m = b[o - 1];
		cout << ans + ma + m - 2*d - 2*k*d;
	} else if(o == 2) {
		ma = b[o];
		cout << ans + ma - 2*d - 2*(k-1)*d;
	} else {
		cout << ans - 2*d - 2*(k-2)*d;
	}
	
	return 0;
}
