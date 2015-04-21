#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct edge
{
	int to, t, id;
	edge(int to, int t, int id)
	{
		this->to = to;
		this->t = t;
		this->id = id;
	}
	edge(){}
};
int len[1007][1007];
int temp[1007];
vector<edge>g[1007];
const int INF = 100000007;
int main()
{
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 1; i <= m; i++)
	{
		int p, q, t;
		cin >> p >> q >> t;
		temp[i] = t;
		g[p].push_back(edge(q, t, i));
		g[q].push_back(edge(p, t, i));
	}
	int t;
	cin >> t;
	for (int tt = 1; tt <= t; tt++)
	{
		int a, b;
		cin >> a >> b;
		queue<pair<int, int> >q;
		for (int i = 0; i < 1007; i++)
		{
			for (int j = 0; j < 1007; j++)
			{
				len[i][j] = INF;
			}
		}
		for (int i = 0; i < 1007; i++)
		{
			len[a][i] = 0;
		}
		q.push(make_pair(a, -1));
		while (!q.empty())
		{
			pair<int, int>tmp = q.front();
			q.pop();
			int curv = tmp.first;
			bool canall = (tmp.second == -1);
			int lstt = (canall ? 0 : temp[tmp.second]);
			int curd = (canall ? 0 : len[curv][tmp.second]);
			for (int i = 0; i < g[curv].size(); i++)
			{
				if (canall || abs(lstt - g[curv][i].t) <= d)
				{
					int too = g[curv][i].to;
					if (curd + 1 < len[too][g[curv][i].id])
					{
						len[too][g[curv][i].id] = curd + 1;
						q.push(make_pair(too, g[curv][i].id));
					}
				}
			}
		}
		int ans = INF;
		for (int i = 0; i < 1007; i++)
		{
			ans = min(ans, len[b][i]);
		}
		if (ans>=INF/2)
		{
			cout << -1 << endl;
		}
		else
		{
			cout << ans << endl;
		}
	}
}