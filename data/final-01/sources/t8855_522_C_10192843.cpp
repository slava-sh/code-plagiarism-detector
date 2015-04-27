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

const int nmax = 100005;

int a[nmax], n, k, T, t[nmax], r[nmax], ans[nmax];
bool any[nmax];

bool read()
{
	scanf("%d%d",&n,&k);
	for (int i = 0; i < k; i ++)
	{
		scanf("%d",&a[i]);
		ans[i] = 0;
		any[i] = 0;
	}
	for (int i = 0; i < n - 1; i ++)
	{
		scanf("%d%d", &t[i], &r[i]);
		t[i]--;
	}
	return false;
}

void solve()
{
	int lft = 0, isFirst = 1;
	for (int i = 0; i < n - 1; i ++)
	{
		if (r[i] == 1)
		{
			if (isFirst)
			{
				int mn_id = -1;
				for (int j = i; j < n - 1; j ++)
				{
					if (t[j] >= 0)
						any[t[j]] = 1;
				}
				for (int j = 0; j < k; j ++)
				{
					if (any[j])
						continue;
					
					if (lft >= a[j])
					{
						ans[j] = 1;
					}

					if (mn_id == -1 ||
						a[mn_id] > a[j])
					{
						mn_id = j;
					}
				}

				lft -= a[mn_id];
				a[mn_id] = 0;
			}
			isFirst = 0;

			assert(lft >= 0);
		}

		if (t[i] >= 0)
			a[t[i]]--;
		else
			lft++;
	}

	for (int i = 0; i < k; i ++)
	{
		if (a[i] <= lft)
			ans[i] = 1;
	}

	for (int i = 0; i < k; i ++)
	{
		printf("%c", ans[i] ? 'Y' : 'N');
	}
	printf("\n");
}

int main()
{
	prepare();
	scanf("%d",&T);
	for (int i = 0; i < T; i ++)
	{
		read();
		solve();
	}
	return 0;
}
