#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

const int INF = (int)1e9;
const int DX[] = {0, 1, 0, -1};
const int DY[] = {1, 0, -1, 0};
const char sumDir[] = {'E', 'S', 'W', 'N'}; //!!!!!!!!!!
const int N = 500 + 10;
const int MID = N * N;
int curT = 0;

struct Point
{
	int x, y;
	Point () {}
	Point (int x, int y) : x(x), y(y) {};
};

Point par[2][N][N];
int dist2[N][N];
Point st[2 * N * N];
char table[N][N];
char ans[N * N];
int dist[N][N], maxCnt[N][N];
int indAns = 0;
bool used[N][N];

int n;
int w, h;

char getDir(int a, int b, int ind)
{
	Point p = par[ind][a][b];
	for (int i = 0; i < 4; i++)
	{
		int nx = p.x + DX[i];
		int ny = p.y + DY[i];
		if (nx == a && ny == b)
		{
			return i;
		}
	}
}

void makePath(int a, int b, int c, int d, int ind)
{
	while (a != c || b != d)
	{
		if (table[a][b] == 'T')
			curT++;
		Point p = par[ind][a][b];
		ans[indAns++] = sumDir[getDir(a, b, ind)]; 
		a = p.x;
		b = p.y;
	}
}

bool check(int a, int b)
{
	return (a >= 0 && b >= 0 && a < w && b < h);
}

int getType(int a, int b)
{
	for (int i = 0; i < 4; i++)
	{
		int nx = a + DX[i];
		int ny = b + DY[i];
		if (check(nx, ny) && table[nx][ny] == 'T')
			return 1;
	}
	return 2;
}

int main()
{
	freopen ("travel.in", "r", stdin);
	freopen ("travel.out", "w", stdout);

	scanf("%d%d%d", &h, &w, &n);
	for (int i = 0; i < w; i++)
	{
		scanf(" %s", table[i]);
	}

	int stX, stY, endX, endY;
	for (int i = 0; i < w; i++)
		for (int s = 0; s < h; s++)
		{
			dist[i][s] = INF;
			if (table[i][s] == 'V')
			{
				dist[i][s] = 0;
				stX = i, stY = s;
			}
		}

	int l = 0, r = 0;
	st[r++] = Point(stX, stY);
	for (int i = l; i < r; i++)
	{
		Point cur = st[i];
		for (int s = 0; s < 4; s++)
		{
			int nx = cur.x + DX[s];
			int ny = cur.y + DY[s];
			if (check(nx, ny) && dist[nx][ny] > dist[cur.x][cur.y])
			{
				dist[nx][ny] = dist[cur.x][cur.y] + 1;
				par[0][nx][ny] = cur;
				if (!used[nx][ny])
					st[r++] = Point(nx, ny);
				used[nx][ny] = 1;
			}
		}
	}
	memset(used, 0, sizeof(used));
	
	l = MID, r = MID;
	st[r++] = Point(stX, stY);
	for (int i = 0; i < w; i++)
		for (int s = 0; s < h; s++)
		{
			dist2[i][s] = INF;
		}
	dist2[stX][stY] = 0;
	while (r - l > 0)
	{
		Point cur = st[l++];
		for (int i = 0; i < 4; i++)
		{
			int nx = cur.x + DX[i];
			int ny = cur.y + DY[i];
			if (check(nx, ny))
			{
				if (table[nx][ny] == 'T' && dist2[nx][ny] > dist2[cur.x][cur.y])
				{
					par[1][nx][ny] = cur;
					st[l - 1] = Point(nx, ny);
					dist2[nx][ny] = dist2[cur.x][cur.y];
					used[nx][ny] = 1;
					l--;
				}
				else if (table[nx][ny] != 'T' && dist2[nx][ny] > dist2[cur.x][cur.y] + 1)
				{
					par[1][nx][ny] = cur;
					st[r++] = Point(nx, ny);
					dist2[nx][ny] = dist2[cur.x][cur.y] + 1;
					used[nx][ny] = 1;
				}
			}
		}
	}
	int bestVal = INF;
	for (int i = 0; i < w; i++)
		for (int s = 0; s < h; s++)
		{
			if (maxCnt[i][s] <= n && table[i][s] == 'T')
			{
				int t = getType(i, s);
				int curVal;
				if (t == 1)
					curVal = dist2[i][s] + n;
				else
					curVal = dist[i][s] + (n - 1) * 2;
				if (curVal < bestVal)
				{
					bestVal = curVal;
					endX = i, endY = s;
				}
			}
		}
		
	if (getType(endX, endY) == 1)
		makePath(endX, endY, stX, stY, 1);
	else
		makePath(endX, endY, stX, stY, 0);

	for (int i = indAns - 1; i >= 0; i--)
		printf("%c", ans[i]);
	if (getType(endX, endY) == 2)
	{
		int d = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = endX + DX[i];
			int ny = endY + DY[i];
			if (check(nx, ny))
				d = i;
		}
		for (int i = curT; i < n; i++)
		{
			printf("%c%c", sumDir[d], sumDir[(d + 2) % 4]);
		}
	}
	else
	{
		int d = 0;
		for (int i = 0; i < 4; i++)
		{
			int nx = endX + DX[i];
			int ny = endY + DY[i];
			if (check(nx, ny) && table[nx][ny] == 'T')
				d = i;
		}
		for (int i = curT; i < n; i++)
		{
			printf("%c", sumDir[d]);
			d = (d + 2) % 4;
		}
	}

	return 0;
}