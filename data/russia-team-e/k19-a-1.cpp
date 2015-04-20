#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;
const int mod = 1000000007;
const int maxn = 200000;

int n, a[maxn], b[maxn];
long long ans;

int main()
{
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);

	cin >> n;

	for (int i = 1; i <= n; i++)
		cin >> a[i], b[i] = 2;

	if (a[1] != - 1 && a[1] != 0) {
		cout << 0;
		return 0;
	}

	b[1] = 0;

	for (int i = 2; i <= n; i++) {
		if (a[i] == - 1)
			continue;
		if (i + a[i] - 1 > n) {
			cout << 0;
			return 0;
		}
		for (int j = 1; j <= a[i]; j++) {
			if (b[j] == 2) {
				if (b[i + j - 1] != 2)
					b[j] = b[i + j - 1];
			} else {
				if (b[i + j - 1] == 2) {
					b[i + j - 1] = b[j];
				} else {
					if (b[j] != b[i + j - 1]) {
						cout << 0;
						return 0;
					}
				}
			} 
		}
		if (i + a[i] <= n) {
			if (b[a[i] + 1] == 2) {
				if (b[i + a[i]] != 2)
					b[a[i] + 1] = b[i + a[i]] ^ 1;
			} else {
				if (b[i + a[i]] == 2) {
					b[i + a[i]] = b[a[i] + 1] ^ 1;
				} else {
					if (b[a[i] + 1] == b[i + a[i]]) {
						cout << 0;
						return 0;
					}
				}
			}
		}
	}

	ans = 2;

   for (int i = 2; i <= n; i++)
   		if (b[i] == 2)
   			ans = (ans * 2ll) % mod;

   	cout << ans;
	return 0;
}
