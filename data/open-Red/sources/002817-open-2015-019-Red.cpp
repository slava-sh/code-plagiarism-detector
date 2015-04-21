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
		for (int i = 0; i < gr[v].size(); i++) {
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
	cin >> n >> m >> l;
	for (int i = 1; i <= m; i++) {
		int q, w, e;
		cin >> q >> w >> e;
		gr[q].push_back(make_pair(w, e));
		gr[w].push_back(make_pair(q, e));
	}
	int qwe;
	cin >> qwe;
	for (int i = 0; i < qwe; i++) {
		int s, f;
		cin >> s >> f;
		cout << ans(s, f) << endl;
	}
	//getchar();
	//getchar();
	return 0;
}