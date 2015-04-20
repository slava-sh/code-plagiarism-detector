#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

const int MAXW = 501;
int a[MAXW][MAXW];
int qx[MAXW * MAXW * 2];
int qy[MAXW * MAXW * 2];
int d[MAXW][MAXW];
char p[MAXW][MAXW];

string s;
int mx[4] = {0, 1, 0, -1};
int my[4] = {1, 0, -1, 0};
char mc[4] = {'E', 'S', 'W', 'N'};
	int w, h, n;
vector <char> ss;
bool gd(int x, int y)
{
	return ((x >= 0) && (y >= 0) && (x < h) && (y < w));
}

int main()
{
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> w >> h >> n;
	int sx, sy;

	for (int i = 0; i < h; i++)
	{
		cin >> s;
		for (int j = 0; j < w; j++)
		{
			d[i][j] = MAXW * MAXW;
			a[i][j] = 1;
			if (s[j] == 'V') sx = i, sy = j;
			if (s[j] == 'T') a[i][j] = 0;
		}
	}
	d[sx][sy] = 0;
	int qb = MAXW * MAXW;
	int qe = qb;
	qx[qe] = sx, qy[qe] = sy;
	qe++;
	for (int i = 0; i < h * w; i++)
	{
		int x = qx[qb], y = qy[qb];
		qb++;
		for (int j = 0; j < 4; j++)
		{
			int nx = x + mx[j], ny = y + my[j];
			if (!gd(nx, ny)) continue;
			int nd = d[x][y] + a[nx][ny];
			if (d[nx][ny] > nd)
			{
				d[nx][ny] = nd;
				p[nx][ny] = mc[j];
				if (a[nx][ny])
				{
					qx[qe] = nx;
					qy[qe] = ny;
					qe++;
				}
				else
				{
					qb--;
					qx[qb] = nx;
					qy[qb] = ny;
				}
			}
		}
	}
	int res = MAXW * MAXW;
	int bi = -1, bj = -1;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < w; j++)
		{
			if (a[i][j] == 1) continue;
			if (res > d[i][j] + 2 * (n - 1))
			{
				res = d[i][j] + 2 * (n - 1);
				bi = i, bj = j;
			}
			for (int l = 0; l < 4; l++)
			{
				int nx = i + mx[l], ny = j + my[l];
	    		if (!gd(nx, ny)) continue;
				if (a[nx][ny] == 0)
				{
					if (res > d[i][j] + n - 1)
					{
						res = d[i][j] + n - 1;
						bi = i, bj = j;
					}
				}
			}
		}
	}
	int cbi = bi, cbj = bj;
	int cn = n;
	while ((bi != sx) || (bj != sy))
	{
		char pp = p[bi][bj];
		if (a[bi][bj] == 0) cn--;
		ss.push_back(pp);
		for (int i = 0; i < 4; i++)
		{
			if (mc[i] != pp) continue;
			bi -= mx[i], bj -= my[i];
		}
	}
	for (int i = ss.size() - 1; i >= 0; i--)
	{
		cout << ss[i];
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = cbi + mx[i], ny = cbj + my[i];
	    if (!gd(nx, ny)) continue;
		if (a[nx][ny] == 0)
		{
			for (int j = 0; j < 2 * n; j++)
			{
				if (cn == 0) break;
				cn--;
				if (j % 2 == 0) cout << mc[i];
				else cout << mc[(i + 2) % 4];
			}
			return 0;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = cbi + mx[i], ny = cbi + my[i];
	    if (!gd(nx, ny)) continue;
		for (int j = 0; j < 2 * n - 2; j++)
		{
			if (j % 2 == 0) cout << mc[i];
			else cout << mc[(i + 2) % 4];
		}
		return 0;
	}
	return 0;
}