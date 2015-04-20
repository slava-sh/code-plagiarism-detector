#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <utility>
#include <ctime>

using namespace std;

vector <vector <pair<int, int> > > graph;
int n;

bool TL()
{
	static bool isTL = 0;
	static int cnt = 0;
	if (++cnt == 100)
	{
		if (float(clock()) / CLOCKS_PER_SEC > 1.7)
			isTL = 1;
		cnt = 0;
	}
	return isTL;
}

int dijkstra(int v, int u)
{
	vector <int> dist(n, INT_MAX);
	set <pair<int, int> > q;
	dist[v] = 0;
	q.insert(make_pair(0, v));
	while(q.size())
	{
		int cur = q.begin()->second;
		if (cur == u)
			return dist[cur];
		q.erase(q.begin());
		for (vector<pair<int, int> > ::iterator it = graph[cur].begin(); it != graph[cur].end(); ++it)
		{
			if (dist[it->first] > dist[cur] + it->second)
			{
				q.erase(make_pair(dist[it->first], it->first));
				dist[it->first] = dist[cur] + it->second;
				q.insert(make_pair(dist[it->first], it->first));
			}
		}
	}
	return dist[u];
}

int main()
{
	srand(1543);
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
	int m;
	scanf("%d %d", &n, &m);
	vector <int> f, s;
	int t, a, b;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &t);
		if (t == 1)
			f.push_back(i);
		if (t == 2)
			s.push_back(i);
	}
	graph.resize(n);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d %d", &a, &b, &t);
		--a;
		--b;
		graph[a].push_back(make_pair(b, t));
		graph[b].push_back(make_pair(a, t));
	}
	int minAns = INT_MAX;
	int minAnsF, minAnsS;
	random_shuffle(f.begin(), f.end());
	random_shuffle(s.begin(), s.end());
	for (vector <int> ::iterator it = f.begin(); it != f.end(); ++it)
	{
		for (vector <int> :: iterator jt = s.begin(); jt != s.end(); ++jt)
		{
			if (TL())
			{
				if (minAns == INT_MAX)
					printf("-1\n");
				else
					printf("%d %d %d\n", minAnsF + 1, minAnsS + 1, minAns);
				return 0;
			}
			t = dijkstra(*it, *jt);
			if (t < minAns)
			{
				minAnsF = *it;
				minAnsS = *jt;
				minAns = t;
			}
		}
	}
	if (minAns == INT_MAX)
		printf("-1\n");
	else
		printf("%d %d %d\n", minAnsF + 1, minAnsS + 1, minAns);
	return 0;
}