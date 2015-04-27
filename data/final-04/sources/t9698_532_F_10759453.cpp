#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <list>
#include <stack>
#include <bitset>
#include <algorithm>
#include <iomanip>

using namespace std;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

#define next ___next
#define last ___last

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

const int INF = int(1e9);
const li INF64 = li(1e18);
const ld EPS = 1e-9;
const ld PI = acosl(ld(-1));

const int N = 200 * 1000 + 13;
int n, m;
char s[N], t[N];

inline void gen ()
{
	n = 10, m = 3;
	forn (i, n)
		s[i] = rand() % 4 + 'a';
	forn (i, m)
		t[i] = rand() % 4 + 'a';

	cout << n << ' ' << m << endl;
	forn (i, n)
		cout << s[i];
	cout << endl;
	forn (i, m)
		cout << t[i];
	cout << endl;

	s[n] = t[m] = 0;
}

inline bool read()
{
//	gen();
//	return true;

	if (scanf ("%d%d", &n, &m) != 2)
		return false;

	assert(scanf ("%s", s) == 1);
	assert(scanf ("%s", t) == 1);

	return true;
}

const li P = 1009;
const li MOD = 1000000000000000031ll;

inline li myMul (li a, li b, li m)
{
	li q = li(ld(a) * b / m);
	li ans = (a * b - q * m) % m;

	if (ans < 0)
		ans += m;

	return ans;
}

inline li norm (li a)
{
	if (a >= MOD)
		a -= MOD;

	if (a < 0)
		a += MOD;

	return a;
}

const int A = 26;
int next[N], last[A];

li st[N];
int szans;
int ans[N];

vector<int> a1[A], a2[A];

inline bool check (int pos)
{
	forn (i, A)
	{
		a1[i].clear();
		a2[i].clear();
	}

	forn (i, A)
	{
		if (last[i] == -1)
			continue;

		if (last[i] < pos)
			continue;

		a1[ s[ last[i] ] - 'a' ].pb(t[last[i] - pos] - 'a');
		a2[ t[last[i] - pos] - 'a' ].pb(s[ last[i] ] - 'a');
	}

	forn (i, A)
		if (sz(a1[i]) > 1 || sz(a2[i]) > 1)
			return false;

	forn (i, A)
		if (sz(a1[i]) == 1)
		{
			int id = a1[i][0];

			if (sz(a1[id]) == 1 && a1[id][0] != i)
				return false;
		}

	forn (i, A)
		if (sz(a2[i]) == 1)
		{
			int id = a2[i][0];

			if (sz(a2[id]) == 1 && a2[id][0] != i)
				return false;
		}

	return true;
}

inline bool naive(int pos)
{
	forn (i, A)
	{
		a1[i].clear();
		a2[i].clear();
	}

	fore(i, pos, pos + m - 1)
	{
		a1[ s[i] - 'a' ].pb(t[i - pos] - 'a');
		a2[ t[i - pos] - 'a' ].pb(s[i] - 'a');
	}

	forn (i, A)
	{
		sort(all(a1[i]));
		a1[i].erase(unique(all(a1[i])), a1[i].end());
		sort(all(a2[i]));
		a2[i].erase(unique(all(a2[i])), a2[i].end());
	}

	forn (i, A)
		if (sz(a1[i]) > 1)
			return false;

	forn (i, A)
		if (sz(a1[i]) == 1)
		{
			int id = a1[i][0];

			if (sz(a1[id]) == 1 && a1[id][0] != i)
				return false;
		}

	forn (i, A)
		if (sz(a2[i]) > 1)
			return false;

	forn (i, A)
		if (sz(a2[i]) == 1)
		{
			int id = a2[i][0];

			if (sz(a2[id]) == 1 && a2[id][0] != i)
				return false;
		}

	return true;
}

inline void solve()
{
	st[0] = 1;
	fore(i, 1, N - 1)
		st[i] = myMul(st[i - 1], P, MOD);

	li bestHash = 0;

	memset(last, -1, sizeof last);
	memset(next, 0, sizeof next);

	forn (i, m)
	{
		if (last[ t[i] - 'a' ] != -1)
			next[ last[ t[i] - 'a' ] ] = i - last[ t[i] - 'a' ];

		last[ t[i] - 'a' ] = i;
	}

//	forn (i, m)
//		cerr << next[i] << ' ';
//	cerr << endl;

	forn (i, m)
	{
		bestHash = myMul(bestHash, P, MOD);
		bestHash = norm(bestHash + next[i]);
	}

	memset(last, -1, sizeof last);
	memset(next, 0, sizeof next);

	forn (i, m)
	{
		if (last[ s[i] - 'a' ] != -1)
			next[ last[ s[i] - 'a' ] ] = i - last[ s[i] - 'a' ];

		last[ s[i] - 'a' ] = i;
	}

	li curHash = 0;
	forn (i, m)
	{
		curHash = myMul(curHash, P, MOD);
		curHash = norm(curHash + next[i]);
	}

	szans = 0;

	fore (i, 0, n - m)
	{
		bool ok = (curHash == bestHash && check(i));
		if (ok)
			ans[szans++] = i;

		//assert(naive(i) == ok);

		curHash = norm(curHash - myMul(st[m - 1], next[i], MOD));
		curHash = myMul(curHash, P, MOD);

		if (i != n - m)
		{
			if (last[ s[i + m] - 'a' ] != -1)
			{
				int pos = last[ s[i + m] - 'a' ] - (i + 1);

				if (pos >= 0)
					curHash = norm(curHash - myMul(st[m - 1 - pos], next[ last[ s[i + m] - 'a' ] ], MOD));
				next[ last[ s[i + m] - 'a' ] ] = i + m - last[ s[i + m] - 'a' ];
				if (pos >= 0)
					curHash = norm(curHash + myMul(st[m - 1 - pos], next[ last[ s[i + m] - 'a' ] ], MOD));
			}

			last[ s[i + m] - 'a' ] = i + m;
		}

		curHash = norm(curHash + next[i + m]);
	}

	printf ("%d\n", szans);
	forn (i, szans)
		printf ("%d ", ans[i] + 1);
	puts("");
}

int main()
{
#ifdef SU2_PROJ
	assert(freopen("input.txt", "r", stdin));
	assert(freopen("output.txt", "w", stdout));
#endif

	cout << setprecision(25) << fixed;
	cerr << setprecision(10) << fixed;

	srand(int(time(NULL)));

	assert(read());
		solve();

#ifdef SU2_PROJ
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}
