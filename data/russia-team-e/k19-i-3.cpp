#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>

using namespace std;

const int maxn = 1000000;

long long d[maxn][5], was[maxn][5], ans, a[maxn], dp, n;

long long calc(int v, int cnt) {
	if (was[v][cnt])
		return d[v][cnt];

	was[v][cnt] = 1;
			
	if (v >= n) {
		d[v][cnt] = 0;
		return 0;
	}

	if (cnt < 2 && a[v] - dp > 0)
		d[v][cnt] = max(d[v][cnt], calc(v + 1, cnt + 1) + a[v] - dp);
	if (a[v] - dp - dp >= dp)
		d[v][cnt] = max(d[v][cnt], calc(v + 1, cnt) + a[v] - dp - dp);
	d[v][cnt] = max(d[v][cnt], calc(v + 1, cnt));

	return d[v][cnt];	
}

int main()
{
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> dp;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
		ans = max(ans, a[i]);
	}

	cout << max(calc(0, 0), ans);

	return 0;
}

