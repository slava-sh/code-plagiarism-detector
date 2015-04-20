#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const long long INF = (long long)1e18;

vector <int> A;
vector <int> B;

struct tree {
	int sz;
	vector <int> data;
	tree (int isz = 750000): sz(isz) {
		data.resize(sz, 0);
	}
	void init(int v, int l, int r, vector <int> &V) {
		if (r - l == 1) {
			data[v] = V[l];
			return;
		}
		int m = (l + r) / 2;
		init(2 * v, l, m, V);
		init(2 * v + 1, m, r, V);
		data[v] = max(data[2 * v], data[2 * v + 1]);
	}
	int query(int v, int l, int r, int a, int b) { //max
		if (r <= a || l >= b) return -1e9;
		if (l >= a && r <= b) return data[v];
		if (r - l == 1) return data[v];
		int m = (l + r) / 2;
		return max(query(2 * v, l, m, a, b), query(2 * v + 1, m, r, a, b));
	}
};

struct vertex {
	int tp, pr;
	bool used;
	bool colored;
	long long d;
	vector <int> e;
	vertex () {
		tp = 0;
		d = INF;
		pr = -1;
		used = 0;
		colored = 0;
	}
};
vector <vertex> G;

void dfs(int v, int dist = 0) {
	G[v].used = 1;
	G[v].d = dist;
	int i, u;
	for (i = 0; i < G[v].e.size(); ++i) {
		u = G[v].e[i];
		if (!G[u].used) {
			dfs(u, dist + 1);
			G[u].pr = v;
		}
	}
}

void paintItBlack(int v) {
	G[v].colored = 1;
	if (G[v].d == 0) return;
	paintItBlack(G[v].pr);
}

int sizeT(int v, int pr = -1) {
	int ans = 0, i, u;
	for (i = 0; i < G[v].e.size(); ++i) {
		u = G[v].e[i];
		if (u != pr && !G[u].colored) ans = max(ans, 1 + sizeT(u, v));
	}
	return ans;
}

void fillVectors(int v, int end) {
	A[G[v].d] = B[G[end].d - G[v].d] = sizeT(v);
	A[G[v].d] += G[v].d;
	B[G[end].d - G[v].d] += G[end].d - G[v].d;
	if (G[v].d == 0) return;
	fillVectors(G[v].pr, end);
}

int main() {
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);

	int n;
	cin >> n;
	G.resize(n);
	int u, v, i;
	for (i = 0; i < n - 1; ++i) {
		cin >> u >> v;
		u--;
		v--;
		G[u].e.push_back(v);
		G[v].e.push_back(u);
	}
	cin >> u >> v;
	u--;
	v--;
	dfs(u);
	paintItBlack(v);
	tree tA;
	tree tB;
	A.resize(n);
	B.resize(n);
	fillVectors(v, v);
	tA.init(1, 0, G[v].d + 1, A);
	tB.init(1, 0, G[v].d + 1, B);
	int ans = 0;
	for (i = 1; i <= G[v].d; ++i) {
		ans = max(ans, min(tA.query(1, 0, G[v].d + 1, 0, i), tB.query(1, 0, G[v].d + 1, 0, G[v].d - i + 1)));
	}
	cout << ans + 1 << endl;
	return 0;
}