#include <iostream>
using namespace std;

int main() {
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);

	int n, m, ans = 0;
	cin >> n >> m;
	if(n > m) swap(n, m);

	if(n == 1) cout << m/3;
	else cout << n/3;
	return 0;
}