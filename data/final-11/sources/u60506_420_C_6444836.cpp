#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int MAXN = 3e5 + 10;
int d[MAXN], ans[MAXN];
set<int> ng[MAXN];
map<pii, int> mp;

int main() {
	ios::sync_with_stdio(false);
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if (x > y)
			swap(x, y);
		x--; y--;
		ng[x].insert(y);
		ng[y].insert(x);
		ans[x]++; ans[y]++;
		d[x]++; d[y]++;
		if (mp.find(pii(x, y)) == mp.end())
			mp[pii(x, y)] = 1;
		else
			mp[pii(x, y)]++;
	}
	sort(ans, ans + n);
	ll jav = 0;
	for (int i = 0; i < n; i++) {
		int cur = n - (lower_bound(ans, ans + n, p - d[i]) - ans);
		if (d[i] >= p - d[i])
			cur--;
		for (set<int>::iterator it = ng[i].begin(); it != ng[i].end(); it++) {
			int u = *it;
			if (d[u] + d[i] >= p)
				cur--;
			int tmp = mp[pii(min(u, i), max(u, i))];
			if (d[u] + d[i] - tmp >= p)
				cur++;
		}
		jav += cur;
	}
	jav >>= 1;
	cout << jav << endl;
	return 0;
}
