#include <bits/stdc++.h>
#define dbg(x) cerr<<#x<<'='<<x<<endl
using namespace std;
template <class T> 
void dbgarr(T &a, int s, int len) {for (int i=s; i<s+len; i++) cerr << a[i] << ' ';cout << endl;}

int n, m;
char buffer[1100][1100];
char mapp[1100][1100];
int sx, sy;
int mlx, mly;
int xx, yy;

void fsxy()
{
	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (buffer[i][j] == 'X') 
			{
				sx = i;
				sy = j;
				return;
			}
}

bool confirm(int xx, int yy)
{
	memset(mapp, '.', sizeof(mapp));
	int bx = sx;
	int by = sy;
	int ex = sx + xx - 1;
	int ey = sy + yy - 1;
	for (int i=bx; i<=ex; i++)
		for (int j=by; j<=ey; j++) 
			mapp[i][j] = 'X';

	while (1)
	{
		int tx = ex, ty = ey;
		while (tx+1 <=n && buffer[tx+1][by] == 'X') tx++;
		if (tx != ex) 
		{
			int dt = tx - ex;
			for (int i=ex+1; i<=tx; i++)
				for (int j=by; j<=ey; j++)
					mapp[i][j] = 'X';
			bx += dt;
			ex += dt;
			continue;
		}
		while (ty+1 <=m && buffer[bx][ty+1] == 'X') ty++;
		if (ty != ey)
		{
			int dt = ty - ey;
			for (int i=bx; i<=ex; i++)
				for (int j=ey+1; j<=ty; j++)
					mapp[i][j] = 'X';
			by += dt;
			ey += dt;
			continue;
		}
		break;
	}

	for (int i=1; i<=n; i++)
		for (int j=1; j<=m; j++)
			if (mapp[i][j] != buffer[i][j]) return false;
	return true;
}

bool confirmY()
{
	yy = mly;
	if (buffer[sx+mlx-1][sy+mly] != 'X') xx = 1;
	else
	{
		for (int i=sx+mlx-1; i>=1; i--)
		{
			if (buffer[i][sy+mly] == 'X') xx = (sx + mlx - 1) - i + 1;
			else break;
		}
	}
//	cout << xx << ' ' << yy << endl;
	return confirm(xx, yy);
}

bool confirmX()
{
	xx = mlx;
	if (buffer[sx+mlx][sy+mly-1] != 'X') yy = 1;
	else
	{
		for (int j = sy+mly-1; j>=1; j--)
		{
			if (buffer[sx+mlx][j] == 'X') yy = (sy + mly - 1) - j + 1;
			else break;
		}
	}
	return confirm(xx, yy);
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++) scanf("%s", buffer[i]+1);

	fsxy();
	for (int i=1; sx+i-1<=n; i++)
	{
		if (buffer[sx+i-1][sy] == 'X') mlx = i;
		else break;
	}
	for (int i=1; sy+i-1<=m; i++)
	{
		if (buffer[sx][sy+i-1] == 'X') mly = i;
		else break;
	}

//	cout << mlx <<' ' << mly << endl;
	
	int ans = 1e9;
	if (confirmX()) ans = min(ans, xx * yy);
	if (confirmY()) ans = min(ans, xx * yy);
	if (ans == 1e9) printf("-1\n");
	else printf("%d\n", ans);
}
