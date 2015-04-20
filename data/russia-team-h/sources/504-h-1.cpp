#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int a[5010];
vector <pair <int, int> > ed[5010];

int inf = 1000000000;

int main() {
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < m; i++) {
		int x, y, w;
		scanf("%d %d %d", &x, &y, &w);
		ed[x].push_back(make_pair(y, w));
		ed[y].push_back(make_pair(x, w));
	}
	set <pair <int, int> > s;
	int d[5010];
	int h[5010];
	for (int i = 1; i <= n; i++) {
		if (a[i] == 1) {
			d[i] = 0;
			h[i] = i;
			s.insert(make_pair(0, i));
		} else {
			d[i] = inf;
			h[i] = -1;
		}
	}
	while (!s.empty()) {
		int vert = (*s.begin()).second, w = (*s.begin()).first;
		s.erase(s.begin());
		for (int i = 0; i < (int)ed[vert].size(); i++) {
			int u = ed[vert][i].first;
			if (d[vert] + ed[vert][i].second < d[u]) {
				s.erase(make_pair(d[u], u));
				d[u] = d[vert] + ed[vert][i].second;
				s.insert(make_pair(d[u], u));
				h[u] = h[vert];
			}
		}
	}
	int x, y, ans = inf;
	for (int i = 1; i <= n; i++) {
		if (a[i] == 2 && d[i] < ans) {
			x = h[i];
			y = i;
			ans = d[i];
		}
	}
	if (ans == inf) {
		printf("-1");
		return 0;
	}
	printf("%d %d %d", x, y, ans);
}
