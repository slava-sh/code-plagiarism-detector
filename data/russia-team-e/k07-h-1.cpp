#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <cassert>
#include <cstdio>
#include <algorithm>

using namespace std;
#define fname "secure"
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long
const int N = 5555;
vector < pair<int, int> > g[5050];
int n,m,i,j,x,y,z;
int a[5555];
int d[5555];

int a1[N], a2[N], ans = 1000000000;

set <pair<int, int> > s;

int main() {
            
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i) {
		scanf("%d",&a[i]);
		if (a[i] == 1) a1[++a1[0]] = i;
		else if(a[i] == 2) a2[++a2[0]] = i;
	}
	for(i=1;i<=m;++i){
		scanf("%d%d%d",&x,&y,&z);
		g[x].pb(mp(y,z));
		g[y].pb(mp(x,z));
	}

	if (a1[0] < a2[0]) {
		for (int i = 1; i <= a1[0]; i ++ ) {
			s.clear();
			memset(d, -1, sizeof d);
			d[a1[i]] = 0;
			s.insert(mp(0, a1[i]));
			while (!s.empty()) {
				int v = s.begin() -> S;
				s.erase(s.begin());
				for (int j = 0;j < g[v].size(); ++ j) {
					int to = g[v][j].F;
					int len = g[v][j].S;
					if (d[to] > d[v] + len || d[to] == -1) {
						s.erase(mp(d[to], to));
						d[to] = d[v] + len;
						s.insert(mp(d[to], to));
					}
				}
			}
			for (int j = 1; j <= a2[0]; ++ j) {
				if (d[a2[j]] != -1 && ans > d[a2[j]]) {
					ans = d[a2[j]];
					x = a1[i], y = a2[j];
				}
			}
		}
	}
	else {
		for (int i = 1; i <= a2[0]; i ++ ) {
			s.clear();
			memset(d, -1, sizeof d);
			d[a2[i]] = 0;
			s.insert(mp(0, a2[i]));
			while (!s.empty()) {
				int v = s.begin() -> S;
				s.erase(s.begin());
				for (int j = 0;j < g[v].size(); ++ j) {
					int to = g[v][j].F;
					int len = g[v][j].S;
					if (d[to] > d[v] + len || d[to] == -1) {
						s.erase(mp(d[to], to));
						d[to] = d[v] + len;
						s.insert(mp(d[to], to));
					}
				}
			}
			for (int j = 1; j <= a1[0]; ++ j) {
				if (d[a1[j]] != -1 && ans > d[a1[j]]) {
					ans = d[a1[j]];
					x = a1[j], y = a2[i];
				}
			}
		}
	}
	if (ans == 1000000000) cout << -1;
	else
	cout << x << " " << y << " " << ans;

	return 0;
}
