#include <cstdio>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <iostream>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <list>
#include <bitset>
#include <cstring>
#include <string>
// C++11 Headers
#include <tuple>
#include <initializer_list>
// *C++11 Headers

#ifdef DEBUG
	#define debug printf
	#define reader scanf
#else
	#define debug ;
	#define reader ;
#endif

using namespace std;

const int MAXN = 1e6;
const int INF = 2e9;

int n, m, d;
vector< pair<int, int> > g[MAXN];
map<int, int> dist[MAXN];
queue< pair<int, int> > q;

int bfs(int s, int f) {
	while (!q.empty()) {
		q.pop();
	}
	for (int i = 0; i < n; i++) {
		dist[i].clear();
	}
	for (auto i : g[s]) {
		q.push(i);
		dist[i.first][i.second] = 1;
	}
	while (!q.empty()) {
		auto u = q.front();
		q.pop();
		if (u.first == f) {
			return dist[u.first][u.second];
		}
		for (auto i : g[u.first]) {
			if (abs(i.second - u.second) <= d) {
				if (!dist[i.first].count(i.second)) {
					dist[i.first][i.second] = dist[u.first][u.second] + 1;
					q.push(i);
				}
			}
		}
	}
	return -1;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> m >> d;
	for (int i = 0; i < m; i++) {
		int b, e, w;
		cin >> b >> e >> w;
		b--, e--;
		g[b].push_back(make_pair(e, w));
		g[e].push_back(make_pair(b, w));
	}
		
	int Q;
	cin >> Q;
	for (int p = 0; p < Q; p++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		cout << bfs(a, b) << '\n';
	} 
		
	return 0;
}
