#define _CRT_SECURE_NO_DEPRECATE
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <ctime>
#include <cstring>

#include <bitset>

#pragma comment(linker, "/STACK:66777216")
using namespace std;
#define pb push_back
#define ppb pop_back
#define pi 3.1415926535897932384626433832795028841971
#define mp make_pair
#define x first
#define y second
#define pii pair<int,int>
#define pdd pair<double,double>
#define INF 1000000000
#define FOR(i,a,b) for (int _n(b), i(a); i <= _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;i--)
#define all(c) (c).begin(), (c).end()
#define SORT(c) sort(all(c))
#define rep(i,n) FOR(i,1,(n))
#define rept(i,n) FOR(i,0,(n)-1)
#define L(s) (int)((s).size())
#define C(a) memset((a),0,sizeof(a))
#define VI vector <int>
#define ll long long
#define MOD 1000000007
int a, b, c, d, n, m, k;
char str[100002];
int fac[100002], ifac[100002];
inline int fpow(int a, int st) {
	int ans = 1;
	while (st) {
		if (st % 2) ans = (ll)ans * a % MOD;
		a = (ll)a * a % MOD;
		st /= 2;
	}
	return ans;
}
inline int cnk(int n, int k) {
	if (k < 0 || k > n || n < 0) return 0;
	return (ll)fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
}
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	scanf("%d%d", &n, &k);
	fac[0] = ifac[0] = 1;
	rep(i, 100000) {
		fac[i] = (ll)fac[i - 1] * i % MOD;
		ifac[i] = fpow(fac[i], MOD - 2);
	}
	scanf("%s", str);
	int ans = 0, sum = 0;
	FORD(i, n - 2, 0) {
		int d = str[i] - '0';
		sum = (sum + (ll)fpow(10, n - 2 - i) * cnk(i, k - 1)) % MOD;
		ans = (ans + (ll)d * sum) % MOD;
	}

	rept(i, n) {
		int d = str[i] - '0';
		ans = (ans + (ll)d * fpow(10, n - i - 1) % MOD * cnk(i, k)) % MOD;
	}
	printf("%d\n", ans);
}
