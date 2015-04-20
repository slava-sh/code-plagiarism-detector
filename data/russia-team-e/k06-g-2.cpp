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
const int MAX_N = 100500;

void solve() {
	ll n, m;
	cin >> n >> m;
	if (min(n, m) <= 2) {
		cout << 0;
		return;
	}
	cout << min((n - 2) / 4, (m - 2) / 4) + 1;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
