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
#include <ctime>
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
int d[5555], p[5555];

int a1[N], a2[N], ans = 1000000000;

set <pair<int, int> > s;

double Time () {
	return double(clock() / double(CLOCKS_PER_SEC));
}

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

	for (int i = 1; i <= n; i ++ ) d[i] = 1000000000;

	for (int i = 1; i <= a1[0]; i ++ ) {
		d[a1[i]] = 0;
		p[a1[i]] = a1[i];
		s.insert(mp(0, a1[i]));
	}

	while (!s.empty()) {
		int v = s.begin() -> S;
		s.erase(s.begin());
		for (int i = 0; i < g[v].size(); i ++ ) {
			int to = g[v][i].F;
			int len = g[v][i].S;
			if (d[to] > d[v] + len) {
				s.erase(mp(d[to], to));
				d[to] = d[v] + len;
				p[to] = p[v];
				s.insert(mp(d[to], to));
			}	
		}
	}

	for (int i = 1; i <= a2[0]; i ++ ) {
		if (ans > d[a2[i]]) {
			ans = d[a2[i]];
			x = p[a2[i]], y = a2[i];
		}
	}

	if (ans == 1000000000) cout << -1;
	else
	cout << x << " " << y << " " << ans;

	return 0;
}
