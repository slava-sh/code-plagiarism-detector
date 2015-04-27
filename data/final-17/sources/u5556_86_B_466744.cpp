#define _CRT_SECURE_NO_DEPRECATE
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<string>
#include<sstream>
#include<deque>
#include<math.h>
#include<cstring>
#include <bitset>
#include<algorithm>
#include<stdio.h>
#include<stdlib.h>

#define all(v) v.begin(),v.end()
#define mpair make_pair

using namespace std;
typedef long double ld;
const ld epsilon = 1e-9;
typedef long long ll;
int mat[1024][1024];
bool vis[1024][1024];
int main()
{
	//freopen("bobi.in", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	vector<string> v(n);
	for(int i = 0; i < n; i++)
		cin >> v[i];
	memset(mat, 0, sizeof(mat));
	memset(vis, false, sizeof(vis));
	int moves[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(v[i][j] != '.')
			{
				vis[i][j] = true;
				continue;
			}
			for(int k = 0; k < 4; k++)
			{
				if(i + moves[k][0] < 0 || i +  moves[k][0] >= n)
					continue;
				if(j + moves[k][1] < 0 || j +  moves[k][1] >= m)
					continue;

				if(v[i + moves[k][0]][j + moves[k][1]] == '.')
					mat[i][j]++;
			}
			if(mat[i][j] == 0)
			{
				cout << -1 << endl;
				return 0;
			}
		}
	}

	bool digs[10];
	pair<int, int> cur;
	int x, y;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			if(v[i][j] == '.')
			{
				vis[i][j] = true;
				v[i][j] = '-';
				memset(digs, false, sizeof(digs));
				vector<pair<int, int> > toProcess;
				toProcess.push_back(make_pair(i, j));
				bool pushed = false;
				for(int k = 0; k < 4; k++)
				{
					if(i + moves[k][0] < 0 || i +  moves[k][0] >= n)
						continue;
					if(j + moves[k][1] < 0 || j +  moves[k][1] >= m)
						continue;
					if(v[i + moves[k][0]][j + moves[k][1]] == '#')
						continue;
					if(v[i + moves[k][0]][j + moves[k][1]] == '.')
					{
						if(pushed && mat[i + moves[k][0]][j + moves[k][1]] != 1)
						{
							continue;
						}
						pushed = true;
						v[i + moves[k][0]][j + moves[k][1]] = '-';
						toProcess.push_back(make_pair(i + moves[k][0], j + moves[k][1]));
					}
					else if(isdigit(v[i + moves[k][0]][j + moves[k][1]]))
						digs[v[i + moves[k][0]][j + moves[k][1]] - '0'] = true;
				}
				for(int l = 0; l < toProcess.size(); l++)
				{
					cur = toProcess[l];
					for(int k = 0; k < 4; k++)
					{
						if(cur.first + moves[k][0] < 0 || cur.first +  moves[k][0] >= n)
							continue;
						if(cur.second + moves[k][1] < 0 || cur.second +  moves[k][1] >= m)
							continue;
						if(v[cur.first + moves[k][0]][cur.second + moves[k][1]] == '.')
						{
							if(mat[cur.first + moves[k][0]][cur.second + moves[k][1]] == 1)
							{
								x = cur.first + moves[k][0];
								y = cur.second + moves[k][1];
								for(int k1 = 0; k1 < 4; k1++)
								{
									if(x + moves[k1][0] < 0 || x +  moves[k1][0] >= n)
										continue;
									if(y + moves[k1][1] < 0 || y +  moves[k1][1] >= m)
										continue;
									if(isdigit(v[x + moves[k1][0]][y + moves[k1][1]]))
										digs[v[x + moves[k1][0]][y + moves[k1][1]] - '0'] = true;
								}
								v[x][y] = '-';
								toProcess.push_back(make_pair(cur.first + moves[k][0], cur.second + moves[k][1]));
							}
							else 
							{
								mat[cur.first + moves[k][0]][cur.second + moves[k][1]]--;
							}
						}
						else if(isdigit(v[cur.first + moves[k][0]][cur.second + moves[k][1]]))
							digs[v[cur.first + moves[k][0]][cur.second + moves[k][1]] - '0'] = true;
					}
				}

				int d = 0;
				for(int k = 0; k < 10; k++)
				{
					if(!digs[k])
					{
						d = k;
						break;
					}
				}
				for(int k = 0; k < toProcess.size(); k++)
				{
					v[toProcess[k].first][toProcess[k].second] = '0' + d;
				}
			}
		}
	}
	for(int i = 0; i < n; i++)
		cout << v[i] << endl;
	return 0;
}