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
#define pb push_back
#define pii pair <int, int>
#define S second
#define F first


const int INF = int(1e9) + 7;

using namespace std;

ll n, kk, m;
vector <ll> dv;
vector <vector <ll> > dp;
map <ll, ll> mp;

int main(){
//	ifstream cin ("test.in");
	cin >> n >> kk;
	while (n % 2 == 0 && kk > 1){
		n /= 2;
		kk--;
	}
	for (ll i = 1; i * i <= n; i++){
		if (n % i == 0){
			dv.pb(i);
			dv.pb(n / i);
		}
	}
	sort(dv.begin(), dv.end());
	m = dv.size();
	dp.assign(m + 1, vector <ll> (kk + 1));
	for (int i = 0; i < m; i++){
		mp[dv[i]] = i;
		dp[i][1] = (dv[i] + 1) / 2;
	}
	vector < vector<int> > e;
	e.resize(m);
	for (int i = 1; i < m; i++){
		for (int j = 0; j < i; j++){
			if (dv[i] % dv[j] == 0) e[i].pb(mp[dv[i] / dv[j]]);
		}
	}
	for (int k = 2; k <= kk; k++){
		for (int j = 0; j < m; j++){
			dp[j][k] = (dv[j] + 1) / 2;
			for (int i = 0; i < e[j].size(); i++){
				dp[j][k] = min(dp[j][k], dp[e[j][i]][k - 1] * ((dv[i] + 1) / 2));
			}
		}
	}
	cout << dp[m - 1][kk];
	return 0;
}