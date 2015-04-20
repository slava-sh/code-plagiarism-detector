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

const int maxn = 200005;

vector <int> e[maxn];
int n, u0, v0;
bool reddy[maxn];
int d[maxn];
int hei[maxn];
int len[maxn];
vector <int> red;

void dfs(int u, int h = 0, int p = -1) {
	if (v0 == u) {
		reddy[u] = 1;
		red.push_back(u);
	}
	hei[u] = h;
	for (int i = 0; i < e[u].size(); i++) {
		int nu = e[u][i];
		if (p == nu)
			continue;
		dfs(nu, h + 1, u);
		if (reddy[nu]) {
			reddy[u] = 1;
			red.push_back(u);
		}
		if (!reddy[nu])
			len[u] = max(len[u], len[nu] + 1);
	}
}
int cou(int u) {
	int maxi = 0;
	for (int i = 0; i < e[u].size(); i++){
		int nu = e[u][i];
		if (!reddy[nu])
			maxi = max(maxi, len[nu] + 1);
	}
	return maxi;
}
int main() {
#ifdef NAVI
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
#endif
	cin >> n;
	for (int i = 0; i < n - 1; i ++) {
		int l, r;
		cin >> l >> r;
		e[l - 1].push_back(r - 1);
		e[r - 1].push_back(l - 1);
	}
	cin >> u0 >> v0;
	u0 --;
	v0--;
	dfs(u0);
	reverse(red.begin(), red.end());
	d[0] = cou(u0);
	for (int i = 1; i < red.size(); i++) {
		d[i] = max(d[i - 1], (cou(red[i]) + i)); 
	}
	int answer = -9999999;
	for (int i = red.size() - 1; i > 0; i--) {
		answer = max(min(d[i - 1], len[red[i]] + ((int)red.size() - i - 1)), answer);
	}
	cout << answer + 1;
}