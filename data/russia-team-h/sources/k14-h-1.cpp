#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define fname "sequre."
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()

const int MAXN = 10500;
const int INF = 1 << 30;

vector < pair < int, int > > g[MAXN];
int a[MAXN], px, py, d[MAXN], min1 = INF;

int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int i=1;i<=m;i++){
			int x,y,w;	
			cin>>x>>y>>w;
			g[x].pb(mp(y,w));
			g[y].pb(mp(x,w));
		}
		for(int i=1;i<=n;i++){
			if (a[i] == 1) {
				for (int j = 1; j <= n; j++)
					d[j] = INF;
				set < pair < int, int > > q;
				d[i] = 0;
				q.insert(mp(d[i],i));
				while (!q.empty()) {
					int v = q.begin()->s;
					q.erase(q.begin());
					for (int j = 0; j < g[v].sz; j++) {
						int to = g[v][j].f;
						int w = g[v][j].s;
						if (d[to] > d[v] + w) {
							q.erase(mp(d[to], to));
							d[to] = d[v] + w;
							q.insert(mp(d[to], to));
						}
					}
				}
				for (int j = 1; j <= n; j++)
					if (a[j] == 2 && d[j] < min1) {
						min1 = d[j];
						px = i, py = j;
					}
			}
		}
		cout << px << " " << py << " " << min1 << endl;
	return 0;
}
