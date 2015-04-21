#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

using namespace std;

map <int, map <int, int> > mp;
vector <pair <int, int> > gr[100010];
int l;

int ans (int s, int f) {
	mp.clear();
	queue <pair <int, int> > q;
	q.push(make_pair(s, 1000000000));
	while (!q.empty()) {
		int v = q.front().first,
			t = q.front().second;
		q.pop();
		qwe++;
		if (qwe >= 10000000) break;
		int ll = 0, rr = gr[v].size();
		while (ll + 1 < rr) {
			int m = (ll + rr) / 2;
			if (gr[v][m].second < t - l) ll = m;
			else  rr = m;
		}
		if (t == 1000000000) ll = 0;
		for (int i = ll; i < gr[v].size(); i++) {
			if (abs(t - gr[v][i].second) > l && t != 1000000000 && i != ll) break;
			if (abs(t - gr[v][i].second) > l && t != 1000000000) continue;
			int nx = gr[v][i].first, nt = gr[v][i].second;
			if (mp[nx].find(nt) == mp[nx].end() || mp[nx][nt] > mp[v][t] + 1) {
				mp[nx][nt] = mp[v][t] + 1;
				q.push(make_pair(nx, nt));
			}
		}
	}
	if (mp.find(f) == mp.end()) return -1;
	int mn = 1000000000;
	for (map <int, int> ::iterator it = mp[f].begin(); it != mp[f].end(); ++it) {
		mn = min(mn, (*it).second);
	}
	return mn;
}

int main () {
	//freopen ("input.txt", "r", stdin);
	//freopen ("output.txt", "w", stdout);
	int n, m;
	scanf("%d%d%d", &n, &m, &l);
	for (int i = 1; i <= m; i++) {
		int q, w, e;
		scanf("%d%d%d", &q, &w, &e);
		gr[q].push_back(make_pair(w, e));
		gr[w].push_back(make_pair(q, e));
	}
	int qwe;
	scanf("%d", &qwe);
	for (int i = 0; i < qwe; i++) {
		int s, f;
		scanf("%d%d", &s, &f);
		printf("%d\n", ans(s, f));
	}
	//getchar();
	//getchar();
	return 0;
}