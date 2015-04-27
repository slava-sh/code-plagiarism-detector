#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;

#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define sz(x) (int((x).size()))
#define bit(x) (1 << (x))

template<class T>
inline void chkmax(T& x, T y) {
	if (x < y) x = y;
}

template<class T>
inline void chkmin(T& x, T y) {
	if (y < x) x = y;
}

typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
const int MX = 100005;
const int MOD = 1000000007;
LL inv[MX], f[MX], g[MX];
char s[MX];
int a[MX], sum[MX];

void init() {
	int i;
	
	inv[1] = 1;
	for (i = 2; i < MX; i++) inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
	
	f[0] = g[0] = 1;
	for (i = 1; i < MX; i++) {
		f[i] = f[i - 1] * i % MOD;
		g[i] = g[i - 1] * inv[i] % MOD;
	}
}

LL C(int n, int k) {
	if (k < 0 || k > n) return 0;
	return f[n] * g[n - k] % MOD * g[k] % MOD;
}

int main() {
	#ifndef ONLINE_JUDGE
		freopen("in.txt", "r", stdin);
		freopen("out.txt", "w", stdout);
	#endif
	
	int n, k, i, j;
	LL pw, com, rlt;
	
	init();
	scanf("%d%d%s", &n, &k, s + 1);
	for (i = 1; i <= n; i++) {
		a[i] = s[i] - '0';
		sum[i] = sum[i - 1] + a[i];
	}
	pw = 1;
	rlt = 0;
	for (j = 1; j < n; j++) {
		com = C(n - j - 1, k - 1);
		rlt += pw * com % MOD * sum[n - j] % MOD;
		pw = pw * 10 % MOD;
	}
	pw = 1;
	for (i = n; i >= 1; i--) {
		com = C(i - 1, k);
		rlt += pw * com % MOD * a[i] % MOD;
		pw = pw * 10 % MOD;
	}
	rlt %= MOD;
	printf("%d\n", (int)rlt);
	return 0;
}