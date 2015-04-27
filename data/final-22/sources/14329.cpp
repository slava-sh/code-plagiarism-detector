#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

const int MAXN = 500000;
const int INF = 1000000000;

int n,m;

struct graph
{
	int v;
	int w;
};

vector< vector<graph> > a;

void add(int i, int j, int w)
{
	graph g;
	g.v = j;
	g.w = w;
	a[i].push_back(g);
}

const int MAX = 4;

int t[5];

queue<int> q[MAX];
int minQ = 0;
vector<int> d;

int count = 0;

int get()
{
	int ans = q[minQ].front(); q[minQ].pop();
	count--;
	return ans;
}

void push(int i, int x)
{
	q[(minQ + i) % MAX].push(x);
	count++;
}

void bfs(int s, int f)
{
	push(0, s);
	d[s] = 0;
	while (count > 0)
	{
		while (!q[minQ].empty())
		{
			int x = get();
			for (int i = 0; i < a[x].size(); i++)
				if (d[a[x][i].v] > d[x] + t[a[x][i].w])
				{
					d[a[x][i].v] = d[x] + t[a[x][i].w];
					push(MAX - a[x][i].w, a[x][i].v);
				}
		}
		minQ = (minQ + 1) % MAX;
	}
}

int main()
{
	freopen("graph.in", "r", stdin);
	freopen("graph.out", "w", stdout);
	t[1] = 12, t[2] = 6, t[3] = 4, t[4] = 3;
	int x,y,w;
	scanf("%d%d", &n, &m);
	d.reserve(n); d.resize(n);
	a.reserve(n); a.resize(n);
	for (int i = 0; i < n; i++)
	{
		d[i] = INF;
	}
	for (int i = 0; i < m; i++)
	{
		scanf("%d%d%d", &x, &y, &w);
		x--, y--;
		add(x, y, w);
		add(y, x, w);
	}
	bfs(0, n - 1);
	for (int i = 1; i < n; i++)
	{
		printf("%.8f\n", ((double)(d[i]) / 12));
	}	

	return 0;
}

