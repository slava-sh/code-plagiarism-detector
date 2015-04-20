#include <vector>
#include <set>
#include <utility>
#include <climits>
#include <cstdio>

using namespace std;

struct Edge
{
	int to, capacity, flow, cost, reverse, number;
	Edge(){}
	Edge(int to, int cost, int reverse, int capacity = 0, int number = 0) : to(to), capacity(capacity), flow(0), cost(cost), reverse(reverse), number(number) {}
};

vector <vector <Edge> > graph;
vector <int> dist, p;
vector <pair<int, int> > parent;
int n, S, T;

bool dijkstra()
{
	dist.assign(n + 3, INT_MAX / 2);
	parent.assign(n + 3, make_pair(-1, -1));
	dist[S] = 0;
	parent[S] = make_pair(S, 0);
	set <pair<int, int> > q;
	q.insert(make_pair(0, S));
	while (q.size())
	{
		int v = q.begin()->second;
		q.erase(q.begin());
		for (int i = 0; i < graph[v].size(); ++i)
		{
			Edge e = graph[v][i];
			if (e.capacity - e.flow > 0 && dist[v] + p[v] - p[e.to] + e.cost < dist[e.to])
			{
				q.erase(make_pair(dist[e.to], e.to));
				parent[e.to] = make_pair(v, i);
				dist[e.to] = dist[v] + p[v] - p[e.to] + e.cost;
				q.insert(make_pair(dist[e.to], e.to));
			}
		}
	}
	for (int i = 0; i < n; ++i)
		p[i] += (parent[i].first == -1 ? 0 : dist[i]);
	return parent[T].first != -1;
}

int main()
{
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout); 
	int m;
	scanf("%d %d", &n, &m);
	S = n;
	T = n + 2;
	int Tprime = n + 1;
	graph.resize(n + 3);
	p.assign(n + 3, 0);
	vector <int> a(n);
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
		if (a[i] == 1)
		{
			graph[S].push_back(Edge(i, 0, graph[i].size(), 1)); /// !!!
			graph[i].push_back(Edge(S, 0, graph[S].size() - 1));
		}
		if (a[i] == 2)
		{
			graph[i].push_back(Edge(Tprime, 0, graph[Tprime].size(), 1)); // !!!
			graph[Tprime].push_back(Edge(i, 0, graph[i].size() - 1));
		}
	}
	int A, b, c;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &A, &b, &c);
		--A;
		--b;
		graph[A].push_back(Edge(b, c, graph[b].size(), 1, i + 1));
		graph[b].push_back(Edge(A, -c, graph[A].size() - 1));
		graph[b].push_back(Edge(A, c, graph[A].size(), 1, i + 1));
		graph[A].push_back(Edge(b, -c, graph[b].size() - 1));
	}
	graph[Tprime].push_back(Edge(T, 0, graph[T].size(), 1));
	graph[T].push_back(Edge(Tprime, 0, graph[Tprime].size() - 1));
	long long minCost = 0;
	while (dijkstra())
	{
		int cur = T;
		int minFlow = INT_MAX;
		while (parent[cur].first != cur)
		{
			Edge &e = graph[parent[cur].first][parent[cur].second];
			minFlow = min(minFlow, e.capacity - e.flow);
			cur = parent[cur].first;
		}
		cur = T;
		while (parent[cur].first != cur)
		{
			Edge &e = graph[parent[cur].first][parent[cur].second];
			e.flow += minFlow;
			minCost += (minFlow * e.cost);
			graph[e.to][e.reverse].flow -= minFlow;
			cur = parent[cur].first;
		}
	}
	int start = -1, end = -1;
	for (int i = 0; i < graph[S].size(); ++i)
	{
		Edge &e = graph[S][i];
		if (e.flow == 1)
		{
			start = e.to;
			break;
		}
	}
	for (int i = 0; i < graph[Tprime].size(); ++i)
	{
		Edge &e = graph[Tprime][i];
		if (e.flow == -1)
		{
			end = e.to;
			break;
		}
	}
	if (start == -1 || end == -1)
	{
		printf("-1\n");
		return 0;
	}
	printf("%d %d %d\n", start + 1, end + 1, minCost);
	return 0;
}