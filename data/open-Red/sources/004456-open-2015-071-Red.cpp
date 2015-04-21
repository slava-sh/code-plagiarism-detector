#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <set>
#include <ctime>
#include <cstring>
#include <string>
#include <cstdlib>
#include <stack>
#include <queue>


using namespace std;

#define pb push_back
#define mp make_pair


typedef long long ll;
typedef long double ld;
typedef double db;
typedef unsigned long long ull;
const int Q = 1e9 + 7;
const int M = 2e3 + 10;

vector<int> g;
int d[M][M];
pair<int, int> q[M];
vector<pair<int, int> > ed[M];
pair<int, int> arr[M];

int obr(int i, int j){
	if (arr[i].first == j)
		return arr[i].second;
	return arr[i].first;	
}
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int i, j, l, r, qw, n, m, u, v, t, D, a, b, ans;
	pair<int, int> cur;
	scanf("%d%d%d", &n, &m, &D);
	for (i = 0; i < m; i++){
		scanf("%d%d%d", &u, &v, &t);
		if (u == v){
			ed[u].pb(mp(u, i));
		}
		else{
			ed[u].pb(mp(v, i));
			ed[v].pb(mp(u, i));
		}
		g.pb(t);
		arr[i] = mp(u, v);
	}
/*	for (i = 1; i <= n; i++){
		for (j = 0; j < (int)ed[i].size(); j++)
			for (k = j + 1; k < (int)ed[i].size(); k++)
				if (abs(g[ed[i][j]] - g[ed[i][k]]) <= D){
					G[ed[i][k]].pb(ed[i][j]);
					G[ed[i][j]].pb(ed[i][k]);
				}
	}                   */
	scanf("%d", &qw);
	while (qw--){       	
		scanf("%d%d", &a, &b);
		for (i = 0; i < m; i++)
			for (j = 0; j <= n; j++)
				d[i][j] = Q;
		l = r = 0;
		for (i = 0; i < (int)ed[a].size(); i++){
			d[ed[a][i].second][ed[a][i].first] = 0;
			q[r++] = mp(ed[a][i].second, ed[a][i].first);
		}
		while (l != r){
			cur = q[l++];
			cerr << cur.first << " " << cur.second <<endl;
		
			for (j = 0; j < (int)ed[cur.second].size(); j++){                                 	
				int t = obr(ed[cur.second][j].second, cur.second);
				if (abs(g[cur.first] - g[ed[cur.second][j].second]) <= D &&  d[ed[cur.second][j].second][t] == Q){
					q[r++] = mp(ed[cur.second][j].second, t);
					d[ed[cur.second][j].second][t] = d[cur.first][cur.second] + 1;
				}
			}
		}
		ans = Q;
		for (i = 0; i < (int)ed[b].size(); i++)
			ans = min(ans, d[ed[b][i].second][b]);
		printf("%d\n", ((ans == Q) ? -1 : ans + 1));
	}
	return 0;
}