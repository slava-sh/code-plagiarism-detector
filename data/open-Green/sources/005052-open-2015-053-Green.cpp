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

const int N = (int)1e9 + 4;
const int M = (int)2e6 + 100;
const ll inf = (ll)1e12 + 7;

vector <li> p;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ll n;
	int k;
	cin >> n >> k;
	ll nn = n;
	for (ll i = 2; i * i <= nn; ++i)
		if (nn % i == 0)
		{
			li t = mp(i, 0);
			for (; nn % i == 0; nn /= i)
				++t.second;
			p.pb(t);
		}
	if (nn > 1)
		p.pb(mp(nn, 1));
	nn = n;
	int kk = k;
	vi ap;
	for (int i = 0; i < sz(p); ++i)
	{
		int j;
		for (j = 0; j < min(kk, p[i].second); ++j)
		{
			nn /= p[i].first;
			ap.pb(p[i].first);
		}
		kk -= j;
	}
	ll ans = (nn + 1) / 2;
	for (int i = sz(ap) - 1; i >= 0; --i)
		ans *= (ap[i] + 1) / 2;
	cout << ans;
	return 0;
}