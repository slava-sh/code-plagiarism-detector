#pragma comment(linker, "/STACK:1000000000")

#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cassert>
#include <iomanip>
#include <memory>
#include <string>
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

const int inf = (int)1e9 + 7;
const int N = (int)1e5 + 4;
const int M = 1000;
const ldb eps = 1e-12;

struct ot
{
	int l, r, c;
	ot() { }
	ot(int l, int r, int c) : l(l), r(r), c(c) { }
};

bool operator<(ot a, ot b)
{
	if (a.l == b.l)
		return a.r < b.r;
	return a.l < b.l;
};

int t[N];

int main()
{
//	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &t[i]);
	int l = 0;
	set <ot> q;
	for (int i = 1; i < n; ++i)
		if (t[i] != t[i - 1])
		{
			q.insert(ot(l, i - 1, t[i - 1]));
			l = i;
		}
	q.insert(ot(l, n - 1, t[n - 1]));
	int p;
	scanf("%d", &p);
	for (int i = 0; i < p; ++i)
	{
		int x, c;
		scanf("%d %d", &x, &c);
		--x;
		set <ot> :: iterator it = q.lwb(ot(x, inf, c));
		--it;
		int l = it->l;
		int r = it->r;
		int col = it->c;
		ot h = *it;
		if (col == c)
		{
			printf("%d\n", sz(q));
			continue;
		}
		if (l < x && x < r)
		{
			ot a = ot(l, x - 1, col);
			ot b = ot(x + 1, r, col);
			q.erase(h);
			q.insert(ot(x, x, c));
			q.insert(a);
			q.insert(b);
			printf("%d\n", sz(q));
			continue;
		}
		if (l == x && r > x)
		{
			set <ot> :: iterator itt = q.lwb(ot(x, inf, c));
			--itt;
			if (itt == q.begin())
			{
				q.erase(h);
				q.insert(ot(x, x, c));
				q.insert(ot(l + 1, r, col));
			}
			else
			{
				--itt;
				if (itt->c == c)
				{
					ot d = *itt;
					q.erase(itt);
					q.erase(h);
					q.insert(ot(d.l, d.r + 1, c));
					q.insert(ot(l + 1, r, col));
				}
				else
				{
					q.erase(h);
					q.insert(ot(x, x, c));
					q.insert(ot(l + 1, r, col));
				}
			}
			printf("%d\n", sz(q));
			continue;
		}
		if (l < x && r == x)
		{
			set <ot> :: iterator itt = q.lwb(ot(x, inf, c));
			if (itt == q.end())
			{
				q.erase(h);
				q.insert(ot(x, x, c));
				q.insert(ot(l, r - 1, col));
			}
			else
			{
				if (itt->c == c)
				{
					ot d = *itt;
					q.erase(itt);
					q.erase(h);
					q.insert(ot(l, r - 1, col));
					q.insert(ot(d.l - 1, d.r, c));
				}
				else
				{
					q.erase(h);
					q.insert(ot(x, x, c));
					q.insert(ot(l, r - 1, col));
				}
			}
			printf("%d\n", sz(q));
			continue;
		}
		if (l == x && r == x)
		{
			set <ot> :: iterator itt = q.lwb(ot(x, inf, c));
			set <ot> :: iterator itp = q.lwb(ot(x, inf, c));
			itp--;
			if (itt == q.end() && itp == q.begin())
			{
				q.erase(h);
				q.insert(ot(x, x, c));
				printf("%d\n", sz(q));
				continue;
			}
			if (itt == q.end())
			{
				itp--;
				if (itp->c == c)
				{
					ot d = *itp;
					q.erase(itp);
					q.erase(h);
					q.insert(ot(d.l, d.r + 1, c));
					printf("%d\n", sz(q));
				}
				else
				{
					q.erase(h);
					q.insert(ot(x, x, c));
					printf("%d\n", sz(q));
				}
				continue;
			}
			if (itp == q.begin())
			{
				if (itt->c == c)
				{
					ot d = *itt;
					q.erase(itt);
					q.erase(h);
					q.insert(ot(d.l - 1, d.r, c));
					printf("%d\n", sz(q));
				}
				else
				{
					q.erase(h);
					q.insert(ot(x, x, c));
					printf("%d\n", sz(q));
				}
				continue;
			}
			itp--;
			if (itp->c == c && itt->c == c)
			{
				ot d = ot(itp->l, itt->r, c);
				q.erase(itp);
				q.erase(itt);
				q.erase(h);
				q.insert(d);
				printf("%d\n", sz(q));
				continue;
			}
			if (itp->c == c)
			{
				 ot d = *itp;
				 q.erase(itp);
				 q.erase(h);
				 q.insert(ot(d.l, d.r + 1, c));
				 printf("%d\n", sz(q));
				 continue;
			}
			if (itt->c == c)
			{
				ot d = *itt;
				q.erase(itt);
				q.erase(h);
				q.insert(ot(d.l - 1, d.r, c));
				printf("%d\n", sz(q));
				continue;
			}
			q.erase(h);
			q.insert(ot(x, x, c));
			printf("%d\n", sz(q));
		}
	}		
	return 0;
}