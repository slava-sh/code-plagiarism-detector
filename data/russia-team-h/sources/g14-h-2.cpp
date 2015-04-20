#include <iostream>
#include <cstdio>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <stdlib.h>

#define ll long long
#define pb push_back
#define mp make_pair
#define m9 1000000009
#define m7 1000000007
#define INF 1000000001
#define fi first
#define se second
#define EPS 0.000000001
#define Pi 3.1415926535897932384626433832795028841971
using namespace std;

ll d1[10000], d2[10000], x, y, res, p1[10000], p2[10000], n, m, a[10000], l;
vector <vector<pair<ll, ll > > > g;

void dijkstra1 (int n) {
 
     d1[n] = 0;
	 set < pair<int,int> > q;
	 
	 q.insert (make_pair (d1[n], n));
	 
     while (!q.empty()) {
           
		   int v = q.begin()->se;
		   q.erase (q.begin());
 
		   for (size_t j = 0; j < g[v].size(); ++j) {
			   
               int to = g[v][j].fi, len = g[v][j].se;
               
               if (d1[v] + len < d1[to]) {
                        
				  q.erase (make_pair (d1[to], to));
				  d1[to] = d1[v] + len;
				  p1[to] = n;
				  q.insert (make_pair (d1[to], to));
		       
               }
         }
     
     }

}

void dijkstra2 (int n) {
     
     d2[n] = 0;
	 set < pair<int,int> > q;
	 
	 q.insert (make_pair (d1[n], n));
	 
     while (!q.empty()) {
           
		   int v = q.begin()->se;
		   q.erase (q.begin());
 
		   for (size_t j = 0; j < g[v].size(); ++j) {
			   
               int to = g[v][j].fi, len = g[v][j].se;
               
               if (d2[v] + len < d2[to]) {
                        
				  q.erase (make_pair (d2[to], to));
				  d2[to] = d2[v] + len;
				  p2[to] = n;
				  q.insert (make_pair (d2[to], to));
		       
               }
         }
     
     }

}
     
int main() {
    
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    freopen("secure.in", "r", stdin); freopen("secure.out", "w", stdout);
    
    cin >> n >> m;
    
    g.resize(n + 1);
    
    for (int i = 1; i <= n; i++) d1[i] = INF, d2[i] = INF;
    
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= m; i++) {
        
        cin >> x >> y >> l;
        
        g[x].pb(mp(y, l));
        g[y].pb(mp(x, l));
        
    }
    
    for (int i = 1; i <= n; i++) {
    
        if (a[i] == 1) dijkstra1(i);
        
    }
    
    int res = INF;
    
    for (int i = 1; i <= n; i++) {
        
        if (a[i] != 2) continue;
        
        if (res > d1[i]) { res = d1[i]; x = p1[i]; y = i; }
        
    }
    
    if (res == INF) { cout << -1; return 0; }
    
    cout << x << " " << y << " " << res;
    
    return 0;
    
}
