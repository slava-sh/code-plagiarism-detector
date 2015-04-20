#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define fname "fence."
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()

const int MAXN = 100500;
const int INF = 1 << 30;

int n, k, a[MAXN];

bool check(int x) {
	int cur = 0;
	for (int i = 1; i <= n; i++) 
		if (a[i] < x) return 0;
	cur = a[1];
	for (int i = 2; i <= n; i++)
		cur = max (a[i], cur + x);
	if (cur <= k) return 1;
	return 0;
}

int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
		cin >> n >> k;
		for (int i = 1; i <= n; i++)	
			cin >> a[i];
		sort(a + 1, a + n + 1);
		int l = 0, r = INF, ans = 0;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (check(mid)) {
				l = mid + 1;
				ans = mid;
			}
			else
				r = mid - 1;
		}
		cout << ans;
	return 0;
}
