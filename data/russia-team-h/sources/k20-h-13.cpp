#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;

#define fname "secure"
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define forp(i, a, b) for(int i = a; i <= b; ++i)
#define form(i, a, b) for(int i = a; i >= b; --i)

const int MAXN = 5000 + 100;
const ll INF = (ll) (1e14);

int n, m, cnt;
int a[MAXN];
vector < pair < int ,int > > g[MAXN];
ll d[MAXN], p[MAXN];
vector <int> ed, de;
set < pair <ll , pair <ll, ll> > > ans;
pair < ll, pair <ll, ll > > ans1;
int main() {
	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin>>n>>m;
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (a[i] == 1)
			ed.pb(i);
		else if (a[i] == 2) 
			de.pb(i);
	}
	for(int i = 0; i < m; i++) {
		int a, b, cost;
		scanf("%d%d%d", &a, &b, &cost);
		g[a].pb(mp(b, cost));
		g[b].pb(mp(a, cost));

	}
	ans1.F = INF;
	for(int i = 0 ; i < ed.size(); i++) {
		int s = ed[i];
		for(int i = 0; i <= n;++i) {
			p[i]= 0; 
			d[i] = INF;    
		}
		set < pair <ll, ll> > q;
		d[s] = 0;
		p[s] = s;
		q.insert(mp(d[s], s));
		while(!q.empty()) {
			int v = q.begin()->second;
			q.erase(q.begin());
			for(int j = 0; j < g[v].size(); j++) {
				int to = g[v][j].F, len = g[v][j].S;
				if ( d[v] + len < d[to]) {
					q.erase(mp(d[to], to));
					++cnt;
					d[to] = d[v] + len;
					p[to] = p[v];
					if (a[to] == 2) {
						//ans.insert(mp(d[to], mp(v, to)));
						if (d[to] < ans1.F) {
							ans1 = mp(d[to], mp(p[v], to));
							if(cnt == 103) {cout<<ans1.S.F<<" "<<ans1.S.S<<" "<<ans1.F<<endl;
	                        return 0;       }
						}
					}
					
					q.insert(mp(d[to], to));
			   	}
			   	
			}

		}
		/*
		for(int j = 0; j < de.size(); j++) {
			ans.insert(mp(d[de[j]], mp(s, de[j])));
		}
		*/

	}
	               /*
	if((*ans.begin()).F == INF) {
		cout << - 1;
		return 0;
	}
	cout<<(*ans.begin()).S.F<<" "<<(*ans.begin()).S.S<<" "<<(*ans.begin()).F<<endl;
	*/
	if (ans1.F == INF) 
		cout<< -1;
	else 
		cout<<ans1.S.F<<" "<<ans1.S.S<<" "<<ans1.F<<endl;
	return 0;
}