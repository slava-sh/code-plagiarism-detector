#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <memory>
#include <set>
#include <map>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define sz(a) (int)a.size()

typedef long long ll;
typedef vector <int> vi;
typedef vector <vi> vvi;
typedef vector <vvi> vvvi;
typedef pair <int, int> ii;
typedef pair <ll, int> li;
typedef pair <int, ll> il;
typedef pair <ll, ll> lll;
typedef vector <ii> vii;
typedef vector <ll> vll;
typedef double db;
typedef long double ldb;
typedef vector <bool> vb;
typedef vector <vb> vvb;
typedef vector <vvb> vvvb;
typedef set <int> si;
typedef set <ii> sii;
typedef set <ll> sl;
typedef set <lll> sll;
typedef set <li> sli;
typedef set <il> sil;
typedef vector <db> vdb;
typedef vector <ldb> vldb;
typedef vector <si> vsi;

const int N = (int)2e5 + 4;
const int M = (int)2e6 + 100;
const ll inf = (ll)1e9 + 7;

struct pt
{
	ll a, b;
};

pt d[N];
ll p[N];
ll ps[N];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n, k, c, f;
	scanf("%lld %lld %lld %lld", &n, &k, &c, &f);
	ll s = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%lld %lld", &d[i].a, &d[i].b);
		s += (d[i].b - d[i].a);
	}
	for (int i = 1; i < n; ++i)
		p[i] = d[i].a - d[i - 1].b;
	sort(p, p + n);
	for (int i = 1; i < n; ++i)
		ps[i] = ps[i - 1] + p[i];
	ll l = 0, r = (ll)1e18;
	for (; r > l;)
	{
		ll x = (l + r) / 2;
		bool h = 0;
		for (ll i = 0; i < n; ++i)
			if (x >= i * c && (x - i * c) / f >= s && ((i + 1) * k >= n || ((i + 1) * k < n && (x - i * c) / f - s >= ps[n - (i + 1) * k])))
				h = 1;
		if (h)
			r = x;
		else
			l = x + 1;
	}
	printf("%lld", l);
	return 0;
}