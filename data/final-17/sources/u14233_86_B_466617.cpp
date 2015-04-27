#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <iostream>
#include <queue>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include "string.h"
using namespace std;
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(i,a,b) for (int _n(b), i(a); i < _n; i++)
#define FORD(i,a,b) for(int i=(a),_b=(b);i>=_b;--i)
#define FOREACH(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,n) FOR(i,0,n)
#define ALL(c) (c).begin(), (c).end()
#define SORT(c) sort(ALL(c))
#define REVERSE(c) reverse(ALL(c))
#define UNIQUE(c) SORT(c),(c).resize(unique(ALL(c))-(c).begin())
#define INF 1000000000
#define X first
#define Y second
#define pb push_back
#define SZ(c) (c).size()
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VPII;
typedef vector<VI> VVI;

int n, m;

int r[1024][1024];

int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w+", stdout);

	cin >> n >> m;

	vector <string> a(n), res;

	REP (i, n)
		cin >> a[i];

	res = a;

	int c = 0;

	REP (i, n)
		REP (j, m)
			r[i][j] = -1;

	REP (i, n)
		REP (j, m)
			if (a[i][j] == '.')
			{
				if (i+1<n && a[i+1][j]=='.')
				{
					r[i][j] = c;
					r[i+1][j] = c++;
					a[i][j] = '#';
					a[i+1][j] = '#';
				}
				else if (j+1<m && a[i][j+1]=='.')
				{
					r[i][j] = c;
					r[i][j+1] = c++;
					a[i][j] = '#';
					a[i][j+1] = '#';
				}
			}

	VPII d;
	d.pb (PII(1, 0));
	d.pb (PII(-1, 0));
	d.pb (PII(0, 1));
	d.pb (PII(0, -1));

	REP (i, n)
		REP (j, m)
			if (a[i][j] == '.')
			{
				bool ok = false;

				REP (dd, d.size())
				{
					int x = i+d[dd].X;
					int y = j+d[dd].Y;

					if (x<0 || x>=n || y<0 || y>=m)
						continue;

					if (r[x][y] != -1)
					{
						r[i][j] = r[x][y];
						ok = true;
					}
				}

				if (!ok)
				{
					cout << -1 << endl;
					return 0;
				}
			}

	VVI e(c);

	REP (i, n)
		REP (j, m)
		{
			if (i+1<n)
			{
				int x = r[i][j];
				int y = r[i+1][j];

				if (x!=-1 && y!=-1 && x!=y)
					e[max(x, y)].pb (min(x,y));
			}

			if (j+1<m)
			{
				int x = r[i][j];
				int y = r[i][j+1];

				if (x!=-1 && y!=-1 && x!=y)
					e[max(x, y)].pb (min(x,y));
			}
		}

	VI col(c);
	bool used[10];

	REP(i, c)
	{
		memset(used, 0, sizeof(used));
		REP (j, e[i].size())
		{
			used[col[e[i][j]]] = true;
		}

		while (used[col[i]])
			col[i]++;

	}

	REP (i, n)
		REP (j, m)
			if (r[i][j]!=-1)
				res[i][j] = '0'+col[r[i][j]];

	REP (i, n)
		cout << res[i] << endl;

	return 0;
}
