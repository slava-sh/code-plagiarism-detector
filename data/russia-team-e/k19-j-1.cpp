#include <cstdio>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <queue>

#define mp make_pair
#define F first
#define S second

using namespace std;
deque <pair<int, int> > q;
int ans, n, m, k, x, y, cntT[1010][1010], len[1010][1010];
char a[1010][1010], Mv[1010][1010];
pair <int, int> v, pr[1010][1010];
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char s[4] = {'S', 'N', 'E', 'W'};
bool was[1010][1010], f;

void back(int x, int y)
{
	if (pr[x][y] == mp(0, 0))
		return;
   	back(pr[x][y].F, pr[x][y].S);
   	cout << Mv[x][y];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);

	cin >> m >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'V')
			{
				q.push_back(mp(i, j));
				was[i][j] = 1;
			}
		}
	}

	while (!q.empty())
	{
		v = q.front();
		q.pop_front();
		for (int i = 0; i < 4; i++)
		{
			x = v.F + dx[i];
			y = v.S + dy[i];
			if (x > 0 && y > 0 && x <= n && y <= m && !was[x][y])
			{
				was[x][y] = 1;
				if (a[x][y] == 'T')
					q.push_front(mp(x, y));
				else
					q.push_back(mp(x, y));
				cntT[x][y] = cntT[v.F][v.S] + (a[x][y] == 'T');
				len[x][y] = len[v.F][v.S] + 1;
				Mv[x][y] = s[i];
				pr[x][y] = v;
			}
		}
	}
	ans = int(1e9);
	bool gf = 0;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			if (a[i][j] == 'T')
			{
				f = 0;
				for (int c = 0; c < 4; c++)
				{
					if (a[i + dx[c]][j + dy[c]] == 'T')
						f = 1;
				}
				if (cntT[i][j] >= k)
				{
					if (ans > len[i][j])
					{
						ans = len[i][j];
						v = mp(i, j);
						gf = 0;
					}
				}
				if (f)
				{
					if (ans > len[i][j] + k - cntT[i][j] && (k - cntT[i][j]) % 2 == 0)
					{
						ans = len[i][j] + k - cntT[i][j];
						v = mp(i, j);
						gf = 1;
					}
				}
				else
				{
					if (ans > len[i][j] + 2 * (k - cntT[i][j]))
					{
						ans = len[i][j] + 2 * (k - cntT[i][j]);
						v = mp(i, j);
						gf = 0;
					}
				}
			}
		}
	}
	int c = ans - len[v.F][v.S];
	back(v.F, v.S);
	if (gf)
	{
		for (int i = 0; i < 4; i++)
			if (a[v.F + dx[i]][v.S + dy[i]] == 'T')
			{
				for (int j = 1; j <= c / 2; j++)
					cout << s[i] << s[i ^ 1];
				return 0;
			}
	}
	else
	{
		for (int i = 0; i < 4; i++)
			if (a[v.F + dx[i]][v.S + dy[i]] > 0)
			{
				for (int j = 1; j <= c / 2; j++)
					cout << s[i] << s[i ^ 1];
				return 0;
			}
	}
}
