#include <iostream>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

#define mod 1000000000000000007ll

set <pair <int, int> > st;
char a[301][301];
int n, dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1}, m, t;
map <long long, long long> d[7], was[7];
long long mask[400001];

void calc(int cnt, long long h)
{
	if (cnt == 0)
	{
		d[cnt][h] = 1;
		return;
	}

	long long newh = 0;

	for (set <pair <int, int> > :: iterator it = st.begin(); it != st.end(); ++it)
	{
		pair <int, int> v = *it;
		for (int i = 0; i < 4; ++i)
		{
			int x = v.first + dx[i];
			int y = v.second + dy[i];

			if (x >= 0 && x < n && y >= 0 && y < m && a[x][y] != '*')
			{
				newh = (h + mask[x * m + y]) % mod;
				if (was[cnt - 1][newh])
					continue;
				was[cnt - 1][newh] = 1;
				a[x][y] = '*';
				st.insert(make_pair(x, y));
				calc(cnt - 1, newh);
				d[cnt][h] += d[cnt - 1][newh];
				st.erase(make_pair(x, y));
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

	long long h = 0;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == '*')
				st.insert(make_pair(i, j)), h = (h + mask[i * m + j]) % mod;
		}				

	calc(t, h);

	cout << d[t][h];
}
