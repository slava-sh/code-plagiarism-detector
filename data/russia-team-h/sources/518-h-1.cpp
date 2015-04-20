#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const long long INF = (long long)1e18;

struct edge {
	int v;
	long long c;
	edge (int iv = -1, long long ic = -1): v(iv), c(ic) {}
};

struct vertex {
	int tp, pr;
	bool used;
	long long d;
	vector <edge> e;
	vertex () {
		tp = 0;
		d = INF;
		pr = -1;
		used = 0;
	}
};
vector <vertex> G;

void calcDist() {
	int i, j, k, v, c;
	for (i = 0; i < G.size(); ++i) {
		k = G.size() - 1;
		for (j = 0; j < G.size() - 1; ++j) {
			if (!G[j].used && (G[k].used || G[j].d < G[k].d)) k = j;
		}
		for (j = 0; j < G[k].e.size(); ++j) {
			v = G[k].e[j].v;
			c = G[k].e[j].c;
			if (G[v].d > G[k].d + c) {
				G[v].pr = k;
				G[v].d = G[k].d + c;
			}
		}
		G[k].used = 1;
	}
}

int main() {
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);

	int n, m;
	cin >> n >> m;
	G.resize(n + 2);
	int i, s, t, c;
	for (i = 0; i < n; ++i) scanf("%d", &G[i].tp);
	for (i = 0; i < m; ++i) {
		scanf("%d %d %d", &s, &t, &c);
		s--;
		t--;
		G[s].e.push_back(edge(t, c));
		G[t].e.push_back(edge(s, c));
	}

	// G[n] - to 1
	// G[n + 1] - to 2
	G[n].d = 0;
	for (i = 0; i < n; ++i) {
		if (G[i].tp == 1) G[n].e.push_back(edge(i, 0));
		if (G[i].tp == 2) G[i].e.push_back(edge(n + 1, 0));
	}
	calcDist();

	if (G[n + 1].d >= INF) {
		cout << -1 << endl;
		return 0;
	}

	int cur = n + 1;
	while (G[cur].pr != n) cur = G[cur].pr;
	printf("%d %d %lld", cur + 1, G[n + 1].pr + 1, G[n + 1].d);
	return 0;
}