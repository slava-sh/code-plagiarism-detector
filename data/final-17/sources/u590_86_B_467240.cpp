#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cctype>
 
#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <list>
#include <iterator>
#include <functional>
 
using namespace std;
 
typedef long long int64;
typedef unsigned long long ull;
 
int64 labs(int64 a)
{
        return a<0 ? (-a) : a;
}
int64 max(int64 a, int64 b)
{
        return a>b?a:b;
}
int64 min(int64 a, int64 b)
{
        return a<b?a:b;
}
template<typename T> struct Point
{
        T x, y; Point(){} Point(T xx, T yy): x(xx), y(yy){}
};
template<typename T> bool operator <(const Point<T> &p1, const Point<T> &p2)
{
        return p1.x < p2.x || p1.x == p2.x && p1.y < p2.y;
}
 
#define mp make_pair
#define pb push_back
#define forn(i, n) for(int (i)=0; (i)<(n); (i)++)
#define forr(i, n) for(int (i)=(n)-1; (i)>=0; (i)--)
#define forit(i,c) for((i)=(c).begin(); (i)!=(c).end(); (i)++)
#define all(x) (x).begin(), (x).end()
#define zero(a) memset((a), 0, sizeof(a))
 
typedef vector<int> vint;
typedef vector<bool> vbool;
typedef vector<int64> vint64;
typedef Point<int> pint;
typedef Point<int64> pint64;

const int MAXN = 1005;
char mas[MAXN][MAXN];
int was[MAXN][MAXN];

const int di[] = {0, 0, 1, -1};
const int dj[] = {1, -1, 0, 0};

int n, m;
bool InBorder(int i, int j)
{
	return i >= 0 && j >= 0 && i < n && j < m; 
}



bool mask[10];
void dfs(int i, int j, int col)
{
	if (!InBorder(i, j) || mas[i][j] == '#' || mas[i][j] == '-')
		return;

	if (isdigit(mas[i][j]))
	{
		mask[mas[i][j]-'0'] = 1;
	}
	
	if (was[i][j] != col)
		return;

	mas[i][j] = '-';	
	forn(k, 4)
	{
		dfs(i+di[k], j+dj[k], col);
	}
}
void dfs1(int i, int j, char nc)
{
	if (!InBorder(i, j) || mas[i][j] != '-')
		return;

	mas[i][j] = nc;
	forn(k, 4)
	{
		dfs1(i+di[k], j+dj[k], nc);
	}
}

void Solve()
{
	forn(i, n)
	{
		forn(j, m)
		{
			if (mas[i][j] == '.')
			{
				zero(mask);
				dfs(i, j, was[i][j]);

				char col = '9';
				forn(k, 10)
				{
					if (!mask[k])
					{
						col = k+'0';
						break;
					}						
				}

				dfs1(i, j, col);
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	forn(i, n)
	{
		forn(j, m)
		{
			cin >> mas[i][j];
		}
	}
	
	zero(was);

	int col = 1;
	forn(i, n)
	{
		forn(j, m-1)
		{
			if (mas[i][j] == '.' && mas[i][j+1] == '.' 
			 && was[i][j] ==  0  && was[i][j+1] ==  0 )
			{
				was[i][j] = was[i][j+1] = col++;
			}
		}
	}
		
	forn(i, n-1)
	{
		forn(j, m)
		{
			if (mas[i][j] == '.' && mas[i+1][j] == '.' 
			 && was[i][j] ==  0  && was[i+1][j] ==  0 )
			{
				was[i][j] = was[i+1][j] = col++;
			}
		}
	}
	
	forn(i, n)
	{
		forn(j, m)
		{
			if (mas[i][j] == '.' && was[i][j] == 0)
			{
				bool ok = 0;
				forn(k, 4)
				{
					if (InBorder(i + di[k], j + dj[k]) && mas[i + di[k]][j + dj[k]] == '.')
					{
						was[i][j] = was[i + di[k]][j + dj[k]];
						ok = true;
						break;
					}
				}
				if (!ok)
				{
					cout << -1;
					return 0;
				}
			}
		}
	}

	Solve();

	forn(i, n)
	{
		forn(j, m)
		{
			cout << mas[i][j];
		}
		cout << endl;
	}


	return 0;
}


/*



*/
