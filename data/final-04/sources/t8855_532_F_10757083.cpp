#pragma comment(linker,"/STACK:64000000")
#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <sstream>
#include <stdio.h>
#include <memory.h>
#include <algorithm>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <cassert>
#include <time.h>
#include <bitset>

using namespace std;

#define mp make_pair
#define pb push_back
#define _(a,b) memset( (a), b, sizeof( a ) )
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#ifdef _DEBUG
#define dbg(...) {fprintf(stderr, __VA_ARGS__); fflush(stderr);}
#define dbgx(x) {cerr << #x << " = " << x << endl;}
#define dbgv(v) {cerr << #v << " = {"; for (typeof(v.begin()) it = v.begin(); it != v.end(); it ++) cerr << *it << ", "; cerr << "}"; cerr << endl;}
#else
#define dbg(...) { }
#define dbgx(x) { }
#define dbgv(v) { }
#endif

typedef unsigned long long ull;
typedef long long lint;
typedef pair < int , int > pii;
typedef long double ld;

const int INF = 1000 * 1000 * 1000;
const lint LINF = 1000000000000000000LL;
const double eps = 1e-9;

void prepare()
{
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#endif
}

const int nmax = 2 * 100005;
const lint g = 3137, mod1 = 1000 * 1000 * 1000 + 7, mod2 = 1000 * 1000 * 1000 + 9;

lint p1[nmax], p2[nmax];
char tmp[nmax];
string S, T, BUF;

string getString()
{
	scanf("%s",tmp);
	return tmp;
}

void init()
{
	p1[0] = 1;
	p2[0] = 1;
	for (int i = 1; i < nmax; i ++)
	{
		p1[i] = p1[i - 1] * g % mod1;
		p2[i] = p2[i - 1] * g % mod2;
	}
}

struct MyString
{
	string str;
	int n;
	lint h1[nmax], h2[nmax];

	void init(string inputString)
	{
		str = inputString;
		n = sz(str);
		calc();
	}

	void calc()
	{
		h1[0] = h2[0] = str[0];
		for (int i = 1; i < n; i ++)
		{
			h1[i] = (h1[i - 1] + p1[i] * str[i]) % mod1;
			h2[i] = (h2[i - 1] + p2[i] * str[i]) % mod2;
		}
	}

	lint get_hash_1(int l,int r)
	{
		lint ret = (h1[r] - (l > 0 ? h1[l - 1] : 0) + mod1) % mod1;
		return (ret * p1[nmax - 1 - l]) % mod1;
	}

	lint get_hash_2(int l,int r)
	{
		lint ret = (h2[r] - (l > 0 ? h2[l - 1] : 0) + mod2) % mod2;
		return (ret * p2[nmax - 1 - l]) % mod2;
	}

	lint get_hash(int l,int r)
	{
		if (l > r) return 0;
		lint ret = (get_hash_1(l,r) << 32) + get_hash_2(l,r);
		return ret ;
	}
}s[30], t[30];

int n, m;
vector < int > ans;
vector < int > positions[30];
int l[30], r[30];

bool read()
{
	scanf("%d%d",&n,&m);
	S = getString();
	T = getString();
	return false;
}

void initHash(MyString &s, string &inputString, char c)
{
	BUF = inputString;
	for (int i = 0; i < sz(inputString); i ++)
	{
		if (inputString[i] == c)
		{
			BUF[i] = '1';
		}
		else
		{
			BUF[i] = '0';
		}
	}

	s.init(BUF);
}

void precalc()
{
	for (int i = 0; i < n; i ++)
	{
		positions[S[i] - 'a'].pb(i);
	}

	for (char c = 'a'; c <= 'z'; c ++)
	{
		initHash(s[c - 'a'], S, c);
		initHash(t[c - 'a'], T, c);
	}
}

void updatePointers(int L, int R)
{
	for (int i = 0; i < 26; i ++)
	{
		while (l[i] < sz(positions[i]) && positions[i][l[i]] < L)
			l[i]++;
		while (r[i] < sz(positions[i]) && positions[i][r[i]] <= R)
			r[i]++;
	}
}

int mapping[26];

void getMapping(int shift)
{
	_(mapping, -1);
	for (int i = 0; i < 26; i ++)
	{
		if (l[i] < sz(positions[i]) && l[i] < r[i])
		{
			int pos = positions[i][l[i]];
			int from = S[pos] - 'a';
			int to = T[pos - shift] - 'a';

			mapping[from] = to;
			mapping[to] = from;
		}
	}
}

bool checkMapping()
{
	for (int i = 0; i < 26; i ++)
	{
		int from = i, to = mapping[i];
		if (to == -1) 
		{	
			continue;
		}
		if (mapping[to] != from)
		{
			return false;
		}
	}
	return true;
}

bool checkHard(int L, int R)
{
	for (int from = 0; from < 26; from ++)
	{
		int to = mapping[from];
		if (to == -1)
		{
			continue;
		}

		lint h1 = s[from].get_hash(L, R);
		lint h2 = t[to].get_hash(0, m - 1);
		if (h1 != h2)
		{
			return false;
		}
	}
	return true;
}

void doit()
{
	for (int shift = 0; shift < n - m + 1; shift ++)
	{
		int L = shift;
		int R = shift + m - 1;

		updatePointers(L, R);
		getMapping(shift);
		if (!checkMapping())
		{
			continue;
		}

		if (checkHard(L, R))
		{
			ans.pb(shift);
		}
	}
}

void outResult()
{
	printf("%d\n", sz(ans));
	for (int i = 0; i < sz(ans); i ++)
	{
		if (i) printf(" ");
		printf("%d", ans[i] + 1);
	}
	printf("\n");
}

void solve()
{
	precalc();
	doit();
	outResult();
}

int main()
{
	prepare();
	init();
	read();
	solve();
	return 0;
}