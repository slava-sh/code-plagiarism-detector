#pragma comment(linker, "/stack:64000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <cstring>
#include <ctime>
#include <cmath>
#include <cassert>
#include <vector>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <utility>

#define forn(i, n) for (int i = 0; i < int(n); i++)
#define forl(i, n) for (int i = 1; i <= int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i, l, r) for (int i = int(l); i <= int(r); i++)
#define correct(x, y, n, m) (0 <= (x) && (x) < (n) && 0 <= (y) && (y) < (m))
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb(a) push_back(a)
#define mp(x, y) make_pair((x), (y))
#define ft first
#define sc second
#define X first
#define Y second

using namespace std;

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

template<typename X> inline X abs(const X& a) { return a < 0? -a: a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9, PI = 3.1415926535897932384626433832795;

set<pt> z;

inline bool read()
{
	int n;
	
	if (scanf("%d", &n) != 1)
		return false;
		
	map<int, int> cnt;
		
	forn(i, n)
	{
		int x;
		assert(scanf("%d", &x) == 1);
		
		cnt[x]++;
	}
	
	vector<pt> cur(all(cnt));
	
	forn(i, sz(cur))
		z.insert(mp(-cur[i].sc, cur[i].ft));
	
	return true;
}

inline void solve()
{
	vector< pair<pt, int> > ans;
	
	while (sz(z) >= 3)
	{
		pt v1 = *z.begin(); z.erase(z.begin());
		pt v2 = *z.begin(); z.erase(z.begin());
		pt v3 = *z.begin(); z.erase(z.begin());
		
		ans.pb(mp(mp(v1.sc, v2.sc), v3.sc));
		
		if (++v1.ft < 0) z.insert(v1);
		if (++v2.ft < 0) z.insert(v2);
		if (++v3.ft < 0) z.insert(v3);
	}
	
	printf("%d\n", sz(ans));
	
	forn(i, sz(ans))
	{
		int cur[] = { ans[i].ft.ft, ans[i].ft.sc, ans[i].sc };
		sort(cur, cur + 3);
		reverse(cur, cur + 3);
		
		printf("%d %d %d\n", cur[0], cur[1], cur[2]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    assert(read());
    solve();
    
    return 0;
}
