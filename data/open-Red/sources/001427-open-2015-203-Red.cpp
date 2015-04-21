#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <cstdio>

#define INF 1000000007

using namespace std;

typedef pair<pair<int, int>, int> Edge2;

struct Edge
{
	int dest;
	int temp;
	Edge(){}
	Edge(int dest, int temp) :dest(dest), temp(temp){}
};

struct Queue_Elem
{
	int vert;
	int min_t;
	int len;
	int max_t;
	Queue_Elem(){}
	Queue_Elem(int vert, int min_t, int max_t, int len) :vert(vert), min_t(min_t), max_t(max_t), len(len){}
};

int main()
{
	freopen("input.txt", "r", stdin);
	map<Edge2, bool> vis;
	int N, M, D;
	cin >> N >> M >> D;
	vector<vector<Edge> > gr(N);
	vector<Edge2> edges;
	for (int i = 0; i < M; i++)
	{
		int x, y, cost;
		cin >> x >> y >> cost;
		x--;
		y--;
		gr[x].push_back(Edge(y, cost));
		gr[y].push_back(Edge(x, cost));
		Edge2 a, b;
		a.first.first = x;
		a.first.second = y;
		a.second = cost;
		b.first.first = y;
		b.first.second = x;
		b.second = cost;
		edges.push_back(a);
		edges.push_back(b);
	}
	int Q;
	cin >> Q;
	for (int it = 0; it < Q; it++)
	{
		for (size_t i = 0; i < edges.size(); i++)
			vis[edges[i]] = false;
		vector<bool> done(N);
		int from, to;
		cin >> from >> to;
		from--;
		to--;
		done[from] = true;
		queue<Queue_Elem> q;
		q.push(Queue_Elem(from, -INF, INF, 0));
		bool did = false;
		while (!q.empty())
		{
			Queue_Elem now = q.front();
			if (now.vert == to)
			{
				cout << now.len << endl;
				did = 1;
				break;
			}
			q.pop();
			bool d = false;
			for (size_t i = 0; i < gr[now.vert].size(); i++)
			{
				if (gr[now.vert][i].temp < now.min_t || gr[now.vert][i].temp > now.max_t)
				{
					d = true;
					break;
				}
			}
			if (!d)
				done[now.vert] = true;
			for (size_t i = 0; i < gr[now.vert].size(); i++)
			{
				if (!done[gr[now.vert][i].dest] && !vis[make_pair(make_pair(now.vert, gr[now.vert][i].dest), gr[now.vert][i].temp)])
				{
					if (gr[now.vert][i].temp >= now.min_t && gr[now.vert][i].temp <= now.max_t)
					{
						q.push(Queue_Elem(gr[now.vert][i].dest, gr[now.vert][i].temp - D, gr[now.vert][i].temp + D, now.len + 1));
						vis[make_pair(make_pair(now.vert, gr[now.vert][i].dest), gr[now.vert][i].temp)] = true;
					}
				}
			}
		}
		if (!did)
			cout << -1 << endl;
	}
	return 0;
}