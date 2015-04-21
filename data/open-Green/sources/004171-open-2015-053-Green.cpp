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

const int N = (int)1e6 + 4;
const int M = (int)1e3 + 100;
const ll inf = (ll)1e12 + 7;
const int K = 11;

ll dp[K][M];
int a[M];
vi g[M];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n, k;
	cin >> n >> k;
	int s = 0;
	for (int i = 1; i * i <= n; ++i)
		if (n % i == 0)
		{
			a[s] = i;
			++s;
			if (n / i != i)
			{
				a[s] = n / i;
				++s;
			}
		}
	for (int i = 0; i < s; ++i)
		for (int j = 0; j < s; ++j)
			if (a[i] % a[j] == 0)
				g[i].pb(j);
	dp[0][0] = 1;
	for (int i = 1; i < s; ++i)
		dp[0][i] = inf;
	for (int i = 1; i <= k; ++i)
		for (int j = 0; j < s; ++j)
		{
			dp[i][j] = inf;
			for (int t = 0; t < sz(g[j]); ++t)
				dp[i][j] = min(dp[i][j], dp[i - 1][g[j][t]] * ll(a[j] / a[g[j][t]] + 1) / 2);
		}
	if (n == 1)
		cout << 1;
	else
		cout << dp[k][1];
	return 0;
}