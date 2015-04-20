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
#define FNAME "che"

using namespace std;

typedef long long ll;

const int INF = 1e9;
const int MAX_N = 300500;

int n, r;
int a[MAX_N];

void solve() {
	scanf("%d%d", &n, &r);
	for (int i = 0;i < n;++i)
		scanf("%d", &a[i]);
	sort(a, a + n);
	int l = 0;
	ll res = 0;
	for (int i = 0;i < n;++i) {
		while (a[i] - a[l] > r)
			++l;
		res += l;
	}
	cout << res << endl;
}

int main() {
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout);
	solve();
	return 0;
}
