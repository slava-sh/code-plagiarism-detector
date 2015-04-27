#include <iostream>
using namespace std;
const int MAX = 1005;
char a[MAX][MAX];
int par[MAX][MAX], cnt, stx, sty, n, m;
int get(int x1, int y1, int x2, int y2)
{
	return par[x2][y2] - par[x1][y2] - par[x2][y1] + par[x1][y1];
}
bool check(int x, int y)
{
	int i = stx, j = sty;
	int c = get(i, j, i + x, j + y);
	if (c != x * y)
		return false;
	while (true)
	{
		if (a[i + x][j] == 'X' && a[i][j + y] == 'X')
			return false;
		if (a[i + x][j] == 'X')
		{
			c += y;
			i++;
			if (get(i, j, i + x, j + y) != x * y)
				return false;
			continue;
		}
		if (a[i][j + y] == 'X')
		{
			c += x;
			j++;
			if (get(i, j, i + x, j + y) != x * y)
				return false;
			continue;
		}
		break;
	}
	return (c == cnt);
}
int main()
{
	ios::sync_with_stdio(false);
	stx = -1, sty = -1;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[i][j];
			if (a[i][j] == 'X')
			{
				cnt++;
				par[i + 1][j + 1] = 1;
				if (stx == -1)
				{
					stx = i;
					sty = j;
				}
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			par[i][j] += par[i - 1][j] + par[i][j - 1] - par[i - 1][j - 1];
	int lenx = 0, leny = 0;
	for (int i = stx; i <= n; i++)
		if (a[i][sty] != 'X')
		{
			lenx = i - stx;
			break;
		}
	for (int j = sty; j <= m; j++)
		if (a[stx][j] != 'X')
		{
			leny = j - sty;
			break;
		}
	int ans = 1000000000;
	for (int x = 1; x <= lenx; x++)
		if (check(x, leny))
			ans = min(ans, x * leny);
	for (int y = 1; y <= leny; y++)
		if (check(lenx, y))
			ans = min(ans, lenx * y);
	if (ans == 1000000000)
		ans = -1;
	cout << ans << endl;
	return 0;
}
