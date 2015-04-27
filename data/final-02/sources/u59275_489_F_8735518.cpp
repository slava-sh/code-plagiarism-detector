#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <complex>
#include <string>
#include <bitset>
#include <vector>
#include <cstdio>
#include <ctime>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef complex < double > cd;

const bool db = false;

#define mp make_pair
#define pb push_back
#define ppb pop_back
#define sd second
#define fs first

#define inf 1000000007
#define nmax 100010
#define mmax 100010
#define eps 1e-9

int n, m, mod;
int g[1555], ones, twos;
int dp[1555][1555];

int calc(int o, int t) {
	if(o == 0 && t == 1)
		return 0;
	if(o == 0 && t == 0)
		return 1;
	if(dp[o][t] != -1)
		return dp[o][t];
	ll res = 0;
	res = 0;
	if(o >= 2) {
		res += o * 1LL * (o - 1) / 2 % mod * 1LL * calc(o - 2, t) % mod;
		res %= mod;
	}
	if(o >= 1 && t >= 1) {
		res += o * 1LL * t % mod * 1LL * calc(o, t - 1) % mod;
		res %= mod;
	}
	if(t >= 2) {
		res += t * 1LL * (t - 1) / 2 % mod * 1LL * calc(o + 2, t - 2) % mod;
		res %= mod;
	}
	dp[o][t] = res % mod;
	return res;
}

int main() {
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    //freopen("mountaineering.in", "r", stdin); freopen("mountaineering.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &mod);
	for(int i = 1; i <= n; ++i)
		g[i] = 2;
	for(int i = 1; i <= m; ++i) 
		for(int j = 1; j <= n; ++j) {
			char c; cin >> c;
			if(c == '1')
				--g[j];
		}
	memset(dp, -1, sizeof(dp));
	dp[0][0] = 1;
	for(int sum = 1; sum <= 1000; ++sum)
		for(int ones = sum - 2; ones >= 0; --ones)
			calc(ones, sum - ones);
	for(int i = 1; i <= n; ++i)
		if(g[i] == 1)
			++ones;
		else if(g[i] == 2)
			++twos;
	cout << calc(ones, twos) << endl;
	getchar(); getchar();
    return 0;
}