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

const int MAXN = 100 * 1000 + 10;

char c[MAXN];
vector<int> v[MAXN];
bool mark[MAXN], seen[MAXN];
int cnt[MAXN];

int main ()
{
	ios::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) v[i].pb(0);

	int start = 0;
	for (int i = 1; i <= m; i ++)
	{
		int x;
		cin >> c[i] >> x;
		v[x].pb(i);

		if (!seen[x])
		{
			seen[x] = true;
			if (c[i] == '-') start ++;
		}
	}

	int tot = start;
	cnt[0] = start;
	for (int i = 1; i <= m; i ++)
	{
		tot += (c[i] == '+' ? 1 : -1);
		cnt[i] = tot;
	}
	
	for (int i = 1; i <= n; i ++)
	{
		for (int j = 1; j < SZ(v[i]); j ++)
			if (c[v[i][j]] == '+')
			{
				if (v[i][j] - v[i][j - 1] > 1)
				{
					mark[i] = true;
					break;
				}
				if (cnt[v[i][j - 1]] != 0)
				{
					mark[i] = true;
					break;
				}
			}
		if (c[v[i].back()] == '-') 
		{
			if (m - v[i].back() > 0) mark[i] = true;
			if (cnt[m] > 0) mark[i] = true;
		}
	}

	vector<int> ans;
	for (int i = 1; i <= n; i ++)
		if (!mark[i]) ans.pb(i);
	cout << SZ(ans) << endl;
	FOREACH(i, ans) cout << *i << ' ';
	cout << endl;
	return 0;
}

