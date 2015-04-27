#pragma comment(linker, "/STACK:100000000")
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <cstdlib>
#include <complex>
#include <sstream>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <map>
#include <set>
 
using namespace std;
 
typedef unsigned long long ull;
typedef complex < double > cd;
typedef long double ld;
typedef long long ll;
 
#define ppb pop_back
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
 
#define inf 1000000007
#define nmax 200010
#define mmax 100010
#define eps 1e-9

int n, m;
int Pow[] = {239017, 301703};
int mod[] = {inf, inf + 2};
int hp[2][nmax];
char s[nmax], t[nmax];
int h[2][26], f[2][26], g[2][26];
int ch[26], cg[26];

int main() {
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//freopen("distance.in", "r", stdin); freopen("distance.out", "w", stdout);
	//ios :: sync_with_stdio(false);
	scanf("%d%d\n", &n, &m);
	gets(s + 1);
	gets(t + 1);
	for(int k = 0; k < 2; ++k) {
        hp[k][0] = 1;
        for(int i = 1; i < nmax; ++i) {
            hp[k][i] = 1LL * hp[k][i - 1] * Pow[k] % mod[k];
        }
    }
	for(int i = 1; i <= m; ++i) {
		for(int k = 0; k < 2; ++k) {
			h[k][t[i] - 'a'] = (h[k][t[i] - 'a'] + hp[k][i]) % mod[k];
			g[k][s[i] - 'a'] = (g[k][s[i] - 'a'] + hp[k][i]) % mod[k];
			cg[s[i] - 'a']++;
			ch[t[i] - 'a']++;
		}
	}
	vector < int > ans;
	int nxt[26] = {};
	for(int i = 1; i + m - 1 <= n; ++i) {
		vector < pair < pair < int, int >, int > > le, ri;
		for(int j = 0; j < 26; ++j) {
			le.pb(mp(mp(g[0][j], g[1][j]), j));
			ri.pb(mp(mp(h[0][j], h[1][j]), j));
		}
		sort(le.begin(), le.end());
		sort(ri.begin(), ri.end());
		memset(nxt, -1, sizeof(nxt));
		bool ok = true;
		for(int i = 0; i < 26; ++i) {
			ok &= le[i].fs == ri[i].fs;
		}
		if(ok == true) {
			for(int j = 0; j < 26; ++j) {
				if(cg[le[j].sd] == 0) continue;
				if(nxt[le[j].sd] != -1 && nxt[le[j].sd] != ri[j].sd)
					ok = false;
				nxt[le[j].sd] = ri[j].sd;
				if(nxt[ri[j].sd] != -1 && nxt[ri[j].sd] != le[j].sd)
					ok = false;
				nxt[ri[j].sd] = le[j].sd;
			}
			if(ok == true)
				ans.push_back(i);
		}
		for(int k = 0; k < 2; ++k) {
			g[k][s[i] - 'a'] = (g[k][s[i] - 'a'] + mod[k] - hp[k][i]) % mod[k];
			--cg[s[i] - 'a'];
			if(i + m <= n) {
				g[k][s[i + m] - 'a'] = (g[k][s[i + m] - 'a'] + hp[k][i + m]) % mod[k];
				++cg[s[i + m] - 'a'];
			}
			for(int j = 0; j < 26; ++j) {
				h[k][j] = (h[k][j] * 1LL * Pow[k]) % mod[k];
			}
		}
	}
	cout << ans.size() << "\n";
	for(int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << (i == ans.size() - 1 ? '\n' : ' ');
	}
	getchar(); getchar();
	return 0;
}