#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <cmath>
#include <cassert>
#include <map>
#include <set>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <utility>

#define pb(x) push_back(x)
#define fi first
#define se second
#define mp make_pair
#define FNAME "prizes"

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MAX_N = 100;

ll n, m;

void solve() {
	cin >> n >> m;
	if (n == 1) {
		cout << (m + 1) / 4;
		return;
	}
	if (m == 1) {
		cout << (n + 1) / 4;
		return;
	}
	if (n == 2) {
		cout << 0;
		return;
	}
	if (m == 2) {
		cout << 0;
		return;
	}
	cout << 1;
	return;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
