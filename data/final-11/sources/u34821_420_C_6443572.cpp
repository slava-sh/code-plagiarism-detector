#include <iostream>
#include <iomanip>
#include <fstream>
#include <map>
#include <vector>
#include <list>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>
#include <ctime>
using namespace std;

#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define mp make_pair
#define VAL(x) #x << " = " << (x) << "   "
#define SQR(a) ((a) * (a))
#define SZ(x) ((int) (x).size())
#define ALL(x) (x).begin(), (x).end()
#define CLR(x, a) memset(x, a, sizeof x)
#define FOREACH(i, x) for(__typeof((x).begin()) i = (x).begin(); i != (x).end(); i ++)
#define FOR(i, n) for (int i = 0; i < (n); i ++)
#define X first
#define Y second
#define EPS (1e-8)

//#define cin fin
//#define cout fout

//ifstream fin("problem.in");
//ofstream fout("problem.out");

const int MAXN = 300 * 1000 + 10;

int deg[MAXN], t[MAXN];
pii e[MAXN];
map<pii, int> cnt;

int main ()
{
	ios::sync_with_stdio(false);

	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i ++)
	{
		int x, y;
		cin >> x >> y; x --, y --;

		deg[x] ++, deg[y] ++;
		t[x] ++, t[y] ++;
		cnt[mp(x, y)] ++; cnt[mp(y, x)] ++;
		
		e[i] = mp(x, y);
	}

	sort(deg, deg + n);
	ll ans = 0;
	for (int i = 0, j = n - 1; i < n; i ++)
	{
		while (j > i && deg[i] + deg[j] >= p) j --;
		ans += n - 1 - max(i, j);
	}

	for (int i = 0; i < n; i ++)
	{
		int x = e[i].X, y = e[i].Y;
		if (t[x] + t[y] >= p)
		{
			if (t[x] + t[y] - cnt[mp(x, y)] < p)
			{
				ans --;
				cnt[mp(x, y)] = cnt[mp(y, x)] = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}

