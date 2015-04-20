#pragma comment(linker, "/STACK:0x04000000")
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <vector>

using namespace std;

const int N = 5005;
const int INF = 2000000000;
int gr[N][N];
int t[N];
int d[N];
bool us[N];
int par[N];

int main() {
#ifdef NAVI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("secure.in", "r", stdin);
	freopen("secure.out", "w", stdout);
#endif
	int n;
	int m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t[i];
	}
	memset(gr, -1, sizeof(gr));
	memset(par, -1, sizeof(par));
	for (int i = 0; i < m; i++) {
		int a;
		int b;
		int c;
		cin >> a >> b >> c;
		a--;
		b--;
		gr[a][b] = gr[b][a] = c;
	}
	for (int i = 0; i < n; i++) {
		d[i] = t[i] == 1 ? 0 : INF;
	}
	while (true) {
		int p = -1;
		for (int i = 0; i < n; i++) {
			if (!us[i] && (p == -1 || d[p] > d[i])) {
				p = i;
			}
		}
		if (p == -1 || d[p] == INF) {
			break;
		}
		for (int i = 0; i < n; i++) {
			if (gr[p][i] != -1 && d[p] + gr[p][i] < d[i]) {
				d[i] = d[p] + gr[p][i];
				par[i] = p;
			}
		}
		us[p] = true;
	}
	int u = -1;
	for (int i = 0; i < n; i++) {
		if (t[i] == 2 && d[i] != INF && (u == -1 || d[u] > d[i])) {
			u = i;
		}
	}
	if (u == -1) {
		cout << "-1\n";
	} else {
		int v = u;
		while (par[v] != -1) {
			v = par[v];
		}
		cout << v + 1 << " " << u + 1 << " " << d[u] << "\n";
	}
}