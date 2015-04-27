#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char s[1010][1010];
int n, m;
int x1, y1, x2, y2;
int f[1010][1010];
int flag;
int cnt;
int t;
bool check(int x, int y, int xx, int yy, int ttt)
{
	int tt = (xx - x + 1) * (yy - y + 1);
	if(tt == f[xx][yy] - f[x-1][yy] - f[xx][y-1] + f[x-1][y-1])
	{
		cnt += tt * ttt;
		return true;
	}
	return false;
}
void move(int x, int y, int xx, int yy)
{
	if(check(xx+1, y, xx+1, yy, 0) && check(x, yy+1, xx, yy+1, 0))
		return ;
	if(check(xx+1, y, xx+1, yy, 1))
		move(x+1, y, xx+1, yy);
	else if(check(x, yy+1, xx, yy+1, 1))
		move(x, y+1, xx, yy+1);
	return ;
}

bool solve()
{
	if(!check(x1, y1, x2, y2, 1))
		return false;
	move(x1, y1, x2, y2);
	if(cnt != f[n][m])
		return false;
	return true;
}
int main()
{
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%s", s[i] + 1);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			f[i][j] = f[i-1][j] + f[i][j-1] - f[i-1][j-1] + (s[i][j] == 'X');
	for(int i = n; i >= 1; i--)
		for(int j = m; j >= 1; j--)
			if(s[i][j] == 'X')
			{
				x1 = i;
				y1 = j;
			}
	int size = -1;
	for(int i = x1; i <= n; i++)
		for(int j = y1; j <= m; j++)
		{
			cnt = 0;
			x2 = i;
			y2 = j;
			t = (x2 -x1 + 1)*(y2 - y1 + 1);
			if(size != -1 && t >= size)
				continue;
			if(solve())
				if(size == -1 || t < size)
					size = t;
		}
	printf("%d\n", size);
	return 0;
}
