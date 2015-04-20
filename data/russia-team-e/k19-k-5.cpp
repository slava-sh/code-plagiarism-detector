#include <iostream>
#include <map>
#include <cstdio>

using namespace std;

#define mod 1000007

char a[301][301];
int n, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, m, t, sz;
int d[7][1000008], was[7][1000008], mask[400001];
pair <int, int> vec[100];

void calc(int cnt, int h)
{
	if (cnt == 0)
	{
		d[cnt][h] = 1;
		return;
	}

	int newh = 0, x, y;
	
	for (int i = 1; i <= sz; ++i)
	{
		pair <int, int> v = vec[i];
		for (int i = 0; i < 4; ++i)
		{
			x = v.first + dx[i];
			y = v.second + dy[i];

			if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*')
			{
				newh = (h + mask[x * m + y]) % mod;
				if (was[cnt - 1][newh] > 0)
					continue;
				was[cnt - 1][newh] = 1;
				a[x][y] = '*';
				vec[++sz] = make_pair(x, y);
				calc(cnt - 1, newh);
				d[cnt][h] += d[cnt - 1][newh];
				--sz;
				a[x][y] = '.';
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
			mask[i * m + j] = (mask[i * m + j - 1] * 11ll) % mod;

	int h = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '*')
				vec[++sz] = make_pair(i, j), h = (h + mask[i * m + j]) % mod;
		}				

	calc(t, h);

	cout << d[t][h];
}
