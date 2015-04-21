#include <iostream>
#include <vector>
#include <fstream>
#include <set>
#include <string>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
#define mp make_pair
#define pb push_back
#define pp pop_back

struct Point {
	ld x, y;
	Point(ld=0, ld=0);
	Point operator-(const Point &) const;
	ld len() const;
};

Point::Point(ld x, ld y): x(x), y(y) 
{}

Point Point::operator-(const Point &p) const {
	return Point(x - p.x, y - p.y);
}

ld Point::len() const {
	return sqrt(x*x + y*y);
}


int n, m, D;
vector <vector <int> > graph;
vector <int> edgeT;
vector <pair <int, int> > edges;
vector <int> dist;
const int INF = (int)(1e9);

bool Cmpt(int a, int t1) {
	return edgeT[a] < t1;
}

bool Cmpt2(int t1, int b) {
	return t1 < edgeT[b];
}


int findPath(int s, int t) {
	dist.assign(2 * m, INF);
	queue<int> q;
	for (int i = 0; i < (int)graph[s].size(); ++i) {
		dist[graph[s][i]] = 0;
		q.push(graph[s][i]);
	}
	int ans = INF;
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		int v = edges[cur].second;
		if (v == t)
			return dist[cur] + 1;
		int t = edgeT[cur];
		vector<int>::iterator it1 = lower_bound(graph[v].begin(), graph[v].end(), t - D, Cmpt);
		vector<int>::iterator it2 = upper_bound(graph[v].begin(), graph[v].end(), t + D, Cmpt2);
		for (vector<int>::iterator it = it1; it != it2; ++it) {
			int e = *it;
			if (abs(edgeT[e] - t) <= D && dist[cur] + 1 < dist[e]) {
				dist[e] = dist[cur] + 1;
				q.push(e);
			}
		}
	}
	return (ans == INF ? -1 : ans);
}

int main() {
	//freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &D);
	graph.resize(n);
	edgeT.resize(2 * m);
	edges.resize(2 * m);
	for (int i = 0, u, v, t; i < m; ++i) {
		scanf("%d%d%d", &u, &v, &t);
		--u, --v;
		graph[u].pb(2 * i);
		graph[v].pb(2 * i + 1);
		edgeT[2 * i] = edgeT[2 * i + 1] = t;
		edges[2 * i] = mp(u, v);
		edges[2 * i + 1] = mp(v, u);
	}
	int Q;
	scanf("%d", &Q);
	for (int _i = 0; _i < Q; ++_i) {
		int A, B;
		scanf("%d%d", &A, &B);
		--A, --B;
		printf("%d\n", findPath(A, B));
	}
}