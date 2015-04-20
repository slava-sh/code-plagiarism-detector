#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <cstdio>

using namespace std;

char a[301][301];
int n, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, m, t, sz;
map <int, bool> was[7];
int mask[400001], ans;
pair <int, int> vec[100];

void calc(int cnt, int h, int last)
{
	if (cnt == 0)
	{
		ans++;
		return;
	}

	int newh = 0;
	int x, y;
	
	for (int i = last; i <= sz; ++i)
	{
		pair <int, int> v = vec[i];
		for (int j = 0; j < 4; ++j)
		{
			x = v.first + dx[j];
			y = v.second + dy[j];

			if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*')
			{
				newh = (h + mask[x * m + y]);
				if (!was[cnt - 1].count(newh))
				{
					was[cnt - 1][newh] = 1;
					a[x][y] = '*';
					vec[++sz] = make_pair(x, y);
					calc(cnt - 1, newh, i);
					--sz;
					a[x][y] = '.';
				}
			}
		}
	}

	return;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	freopen("virus.in", "r", stdin);
	freopen("virus.out", "w", stdout);

	cin >> n >> m >> t;

	mask[0] = 1;

	for (int i = 0; i < n; ++i)
		for (int j = (i == 0 ? 1 : 0); j < m; ++j)
			mask[i * m + j] = (mask[i * m + j - 1] * 11ll);

	int h = 0;

/*	a[0][0] = '*';
	a[n - 1][m - 1] = '*';
	a[0][m - 1] = '*';
	a[n - 1][0] = '*';
	a[25][25] = '*';
	a[25][50] = '*';
	a[50][25] = '*';
	a[50][50] = '*';*/
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '*')
				vec[++sz] = make_pair(i, j), h = (h + mask[i * m + j]);
		}				

	calc(t, h, 1);

	cout << ans;
}
