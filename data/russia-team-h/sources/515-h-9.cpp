#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<cassert>

using namespace std;
const int X = 5010, INF1 = 1e9;
const long long INF = 1e10;
bool used[X];
vector <int> g;
int table[X][X], new_table[X][X];
long long color[X], d[X], pr[X];

long long deij(int s)
{
	int i, z, k;
	long long mn = INF;
	for(i = 0; i < X; i++)
	{
		d[i] = INF;
	}
	d[0] = 0;
	for(z = 0; z < X; z++)
	{
		k = -1;
		mn = INF;
		for(i = 0; i < X; i++)
		{
			if(!used[i])
			{
			   mn = min(mn, d[i]);
			   if(mn == d[i])
			   {
				   k = i;
			   }
			}
		}
		if(k != -1 && mn >= INF)
		{
			break;
		}
		used[k] = true;
		for(i = 0; i < X; i++)
		{
			if(new_table[k][i] != 0)
			{
				if(d[i] >  d[k] + ((long long)new_table[k][i]))
				{
					pr[i] = k;
				}
				d[i] = min(d[i], d[k] + ((long long)new_table[k][i])); 
			}
		}
		
	}
	return d[1];
}

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int n, m, i, a, b, c, j;
	long long ans, x, y, delta = INF;
	cin >> n >> m;
	for(i = 0; i < n; i++)
	{
		cin >> color[i];
	}
	for(i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		a--;
		b--;
		table[a][b] = c;
		table[b][a] = c;
		if(color[a] + color[b] == 3 && delta > c)
		{
			delta = c;
			x = a;
			y = b;
			if(color[a] == 2)
			{
				swap(x, y);
			}
			x += 1;
			y += 1;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(color[i] == 0)
		{
			new_table[i + 2][0] = INF1;
			new_table[0][i + 2] = INF1;
			new_table[i + 2][1] = INF1;
			new_table[1][i + 2] = INF1;
			for(j = 0; j < n; j++)
			{
				if(color[j] == 0)
				{
					new_table[i + 2][j  + 2] = table[i][j];
					new_table[j + 2][i + 2] = table[j][i];
				}
				else if(color[j] == 1)
				{
					if(table[i][j] != 0)
					{
						new_table[i + 2][0] = min(table[i][j], new_table[i + 2][0]);
						new_table[0][i + 2] = new_table[i + 2][0];
					}
				}
				else if(color[j] == 2)
				{
					if(table[i][j] != 0)
					{
						new_table[i + 2][1] = min(table[i][j], new_table[i + 2][1]);
						new_table[1][i + 2] = new_table[i + 2][1];
					}
				}
			}
			if(new_table[i + 2][0] == INF1)
			{
				new_table[i + 2][0] = 0;
				new_table[0][i + 2] = 0;
			}
			if(new_table[i + 2][1] == INF1)
			{
				new_table[i + 2][1] = 0;
				new_table[1][i + 2] = 0;
			}
		}
	}
	ans = deij(0);
	if(min(ans, delta) >= INF)
	{
		cout << -1;
		return 0;
	}
	if(delta <= ans)
	{
		cout << x << ' ' << y << ' ' << delta;
		return 0;
	}
	i = 1;
	g.push_back(i);
	while(i != 0)
	{
		g.push_back(pr[i]);
		i = pr[i];
		assert(g.size() < 2 * n + 3);
	}
	reverse(g.begin(), g.end());
	for(i = 0; i < n; i++)
	{
		if(table[g[1] - 2][i] == d[g[1]] && color[i] == 1)
		{
			x = i;
		}
	}
	for(i = 0; i < n; i++)
	{
		if(table[g[g.size() - 2] - 2][i] == d[1] - d[g[g.size() - 2]] && color[i] == 2)
		{
			y = i;
		}
	}
	cout << x + 1 << ' ' << y + 1 << ' ' << d[1];
	return 0;
}