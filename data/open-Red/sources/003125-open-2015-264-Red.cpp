#include <iostream>
#include <fstream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <random>
#include <map>
#include <algorithm>
#include <ctime>
#include <stack>
#include <queue>
#include <cmath>


#define ll long long
#define mp make_pair
#define pb push_back
#define pii pair <int, int>
#define S second
#define F first


const int INF = int(1e9) + 7;

using namespace std;

int n, m, D, qq, ans = INF;
vector < vector <pii> > g;


int main(){
//	ifstream cin ("test.in");
	cin >> n >> m >> D;
	g.resize(n);
	for (int i = 0; i < m; i++){
		int t1, t2, c; cin >> t1 >> t2 >> c;
		g[t1 - 1].pb(mp(c, t2 - 1));
		g[t2 - 1].pb(mp(c, t1 - 1));
	}
	for (int i = 0; i < n; i++){
		sort(g[i].begin(), g[i].end());
	}
	cin >> qq;
	for (int w = 0; w < qq; w++){
		map <pii, char> used;
		map <pii, int> d;
		ans = INF;

		int v1, v2; cin >> v1 >> v2; v1--; v2--;
		queue <pii> q;
		for (int i = 0; i < g[v1].size(); i++){
			q.push(g[v1][i]);
			d[g[v1][i]] = 1;
		}
		while (!q.empty()){
			pii vv = q.front();
			q.pop();
			int v = vv.S, t = vv.F;
			if (v == v2){
				ans = min(d[vv], ans);
			}
			used[vv] = 0;
			for (int i = max(0, lower_bound(g[v].begin(), g[v].end(), mp(t - D, -1)) - g[v].begin() - 2); i < min(int(g[v].size()), upper_bound(g[v].begin(), g[v].end(), mp(t + D, INF)) - g[v].begin() + 2); i++){
				if (abs(g[v][i].F - t) <= D){
					if (!d[g[v][i]] || d[vv] + 1 < d[g[v][i]]){
						d[g[v][i]] = d[vv] + 1;
						if (!used[g[v][i]]){
							used[g[v][i]] = 1;
							q.push(g[v][i]);
						}
					}
				}
			}
		}
		if (ans == INF) cout << -1 << '\n';
		else cout << ans << '\n';
	}
	return 0;
}