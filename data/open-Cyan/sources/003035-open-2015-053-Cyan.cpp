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
const ldb eps = 1e-10;

struct pt
{
	ldb x, y;
	pt() { }
	pt(ldb x, ldb y) : x(x), y(y) { }
};

struct seg
{
	pt a, b;
	int n;
	seg() { }
	seg(pt a, pt b, int n) : a(a), b(b), n(n) { }
};

struct lin
{
	ldb a, b, c;
	lin() { } 
	lin(ldb a, ldb b, ldb c) : a(a), b(b), c(c) { }
};

lin line(seg a)
{
	return lin(a.a.y - a.b.y, a.b.x - a.a.x, a.a.x * a.b.y - a.a.y * a.b.x);
}

vector <seg> a[N];

bool ls(vector <seg> c, vector <seg> b)
{
	int s = 0, t = 0;
	for (; s < sz(c) && t < sz(b);)
	{
		if (fabs((c[s].b.y - c[s].a.y) / (c[s].b.x - c[s].a.x) - (b[t].b.y - b[t].a.y) / (b[t].b.x - b[t].a.x)) < eps)
		{
			if (max(c[s].b.y, c[s].a.y) >= b[t].b.y && b[t].b.y >= min(c[s].b.y, c[s].a.y))
				++t;
			else
				++s;
			continue;
		}
		if ((c[s].b.y - c[s].a.y) / (c[s].b.x - c[s].a.x) > (b[t].b.y - b[t].a.y) / (b[t].b.x - b[t].a.x) + eps)
			return 0;
		if ((c[s].b.y - c[s].a.y) / (c[s].b.x - c[s].a.x) + eps < (b[t].b.y - b[t].a.y) / (b[t].b.x - b[t].a.x))
			return 1;
	}
	return 0;
}

bool ins(seg a, seg b)
{
	lin q = line(b);
	lin t = line(a);
	if (a.b.y > (-q.c - q.a * a.b.x) / q.b + eps && (-q.c - q.a * a.b.x) / q.b >= min(b.b.y, b.a.y) && (-q.c - q.a * a.b.x) / q.b <= max(b.a.y, b.b.y))
		return 1;
	if (b.b.y + eps < (-t.c - t.a * b.b.x) / t.b && (-t.c - t.a * b.b.x) / t.b >= min(a.b.y, a.a.y) && (-t.c - t.a * b.b.x) / t.b <= max(a.a.y, a.b.y))
		return 1;
	return 0;
}


int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	ldb aa, bb;
	scanf("%Lf %Lf", &aa, &bb);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		int l;
		scanf("%d", &l);
		a[i].resize(l);
		for (int j = 0; j <= l; ++j)
		{
			ldb x, y;
			scanf("%Lf %Lf", &x, &y);
			if (j > 0)
			{
				a[i][j - 1].b = pt(x, y);
				a[i][j - 1].n = i + 1;
			}
			if (j < l)
				a[i][j].a = pt(x, y);
		}
	}
	sort(a, a + n, ls);
	for (int i = 0; i < n - 1; ++i)
	{
		int s = 0, t = 0;
		bool q = 0;
		for (; s < sz(a[i]) && t < sz(a[i + 1]); )
		{
			if (ins(a[i][s], a[i + 1][t]))
			{
				q = 1;
				break;
			}
			if (a[i][s].b.x < a[i + 1][t].b.x)
				++s;
			else
				++t;
		}
		if (q || a[i][sz(a[i]) - 1].b.y > a[i + 1][sz(a[i + 1]) - 1].b.y)
		{
			printf("No\n%d %d", a[i][0].n, a[i + 1][0].n);
			return 0;
		}
	}
	printf("Yes");
	return 0;
}