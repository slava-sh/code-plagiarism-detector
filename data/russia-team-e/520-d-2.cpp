#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

int n, k;
int a[100010];
int b[100010];

bool good(int x) {
	long long total = a[0];
	long long sum = a[0];
	for (int i = 1; i < n; i++) {
		total += max((long long)x, (long long)a[i] - sum);
		sum += max((long long)x, (long long)a[i] - sum);
	}
	return total <= k;
}

int main() {
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int l = 0;
	int r = a[0] + 1;
	while (r > l + 1) {
		int m = (l + r) / 2;
		if (good(m)) {
			l = m;
		} else {
			r = m;
		}
	}
	cout << l;
	//good(2);
}