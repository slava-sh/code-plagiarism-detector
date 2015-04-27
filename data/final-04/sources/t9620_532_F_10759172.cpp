#pragma comment(linker, "/stack:32000000")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <cassert>
#include <string.h>
#include <ctime>

#define pb push_back
#define mp make_pair
#define PI 3.1415926535897932384626433832795
#define sqr(x) (x)*(x)
#define forn(i, n) for(int i = 0; i < n; ++i)
#define ALL(x) x.begin(), x.end()
#define sz(x) int((x).size())
#define X first
#define Y second
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
using namespace std;
typedef pair<int,int> pii;
const int INF = 2147483647;
const ll LLINF = 9223372036854775807LL;

const int mod1 = 1000000007;
const int mod2 = 1000000009;
const int P = 1232133;

const int maxn = 200010;

struct num {
	int x, y;
	num():x(0),y(y) {}
	//num(int x):x(x), y(x) {}
	num(int x, int y):x(x),y(y) {}
	num operator+(const num& o) const {
		num res(x + o.x, y + o.y);
		if (res.x >= mod1) res.x -= mod1;
		if (res.y >= mod2) res.y -= mod2;
		return res;
	}

	num operator-(const num& o) const {
		num res(x - o.x, y - o.y);
		if (res.x < 0) res.x += mod1;
		if (res.y < 0) res.y += mod2;
		return res;
	}

	num operator*(const num& o) const {
		return num(x * (ll)o.x % mod1, y * (ll)o.y % mod2);
	}

	bool operator<(const num& o) const {
		if (x == o.x) return y < o.y;
		return x < o.x;
	}

	bool operator==(const num& o) const {
		return x == o.x && y == o.y;
	}
};

num p[maxn];

num th[30];
int tpos[30];

num sh[30];
int spos[30];

int tmp[30];
int nxt[maxn];

int main()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	p[0] = num(1,1);
	for (int i = 1; i < maxn; ++i) p[i] = p[i-1] * num(P, P);



	int Slen, Tlen; scanf("%d%d", &Slen, &Tlen);
	string s, t; cin >> s >> t;
	memset(tpos, -1, sizeof(tpos));
	for(int i = sz(t)-1; i >= 0; --i) tpos[t[i]-'a'] = i;
	forn(i, sz(t)) th[t[i]-'a'] = th[t[i]-'a'] + p[sz(t)-1-i];
	vector<pair<int, num> > tv;
	forn(i, 26) if (tpos[i] != -1) tv.pb(mp(tpos[i], th[i]));
	sort(ALL(tv));

	int n = sz(s);
	forn(i, 26) tmp[i] = n;
	for (int i = n-1; i >= 0; --i) {
		nxt[i] = tmp[s[i]-'a'];
		tmp[s[i]-'a'] = i;
	}

	vector<int> ans;
	memset(spos, -1, sizeof(spos));
	for (int i = sz(t)-1; i >= 0; --i) spos[s[i]-'a'] = i;
	forn(i, sz(t)) sh[s[i]-'a'] = sh[s[i]-'a'] + p[sz(t)-1-i];
	for(int l = 0; l + sz(t) <= n; ++l) {
		vector<pair<int, num> > vs;
		bool ok = true;
		forn(i, 26) if (spos[i] != -1 && tpos[i] != -1 && spos[i] - l != tpos[i]) {
			if (!(t[spos[i]-l] == s[l+tpos[i]])) {
				ok = false;
				break;
			}
		}
		if (ok) {
			forn(i, 26) if (spos[i] != -1) vs.pb(mp(spos[i]-l, sh[i]));
			sort(ALL(vs));
			if (vs == tv) ans.pb(l);
		}
		forn(i, 26) sh[i] = sh[i] * p[1];
		int j = l + sz(t);
		if (j >= n) break;
		sh[s[j]-'a'] = sh[s[j]-'a'] + p[0];
		sh[s[l]-'a'] = sh[s[l]-'a'] - p[sz(t)];
		spos[s[l]-'a'] = -1;
		if (nxt[l] <= j) spos[s[l]-'a'] = nxt[l];
		if (spos[s[j]-'a'] == -1) spos[s[j]-'a'] = j;
	}
	printf("%d\n", sz(ans));
	forn(i, sz(ans)) printf("%d ", ans[i]+1);
	return 0;
}