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
	cout << min((n + 2) / 4, (m + 2) / 4);
	return 0;
}