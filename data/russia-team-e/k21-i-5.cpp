#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>

using namespace std;

long long n, d, a[1000000];
long long b[1000000];

int main () { 
	
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	
	cin >> n >> d;
	long long k = 0;
	for (long long i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] > 2 * d) {
			b[k] = a[i];
			k++;
			}
		}
	sort (b, b + k);
	if (k == 0) {
		sort(a, a + n);
		cout << a[n - 1];
		exit(0);
	}
	b[0] += d;
	b[k - 1] += d;
	long long ans = 0;
	for (int i = 0; i < k; i++) {
		ans += b[i];
		ans -= 2 * d;
	}
	if (ans != 0)
		cout << ans;
	else
		cout << b[k - 1];
	return 0;
}

