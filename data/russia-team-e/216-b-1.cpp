#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>

using namespace std;

int a[300010];

int main() {
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	int n, r;
	cin >> n >> r;
	int  uk = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > a[uk] + r - 1) {
			ans += uk - 1;
			uk = i;
		}
	}
	cout << uk;
	return 0;
}