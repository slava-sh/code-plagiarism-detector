#define _USE_MATH_DEFINES  
#define _CRT_SECURE_NO_DEPRECATE  
  
#include <algorithm>  
#include <bitset>  
#include <cassert>  
#include <cmath>  
#include <cstdio>  
#include <cstdlib>  
#include <cstring>   
#include <deque>  
#include <functional>  
#include <iomanip>  
#include <iostream>  
#include <list>  
#include <map>  
#include <numeric>  
#include <queue>  
#include <set>  
#include <sstream>  
#include <stack>  
#include <string>  
#include <utility>  
#include <vector>  
  
using namespace std;  
  
#pragma comment(linker, "/STACK:64000000")  
  
#define problem "Khaustov"  

typedef long long int64;  
typedef unsigned char byte;  
typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef pair<int64, int64> pii64;
typedef pair<pii64, int> piii64;
typedef pair<double, int64> pdi;
typedef pair<pdi, int> pdii;
typedef pair<int, string> pis;
typedef vector<int> vi;  
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef vector<pii> vpii;  
typedef vector<vpii> vvpii;  
typedef vector<string> vs;  
typedef vector<vs> vvs;  
typedef list<int> li;  
typedef stringstream ss;  
  
#define y1 _dsfdsfkn
#define left _dsfdsf
#define right _dfjdsj
#define link _tsu_sux
#define prime 1103
#define eps 1e-9
#define inf 123456789
#define toMod 1000000007LL

int n, m;
int h, t, R;
pii H[1 << 9], T[1 << 9];
int f[1 << 9][1 << 9];
int dp[1 << 9][1 << 9];

inline void init()
{
	scanf("%d%d%d", &h, &t, &R);
	scanf("%d", &n);
	for (int i = 1; i <= n; ++i)
		scanf("%d%d", &H[i].first, &H[i].second);
	scanf("%d", &m);
	for (int i = 1; i <= m; ++i)
		scanf("%d%d", &T[i].first, &T[i].second);
	memset(f, -1, sizeof f);
	memset(dp, -1, sizeof dp);
}

inline int check(int x, int y)
{
	return (x + y <= R);
}

int game(int x, int y)
{
	if (x == 0 && y == 0) return 1;
	if (!check(x, y)) return 2;

	if (f[x][y] != -1) return f[x][y];

	f[x][y] = -2;
	int res = 2;

	int lim = min(x, n);
	for (int i = 1; i <= lim; ++i)
	{
		int dx = H[i].first;
		int dy = H[i].second;
		int nx = x - i + dx;
		int ny = y + dy;

		int cur = game(nx, ny);
		if (cur == -2) cur = 0;
		if (cur == 1) res = 1;
		if (cur == 0 && res == 2) res = 0;
	}

	lim = min(y, m);
	for (int i = 1; i <= lim; ++i)
	{
		int dx = T[i].first;
		int dy = T[i].second;
		int nx = x + dx;
		int ny = y - i + dy;

		int cur = game(nx, ny);
		if (cur == -2) cur = 0;
		if (cur == 1) res = 1;
		if (cur == 0 && res == 2) res = 0;
	}

	return f[x][y] = res;
}

int rec(int x, int y, int WIN)
{
	if (!check(x, y)) return 0;
	if (x == 0 && y == 0) return 0;

	if (dp[x][y] != -1) return dp[x][y];

	dp[x][y] = -2;

	int res = 123456789;
	if (WIN == 2) res = 0;

	int lim = min(x, n);
	for (int i = 1; i <= lim; ++i)
	{
		int dx = H[i].first;
		int dy = H[i].second;
		int nx = x - i + dx;
		int ny = y + dy;

		if (check(nx, ny) && dp[nx][ny] == -2) continue;

		int cur = game(nx, ny);
		if (cur != WIN) continue;

		if (WIN == 2)
			res = max(res, rec(nx, ny, WIN) + 1);
		else
			res = min(res, rec(nx, ny, WIN) + 1);
	}

	lim = min(y, m);
	for (int i = 1; i <= lim; ++i)
	{
		int dx = T[i].first;
		int dy = T[i].second;
		int nx = x + dx;
		int ny = y - i + dy;

		if (check(nx, ny) && dp[nx][ny] == -2) continue;

		int cur = game(nx, ny);
		if (cur != WIN) continue;

		if (WIN == 2)
			res = max(res, rec(nx, ny, WIN) + 1);
		else
			res = min(res, rec(nx, ny, WIN) + 1);
	}

	return dp[x][y] = res;
}

piii make(int x, int y, int z)
{
	return piii(x, pii(y, z));
}

priority_queue < piii, vector <piii>, greater <piii> > q;

int main()  
{  
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);

	init();

	int res = game(h, t);

	if (res == 0)
	{
		puts("Draw");
		return 0;
	}

	if (res == 1) puts("Ivan");
	if (res == 2) puts("Zmey");
	
	if (res == 2)
	{
		int res2 = rec(h, t, res);
		printf("%d\n", res2);
	} else {
		q.push(make(0, h, t));
		dp[h][t] = 0;
		while (!q.empty())
		{
			piii cur = q.top();
			q.pop();
			int x = cur.second.first;
			int y = cur.second.second;

			if (x + y > R) continue;

			int w = cur.first;
			if (dp[x][y] != w) continue;
			
			int lim = min(x, n);
			for (int i = 1; i <= lim; ++i)
			{
				int dx = H[i].first;
				int dy = H[i].second;
				int nx = x - i + dx;
				int ny = y + dy;
				
				if (dp[nx][ny] == -1 || dp[nx][ny] > dp[x][y] + 1)
				{
					dp[nx][ny] = dp[x][y] + 1;
					q.push(make(dp[nx][ny], nx, ny));
				}
			}

			lim = min(y, m);
			for (int i = 1; i <= lim; ++i)
			{
				int dx = T[i].first;
				int dy = T[i].second;
				int nx = x + dx;
				int ny = y - i + dy;
				
				if (dp[nx][ny] == -1 || dp[nx][ny] > dp[x][y] + 1)
				{
					dp[nx][ny] = dp[x][y] + 1;
					q.push(make(dp[nx][ny], nx, ny));
				}
			}
		}

		printf("%d\n", dp[0][0]);
	}
    return 0;  
}
