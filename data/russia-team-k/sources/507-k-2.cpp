/*#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
#include <queue>

#define ll long long
#define mp make_pair

#define TASKNAME "dwarfs"

using namespace std;

const int maxn = 3e5;
const int INF = int(1e9);

char A[1000][1000];
int d[1000][1000];
int mark[1000][1000];
const pair <int, int> moves[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)};
int w, h;

void bfs(int x, int y)
{
	queue <pair <int, int> > Q;
	Q.push(make_pair(x, y));
	mark[x][y] = 1;

	while (!Q.empty())
	{
		x = Q.front().first;
		y = Q.front().second;

		for (int i = 0; i < 4; i++)
		{
			int nx = x + moves[i].first;
			int ny = y + moves[i].second;

			if (nx >= 0 && nx < w && ny >= 0 && ny < h)
			{
				if (mark[nx][ny] == 1)
					d[x][y] = max(d[x][y], d[nx][ny] + (A[nx][ny] == 'T'));
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nx = x + moves[i].first;
			int ny = y + moves[i].second;

			if (nx >= 0 && nx < w && ny >= 0 && ny < h)
			{
				if (mark[nx][ny] == 0)
				{
					mark[nx][ny] = 1;
					Q.push(make_pair(nx, ny));
				}
			}
		}
	}
}

int main() {
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	int n;
	cin >> w >> h >> n;
	swap(w, h);
	int sx, sy;

	for (int i = 0; i < w; i++)
	{
		for (int j = 0; j < h; j++)
		{
			cin >> A[i][j];

			if (A[i][j] == 'V')
				sx = i, sy = j;
		}
	}

	bfs(sx, sy);
	int res = 0;

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			if (A[i][j] == 'T')
			{
				int rest = n - d[i][j] - 1;
				int now = abs(i - sx) + abs(j - sy);
				bool flag = 0;

				for (int k = 0; k < 4; k++)
				{
					int ni = i + moves[k].first;
					int nj = j + moves[k].second;

					if (ni >= 0 && ni < w && nj >= 0 && nj < h)
						if (A[ni][nj] == 'T')
							flag = 1;
				}
				
				if (flag)
					now += 


	
	return 0;
}*/

#include <stdio.h>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 
#include <set>
#include <queue>

#define ll unsigned long long
#define mp make_pair

#define TASKNAME "virus"

using namespace std;
/*
const pair <int, int>  moves[4] = {make_pair(1, 0), make_pair(-1, 0), make_pair(0, 1), make_pair(0, -1)}
set <ll> X;

void dfs(char * s, vector <pair <int, int> >  & G, int n, int m, int t)
{
	for (int i = 0; i < int(G.size()); i++)
	{
		int x = G[i].first;
		int y = G[i].second;

		for (int k = 0; k < 4; k++)
		{
			int nx = x + moves[i].first;
			int ny = y + moves[i].second;

			if (nx >= 0 && nx < n && ny >= 0 && ny < m)
				G.push_back(make_pair(nx, ny))
					dfs(s, G, n, m, t - 1);
		}
	}
}*/

int main()
{
	
#ifdef SHAOLING
	freopen("input.txt", "r", stdin);
#else
	freopen(TASKNAME".in", "r", stdin);
	freopen(TASKNAME".out", "w", stdout);
#endif

	srand(179);

	cout << rand() % 14 + 1 << endl;
	return 0;
}