#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <numeric>
#include <cctype>
#include <tuple>
#include <array>
#include <climits>
#include <bitset>
#include <cassert>

// BEGIN CUT HERE
#ifdef _MSC_VER
#include <agents.h>
#endif
// END CUT HERE 

#define FOR(i, a, b) for(ll i = (a); i < (int)(b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define REV(v) v.rbegin(), v.rend()
#define MEMSET(v, s) memset(v, s, sizeof(v))
#define UNIQUE(v) (v).erase(unique(ALL(v)), (v).end())
#define MP make_pair
#define MT make_tuple

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

const int N = 510;
ll dp[2][N][N];

int main(){
	cin.tie(0);
	ios::sync_with_stdio(false);

	ll n, m, mod;
	cin >> n >> m >> mod;
	vector<int> sum(n);
	rep(i, m){
		string s;
		cin >> s;
		rep(j, n) sum[j] += s[j] == '1';
	}

	int zero = count(ALL(sum), 0);
	int one = count(ALL(sum), 1);
	int cur = 0, nxt = 1;

	dp[cur][zero][one] = 1;
	for (int i = m; i < n; ++i){
		rep(j, n + 1) rep(k, n - j + 1){
			if (dp[cur][j][k]){
				if (j >= 2){
					dp[nxt][j - 2][k + 2] += j*(j - 1) / 2 % mod * dp[cur][j][k];
					dp[nxt][j - 2][k + 2] %= mod;
				}
				if (j && k){
					dp[nxt][j - 1][k + 0] += j * k % mod * dp[cur][j][k];
					dp[nxt][j - 1][k + 0] %= mod;
				}
				if (k >= 2){
					dp[nxt][j + 0][k - 2] += k*(k - 1) / 2 % mod * dp[cur][j][k];
					dp[nxt][j + 0][k - 2] %= mod;
				}
			}
		}
		rep(j, n + 1) rep(k, n - j + 1) dp[cur][j][k] = 0;
		swap(cur, nxt);
	}

	cout << dp[cur][0][0] << endl;

	return 0;
}