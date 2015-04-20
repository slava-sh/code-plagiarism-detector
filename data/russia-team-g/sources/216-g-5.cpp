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
	long long n, m;
	cin >> n >> m;
	if (n == 1) {
		cout << (m + 1) / 4;
		return 0;
	}
	if (m == 1) {
		cout << (n + 1) / 4;
	}
	cout << (min (n, m) + 1) / 4;
	return 0;
}