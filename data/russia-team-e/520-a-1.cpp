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

const int N = 1005;
const int Q = 1000000007;
int gr[N][N];
int cl[N];
int n;
bool us[N];

void Color(int u, int c = 0) {
	cl[u] = c;
	for (int v = 0; v < n; v++) {
		if (gr[u][v] == 0) {
			if (cl[v] == -1) {
				Color(v, c);
			} else if (cl[v] != c) {
				cout << "0\n";
				exit(0);
			}
		} else if (gr[u][v] == 1) {
			if (cl[v] == -1) {
				Color(v, c ^ 1);
			} else if (cl[v] == c) {
				cout << "0\n";
				exit(0);
			}
		}
	}
}

void DFS(int u) {
	us[u] = true;
	for (int v = 0; v < n; v++) {
		if (gr[u][v] != -1 && !us[v]) {
			DFS(v);
		}
	}
}

int main() {
#ifdef NAVI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("binary.in", "r", stdin);
	freopen("binary.out", "w", stdout);
#endif
	memset(cl, -1, sizeof(cl));
	memset(gr, -1, sizeof(gr));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (i == 0 && a > 0 || a > n - i) {
			cout << "0\n";
			return 0;
		}
		if (i == 0) {
			continue;
		}
		for (int j = 0; j < a; j++) {
			gr[j][i + j] = gr[i + j][j] = 0;
		}
		if (a != -1) {
			gr[a][i + a] = gr[i + a][a] = 1;
		}
	}
	//for (int i = 0; i < n; i++) {
	//	for (int j = 0; j < n; j++) {
	//		cout << gr[i][j] << " ";
	//	}
	//	cout << "\n";
	//}
	for (int i = 0; i < n; i++) {
		if (cl[i] == -1) {
			Color(i);
		}
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (!us[i]) {
			DFS(i);
			k++;
		}
	}
	int res = 1;
	for (int i = 0; i < k; i++) {
		res = (res * 2) % Q;
	}
	cout << res << "\n";
}