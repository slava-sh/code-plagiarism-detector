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


const ll Q = 1e18;
ll dp[1000000][11];
vector<ll> g;

vector<pair<ll, int> > G[1000000];
int main(){
	srand(time(NULL));
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n, k, i, m, d, j;     

	cin >> n >> k;
	for (i = 1; i * i <= n; i++){
		if (n % i == 0){
			g.pb(i);
			if (i * i != n)
				g.pb(n / i);
		}
	}
	sort(g.begin(), g.end());
	m = (int)g.size();
	for (i = 0; i < m; i++)
		for (j = i; j < m; j++)
			if (g[j] % g[i] == 0)
				G[j].pb(mp(g[j] / g[i], i));

	for (i = 0; i < m; i++)
		dp[i][1] = (g[i] + 1) / 2;
	for (i = 1; i <= k; i++)
		dp[0][i] = 1;

	
/*	for (i = 0; i < m; i++){
		cerr << g[i];
		cerr <<endl;
		for (j= 0; j < (int)G[i].size(); j++)
			cerr << g[G[i][j]] << " ";
		cerr << endl;	
	}*/
	for (i = 1; i < m; i++){
		for (j = 2; j <= k; j++){
			dp[i][j] = Q;
			for (d = 0; d < (int)G[i].size(); d++){
				if (g[i] != G[i][d].first){
					dp[i][j] = min(dp[i][j], dp[G[i][d].second][j - 1] * ((G[i][d].first + 1) / 2));
				}
			}
		}
	}
	cout << dp[m - 1][k];
	return 0;
}