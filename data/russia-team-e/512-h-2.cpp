#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


const int MAXN = 1e9;
int n, m, u, v, c, x, y, ans = MAXN;
vector <int> yandex, mail;
vector <vector <pair <int, int> > > a;
set <pair <int, int> > se;
vector <int> dist;

void init (int v) {
	dist.resize(n + 1, MAXN);
	dist[v] = 0;
	for (int i = 1; i <= n; i++) {
		if (i != v) {
			se.insert(make_pair(MAXN, i));
		} else {
			se.insert(make_pair(0, i));
		}
	}
}

void dey (int v) {
	init(v);
	while (!se.empty()) {
		int v = se.begin()->second;
		int w = se.begin()->first;
		if (w >= ans) {
			return;
		}
		se.erase(se.begin());
		for (int i = 0; i < a[v].size(); i++) {
			int to = a[v][i].second;
			if (dist[to] > w + a[v][i].first) {
				se.erase(make_pair(dist[to], to));
				dist[to] = w + a[v][i].first;
				se.insert(make_pair(dist[to], to));
			}
		}
	}
}

int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("secure.in", "r", stdin);freopen("secure.out", "w", stdout);
	cin >> n >> m;
	a.resize(n + 1);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &u);
		if (u == 1) {
			mail.push_back(i);
		}
		if (u == 2) {
			yandex.push_back(i);
		}
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d", &u);
		scanf("%d", &v);
		scanf("%d", &c);
		a[u].push_back(make_pair(c, v));
		a[v].push_back(make_pair(c, u));
	}
	if (mail.size() < yandex.size()) {
		for (int i = 0; i < mail.size(); i++) {
			dey(mail[i]);
			for (int j = 0; j < yandex.size(); j++) {
				if (dist[yandex[j]] < ans) {
					x = mail[i];
					y = yandex[j];
					ans = dist[yandex[j]];
				}
			}
		}
	} else {
		for (int i = 0; i < yandex.size(); i++) {
			dey(yandex[i]);
			for (int j = 0; j < mail.size(); j++) {
				if (dist[mail[j]] < ans) {
					y = yandex[i];
					x = mail[j];
					ans = dist[mail[j]];
				}
			}
		}
	}
	if (ans == MAXN) {
		cout << -1;
	} else {
		cout << x << ' ' << y << ' ' << ans;
	}
	return 0;
}