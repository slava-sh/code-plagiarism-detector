//#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <cmath>
#include <string>
#include <queue>


using namespace std;

const int maxN = 2e5;

struct edge
{
	int x;
	int y;
	long long t;
	edge(){}
	edge(int x1, int y1, long long t1)
	{
		x = x1;
		y = y1;
		t = t1;
	}
};

vector <vector <int> >list;
vector <vector <int> >listrev;
vector <edge> v;
vector <vector <int> > list1;
int L[maxN];
bool used[maxN];

int main()
{
	int n, m;
	long long d;
	cin >> n >> m >> d;
	list.resize(2 *(n+ 1 + m));
	list1.resize(2 *(m+ 1 + n));
	listrev.resize(2 *(m+ 1 + n));
	for(int i = 1; i <= m; i++)
	{
		int x, y;
		long long t;
		cin >> x >> y >> t;
		list[x].push_back((int)v.size());
		listrev[y].push_back((int)v.size());
		v.push_back(edge(x, y, t));
		list[y].push_back((int)v.size());
		listrev[x].push_back((int)v.size());
		v.push_back(edge(y, x, t));
	}
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < (int)list[i].size(); j++)
		{
			for(int tj = 0; tj < (int)listrev[i].size(); tj++)
			{
				int t1 = list[i][j];
				int t2 = listrev[i][tj];
				if(abs(v[t1].t - v[t2].t) <= d)
				{
					list1[t2].push_back(t1);
				}
			}
		}
	}
	int Q;
	cin >> Q;
	for(int i = 1; i <= Q; i++)
	{
		for(int j = 0; j < maxN; j++)
		{
			used[j] = false;
			L[j] = 1e9;
		}
		int x, y;
		cin >> x >> y;
		queue <int> q;
		for(int j = 0; j < (int)list[x].size(); j++)
		{
			q.push(list[x][j]);
			used[list[x][j]] = true;
			L[list[x][j]] = 0;
		}
		while(!q.empty())
		{
			int vv = q.front();
			q.pop();
			for(int j = 0; j < (int)list1[vv].size(); j++)
			{
				int to = list1[vv][j];
				if(!used[to])
				{
					L[to] = L[vv] + 1;
					used[to] = true;
					q.push(to);
				}
			}
		}
		int ans = 1e9;
		for(int j = 0; j < (int)listrev[y].size(); j++)
		{
			if(used[listrev[y][j]] && ans > L[listrev[y][j]])
			ans = min(ans, L[listrev[y][j]]);
		}
		if(ans >= 1e9)
		{
			cout << -1 << "\n";
			continue;
		}
		cout << ans + 1 << endl;
	}

	return 0;
}