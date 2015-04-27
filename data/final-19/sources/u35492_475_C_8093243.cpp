//be naame khodaa

#include <bits/stdc++.h>

using namespace std;

int minC[1005], maxC[1005], minR[1005], maxR[1005];
char a[1005][1005];
bool mark[1005][1005];

int dfs(int x, int y)
{
	int ans = 1;
	mark[x][y] = true;
	if (a[x+1][y] == 'X' && !mark[x+1][y])
		ans += dfs(x+1, y);
	if (a[x][y+1] == 'X' && !mark[x][y+1])
		ans += dfs(x, y+1);
	return ans;
}

int main()
{
	int n, m, sx, sy, cnt = 0;
	bool f = false;
	cin >> n >> m;
	for (int i = 0; i < max(n, m); i++)
		minC[i] = minR[i] = 1000;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			cin >> a[j][i];
			if (a[j][i] == 'X')
			{
				cnt++;
				if (!f)
				{
					f = true;
					sx = j;
					sy = i;
				}
				minC[j] = min(minC[j], i);
				minR[i] = min(minR[i], j);
				maxC[j] = max(maxC[j], i);
				maxR[i] = max(maxR[i], j);
			}
		}
	if (dfs(sx, sy) != cnt)
		return (cout << -1 << endl), 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[j][i] == '.' && (minC[j] < i && minR[i] < j || maxC[j] > i && maxR[i] > j))
			{
				cout << -1 << endl;
				return 0;
			}


	if (a[maxR[sy]+1][maxC[sx]] != 'X' && a[maxR[sy]][maxC[sx]+1] != 'X')
	{
		cout << min(maxC[sx] - sy + 1, maxR[sy] - sx + 1) << endl;
		return 0;
	}

	char c;
	int minAns = -1;
	for (int i = 0; i < 2; i++)
	{
		c = (i? 'D' : 'R');
		int tx = sx, ty = sy;
		int h = -1, w = -1;
		bool error = false;
		int mycnt = 0;
		while (a[sx][sy] == 'X')
		{
			if (c == 'D')
			{
				if (w != -1 && w != maxR[sy] - sx + 1)
				{
					error = true;
					break;
				}
				w = maxR[sy] - sx + 1;
				int t = maxR[sy];
				while (a[sx][sy] == 'X' && sy < n && maxR[sy] == t)
				{
					sy++;
					mycnt += w;
				}
				if (sy < n && a[sx][sy] != 'X' && mycnt != cnt)
				{
					error = true;
					break;
				}
				c = 'R';
			}
			else
			{
				if (h != -1 && h != maxC[sx] - sy + 1)
				{
					error = true;
					break;
				}
				h = maxC[sx] - sy + 1;
				int t = maxC[sx];
				while (a[sx][sy] == 'X' && sx < m && maxC[sx] == t)
				{
					sx++;
					mycnt += h;
				}
				if (sx < m && a[sx][sy] != 'X' && mycnt != cnt)
				{
					error = true;
					break;
				}
				c = 'D';
			}
		}
		if (!error && (minAns == -1 || h*w < minAns))
			minAns = h*w;
		sx = tx; sy = ty;
	}
	cout << minAns << endl;

    return 0;
}
