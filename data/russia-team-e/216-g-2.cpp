#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
typedef long long ll;

using namespace std;

int main() {
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << (m + 1) / 4;
		return 0;
	}
	if (m == 1) {
		cout << (n + 1) / 4;
		return 0;
	}
	if (n == 2 || m == 2) {
		cout << 1;
		return 0;
	}
	cout << min((n + 1) / 4, (m + 1) / 4);
	return 0;
}