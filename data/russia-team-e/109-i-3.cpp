#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long li;

#define pb push_back

/*struct nd {
	int mx1, mx2;
	int pr;
} g[200005];

vector<int> a[200005];

void dfs(int v, int pr = -1) {
	int i, to;
	g[v].pr = pr;
	for (i = 0; i < a[v].size(); i++) {
		if (a[v][i] != pr) {
			to = a[v][i];
			dfs(a[v][i], v);
			if (g[to].mx1 > g[v].mx1) {

			}
		}
	}
}*/

int main() {
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n, d, a[100005], i, k;
	cin >> n >> d;
	for (i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	i = n - 1;
	while (i != -1 && a[i] >= 3 * d)
		i--;
	i++;
	if (i != 0) {
		if (a[i - 1] > d)
			i--;
	}
	if (i != 0) {
		if (a[i - 1] > d)
			i--;
	}
	k = n - i;
	int s = 0;
	for (; i < n; i++) {
		s += a[i];
	}
	if (k == 0) {
		cout << a[n - 1];
		return 0;
	}
	k--;
	int ans = s - k * 2 * d;
	cout << ans;
	/*int n, i, x, y, s1, s2;
	cin >> n;
	for (i = 0; i < n - 1; i++) {
		cin >> x >> y;
		x--;
		y--;
		a[x].pb(y);
		a[y].pb(x);
	}
	dfs(s1);*/
	return 0;
}
/*
8 3
9 1 8 10 6 5 12 16

*/