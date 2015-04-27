//#pragma comment(linker,"/STACK:256000000")

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <ctime>
#include <cassert>
#include <stdio.h>
#include <string>
#include <memory.h>

using namespace std;

#define ldb long double
#define LL long long
#define nextline() {int c; while ((c = getchar()) != 10 && c != EOF);}

#define PI 3.1415926535897932384626433832795
#define EPS 1e-9

#define sqr(x) ((x) * (x))
#define ABS(a) ((a)<0?-(a):(a))
#define EQ(a,b) (ABS((a)-(b))<EPS)

#define all(a) a.begin(), a.end()
#define two(i) (1 << (i))
#define has(mask, i) ((((mask) & two(i)) == 0) ? false : true)

const int INF = 1000 * 1000 * 1000;
const LL INF64 = 1000LL * 1000LL * 1000LL * 1000LL * 1000LL * 1000LL;

int n, m;
char d[1100][1100];
int a[1100][1100];


void Load()
{
	cin >> n >> m;
	nextline();
	for (int i = 0; i < n; i++)
		gets (d[i]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (d[i][j] == '.')
				a[i][j] = 0;
			else
				a[i][j] = -1;	

			
}

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int mark[10];

int was[1100][1100];
int was2[1100][1100];

void get_c(int i, int j)
{
	was[i][j] = 1;
	for (int k = 0; k < 4; k++)
		if (i + dx[k] >= 0 && i + dx[k] < n &&
			j + dy[k] >= 0 && j + dy[k] < m &&
			a[i + dx[k]][j + dy[k]] >= 0 && a[i + dx[k]][j + dy[k]] < 10)
				mark[a[i + dx[k]][j + dy[k]]] = 1;
   for (int k = 0; k < 4; k++)
		if (i + dx[k] >= 0 && i + dx[k] < n &&
			j + dy[k] >= 0 && j + dy[k] < m &&
			a[i + dx[k]][j + dy[k]] == a[i][j] && 
			!was[i + dx[k]][j + dy[k]])
				get_c (i + dx[k], j + dy[k]);
	
}

int st;
void color (int i, int j, int c)
{
	st++;
//	cerr << "here: " << i << " " << j << " " << c << "\n";
	was2[i][j] = 1;
	for (int k = 0; k < 4; k++)
		if (i + dx[k] >= 0 && i + dx[k] < n &&
			j + dy[k] >= 0 && j + dy[k] < m &&
			a[i + dx[k]][j + dy[k]] == a[i][j] && 
			!was2[i + dx[k]][j + dy[k]])
				color (i + dx[k], j + dy[k], c);	
	a[i][j] = c;
}


void Solve()
{
	int kol = 10;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)	
			if (a[i][j] == 0 && j + 1 < m && a[i][j + 1] == 0)
			{
				a[i][j] = kol;
				a[i][j + 1] = kol;
				kol++;
			}
	}
	for (int j = 0; j < m; j++)
	{
		for (int i = 0; i < n; i++)
			if (a[i][j] == 0 && i + 1 < n && a[i + 1][j] == 0)
			{
				a[i][j] = kol;
				a[i + 1][j] = kol;
				kol++;
			}
	}

/*	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cerr << a[i][j] << " ";
		cerr << "\n";
	}*/

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] == 0)
			{
				for (int k = 0; k < 4; k++)			
					if (i + dx[k] >= 0 && i + dx[k] < n &&
						j + dy[k] >= 0 && j + dy[k] < m &&
						a[i + dx[k]][j + dy[k]] > 0)
					{
						a[i][j] = a[i + dx[k]][j + dy[k]];
						break;
					}
				if (a[i][j] == 0)
				{
					cout << -1;
					return;
				}
			}
/*	cerr << "\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cerr << a[i][j] << " ";
		cerr << "\n";
	} */

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i][j] >= 10)
			{
				memset (mark, 0, sizeof (mark));
				get_c(i, j);
				for (int k = 0; k < 10; k++)
					if (!mark[k])
					{
						st = 0;
						color(i, j, k);
						if (st > 5)
						{
							cout << -1;
							return;
						}
						break;
					}
				if (a[i][j] >= 10)
				{
					cout << -1;
					return;
				}
			}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			if (a[i][j] >= 0)
				d[i][j] = '0' + a[i][j];
	}

	for (int i = 0; i < n; i++)
		puts (d[i]);
}
                
int main()
{
	//ios_base::sync_with_stdio(0);
#ifndef ONLINE_JUDGE
	freopen("in", "rt", stdin);
	freopen("out", "wt", stdout);
#endif
	Load();
	Solve();
	return 0;
}
