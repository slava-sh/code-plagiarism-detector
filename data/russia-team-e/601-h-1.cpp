#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

#define TASK "secure"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;

const int maxn = 5010;
const ll INF = 2000000000;
ll G[maxn][maxn], W[maxn];
bool used[maxn];
int n, m, a[maxn], S, F, p[maxn];

void D() {
    for (int i = 0; i < n; ++i) {
	    W[i] = INF;
	}
	for (int g = 0; g <= n; ++g) {
	     int u = 0;
		 for (int i = 0; i <= n; ++i) {
		     if (used[i] == 0 && (used[u] == 1 || W[i] < W[u])) {
			     u = i;
			 }
		 }
		 used[u] = 1;
		 if (u < n && a[u] == 1) continue;
		 for (int i = 0; i < n; ++i) {
		     if (G[u][i] > 0 && W[i] > W[u] + G[u][i]) {
			     W[i] = W[u] + G[u][i];
				 p[i] = u;
			 }
		 }
	}	
}

int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
	    cin >> a[i];
	}
	for (int i = 0; i < m; ++i) {
	    ll v, u, c;
		cin >> v >> u >> c;
		--v;
		--u;
		if (G[v][u] == 0) G[v][u] = c;
		G[v][u] = min(G[v][u], c);
		if (a[v] == 1) {
		    if(G[n][u] == 0) G[n][u] = c;
			G[n][u] = min(G[n][u], c);
		}
		swap(v, u);
		if (G[v][u] == 0) G[v][u] = c;
		G[v][u] = min(G[v][u], c);
		if (a[v] == 1) {
		    if(G[n][u] == 0) G[n][u] = c;
			G[n][u] = min(G[n][u], c);
		}
	}
	D();
	F = 0;
	for (int i = 0; i < n; ++i) {
	    if (a[i] == 2 && (a[F] != 2 || W[F] > W[i])) {
		    F = i;
		}
	}
	if (2 * W[F] >= INF) {
	    cout << -1;
		return 0;
	}
	int S = F;
	ll C;
	while (1) {
	   if (p[S] != n) {
	       S = p[S];
	   }
	   else {
	       C = G[n][S];
		   break;
	   }
	}
	for (int i = 0; i < n; ++i) {
	    if (a[i] == 1 && G[i][S] == C) {
		    S = i;
			break;
		}
	}
	/*for (int i = 0; i  <= n; ++i) {
	    cout << W[i] << " ";
	}*/
	cout << S + 1 << " " << F + 1 << " " << W[F] << endl;
}