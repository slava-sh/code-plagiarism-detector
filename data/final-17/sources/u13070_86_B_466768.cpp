#include <cstdio>
#include <algorithm>
using namespace std;
char Map[1146][1146];
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int Ans[1146][1146];
bool used[10];
int curColor;
int nColor;
int N, M;
void dfs(int x, int y)
{
	if (x < 0 || y < 0 || x >= N || y >= M) return;
	if (Ans[x][y] < 10) used[Ans[x][y]] = true;
	if (Ans[x][y] != curColor) return;
	Ans[x][y] = nColor;
	for (int k = 0; k < 4; ++k)
	{
		int nx = x + dir[k][0];
		int ny = y + dir[k][1];
		dfs(nx, ny);
	}
}
void rename(int x, int y)
{	
	for (int i = 0; i < 10; ++i)
		used[i] = false;
	curColor = Ans[x][y];
	nColor = 10005000;
	dfs(x, y);
	curColor = nColor;
	for (int i = 0; i < 10; ++i)
		if (!used[i]) nColor = i;
	dfs(x, y);
}
int cnt = 0;
int q(int i, int j)
{
	if (Map[i][j] != '.') return 0;
	for (int k = 0; k < 4; ++k)
	{
		int nx = i + dir[k][0];
		int ny = j + dir[k][1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (Map[nx][ny] == '.')
		{
			Ans[i][j] = cnt;
			Ans[nx][ny] = cnt;
			++cnt;
			Map[nx][ny] = 'u';
			Map[i][j] = 'u';
			return 0;
		}
	}
	for (int k = 0; k < 4; ++k)
	{
		int nx = i + dir[k][0];
		int ny = j + dir[k][1];
		if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
		if (Map[nx][ny] == 'u')
		{
			Ans[i][j] = Ans[nx][ny];
			Map[i][j] = 'u';
			return 0;
		}
	}
	printf ("-1");
	return -1;
}
int main()
{
#ifdef _DEBUG
	freopen("test.txt", "r", stdin);
#endif
	
	scanf ("%d%d", &N, &M);
	for (int i = 0; i < N; ++i)
	{
		scanf ("%s", Map[i]);
	}
	
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (q(i, j) == -1)
				return 0;
		}
	}
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (Map[i][j] == 'u')
			{
				if (Ans[i][j] > 9)
				{
					rename(i, j);
				}
				Map[i][j] = Ans[i][j] + '0';
			}
		}
	}
	for (int i = 0; i < N; ++i)
	{
		puts(Map[i]);
	}
	return 0;
}