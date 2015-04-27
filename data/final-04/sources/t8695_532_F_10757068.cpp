#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <cstdio>
#include <queue>
#include <ctime>
#include <cmath>
#include <set>
#include <map>

#define mp make_pair
#define pb push_back
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

#define sz(c) (int)(c).size()

using namespace std;

typedef long long ll;

const int maxn = (int)2e5 + 123;

const ll Q = (ll)1e18 + 3;
ll P;

ll add(ll a, ll b) {
	if ((a += b) >= Q) a -= Q;
	return a;
}

ll mult(ll a, ll b) {
	ll k = ll((long double)a * b / Q);
	a = a * b - k * Q;
	while (a < 0) a += Q;
	while (a >= Q) a -= Q;
	return a;
}

ll st[maxn];
ll h[maxn];
char S[maxn];
char T[maxn];
ll hS[26][maxn];
ll hT[26][maxn];
int cT[26];

int solve() {
	int n, m;
	if (scanf("%d%d", &n, &m) != 2) return 0;
	scanf("%s", S);
	scanf("%s", T);
	memset(cT, -1, sizeof cT);
	for (int i = 0; i < m; i++) {
		if (cT[T[i] - 'a'] == -1) cT[T[i] - 'a'] = i;
	}
	for (int k = 0; k < 26; k++) {
		hS[k][0] = 0;
   	for (int i = 0; i < n; i++) {
			hS[k][i + 1] = add(mult(hS[k][i], st[1]), (S[i] == k + 'a'));
		}
		hT[k][0] = 0;
		for (int i = 0; i < m; i++) {
			hT[k][i + 1] = add(mult(hT[k][i], st[1]), (T[i] == k + 'a'));
		}
	}
	vector<int> res;
	for (int i = 0; i + m <= n; i++) {
		int ok = 1;
		for (int k = 0; k < 26 && ok; k++) {
			if (cT[k] == -1) continue;
			int l = S[i + cT[k]] - 'a';
			ll h1 = hT[k][m];
			ll h2 = add(hS[l][m + i], Q - mult(hS[l][i], st[m]));
			ok &= h1 == h2;
			h1 = hT[l][m];
			h2 = add(hS[k][m + i], Q - mult(hS[k][i], st[m]));
			ok &= h1 == h2;
		}
		if (ok) res.push_back(i + 1);
	}
	printf("%d\n", (int)res.size());
	for (int i = 0; i < (int)res.size(); i++) {
		printf("%d%c", res[i], " \n"[i + 1 == (int)res.size()]);
	}
	return 1;
}

int main(){
	srand(time(NULL));
	P = 0;
	while (P < 256) {
		P = (((rand() << 16) + rand())%Q + Q) % Q;
	}
	st[0] = 1;
	for (int i = 0; i + 1 < maxn; i++) st[i + 1] = mult(st[i], P);
	while (solve());
}
