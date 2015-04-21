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
const int M = (int)5e3 + 1;
const ll inf = (ll)1e9 + 7;
const ldb eps = 1e-10;

int h[N];
int pos[N];
int a[M][M], b[M][M];

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &h[i]);
		--h[i];
		pos[h[i]] = i;
	}
	for (int i = 1; i < n; ++i)
		for (int j = 0; j < n; ++j)
			a[i][j] = a[i - 1][j] + (j < pos[i - 1]);
	for (int i = n - 2; i >= 0; --i)
		for (int j = 0; j < n; ++j)
			b[i][j] = b[i + 1][j] + (j > pos[i + 1]);
	int ans = 0;
	int s = -2, t = -2;
	for (int i = 0; i < n; ++i)
		for (int j = i + 1; j < n; ++j)
			if (ans > a[i][pos[j]] + a[j][pos[i]] + b[i][pos[j]] + b[j][pos[i]] - a[i][pos[i]] - a[j][pos[j]] - b[i][pos[i]] - b[j][pos[j]] + (pos[j] > pos[i]))
			{
				ans = a[i][pos[j]] + a[j][pos[i]] + b[i][pos[j]] + b[j][pos[i]] - a[i][pos[i]] - a[j][pos[j]] - b[i][pos[i]] - b[j][pos[j]] + (pos[j] > pos[i]);
				s = pos[i];
				t = pos[j];
			}
	printf("%d %d", s + 1, t + 1);
	return 0;
}