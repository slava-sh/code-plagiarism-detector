#pragma comment(linker, "/STACK:256000000")
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <queue>
#include <cmath>
#include <set>
#include <map>

#define localn
#define task "paul"
#define ll long long
#define ld long double
#define pii pair<int, int>
#define mp make_pair
#define N 100010

using namespace std;

const ld eps = 1e-9;
const int inf = 1e9 + 7, M = 1e9 + 7;



vector<pii> g[N];

int main(){
#ifdef local
	freopen(task ".in", "r", stdin);
	freopen(task ".out", "w", stdout);
#endif

	cout << fixed;
	cout.precision(10);

	int n, m, dif, tt, i, k, u, v, t;
	cin >> n >> m >> dif;

	for (i = 0; i < m; i++){
		scanf("%d %d %d", &u, &v, &t);
		g[v].push_back(mp(u, t));
		g[u].push_back(mp(v, t));
	}

	cin >> tt;
	for (i = 0; i < tt; i++){
		queue< pair<int, pii> > q;
		set<pii> mark;
		cin >> u >> v;
		for (k = 0; k < g[u].size(); k++){
			q.push(mp(1, mp(g[u][k].first, g[u][k].second)));
			mark.insert(mp(g[u][k].first, g[u][k].second));
		}
		bool ok = 1;
		while (!q.empty()){
			int path = q.front().first,
				a = q.front().second.first,
				pt = q.front().second.second;
			q.pop();

			if (a == v){
				cout << path << endl;
				ok = 0;
				break;
			}

			for (k = 0; k < g[a].size(); k++){
				int to_v = g[a][k].first, to_t = g[a][k].second;
				if (to_v == u || abs(to_t - pt) > dif){
					continue;
				}
				if (mark.find(mp(to_v, pt)) == mark.end()){
					mark.insert(mp(to_v, pt));
					q.push(mp(path + 1, mp(to_v, to_t)));
				}
			}
		}
		if (ok){
			cout << "-1\n";
		}
	}

	return 0;
}