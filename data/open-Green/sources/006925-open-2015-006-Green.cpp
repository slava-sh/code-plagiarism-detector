#pragma comment(linker, "/STACK:1000000000")

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <cstring>
#include <string>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>

using namespace std;

const int maxn = (int)1e5 + 10;
const long long  pq = (int)1e9 + 7;

vector <pair <int, int> > ed[maxn];
unordered_map <int, int> dst[maxn];
unordered_set <long long> edge[maxn];

int main() {
	int n, m, d;

	scanf("%d %d %d", &n, &m, &d);

	for (int i = 0; i < m; i++) {
		int x, y, w;

		scanf("%d %d %d", &x, &y, &w);

		ed[x].push_back(make_pair(y, w));
		ed[y].push_back(make_pair(x, w));
	}

	int cnt;

	scanf("%d", &cnt);
	
	while (cnt != 0) {
		cnt--;

		int a, b;

		scanf("%d %d", &a, &b);

		for (int i = 1; i <= n; i++) {
			edge[i].clear();
			dst[i].clear();
			for (int j = 0; j < (int)ed[i].size(); j++) {
				edge[i].insert(pq * ed[i][j].second + ed[i][j].first);
			}
		}

		queue <pair <int, int> > q;

		for (int i = 0; i < (int)ed[a].size(); i++) {
			int u = ed[a][i].first;
			int t = ed[a][i].second;

			dst[u][t] = 1;
			q.push(make_pair(u, t));
		}

		edge[a].clear();

		bool st = false;

		while (!q.empty()) {
			int v = q.front().first;
			int t = q.front().second;
			q.pop();
			if (v == b) {
				printf("%d\n", dst[v][t]);
				st = true;
				break;
			}

			unordered_set <long long>::iterator it = edge[v].lower_bound((t - d) * pq);
			vector <long long> del;

			while (it != edge[v].end()) {
				int u = (*it) % pq;
				int tm = (*it) / pq;
				if (tm > t + d) {
					break;
				}
				del.push_back((*it));

				if (abs(t - tm) > d) {
					throw 1;
				}

				if (!dst[u].count(tm)) {
					dst[u][tm] = dst[v][t] + 1;
					q.push(make_pair(u, tm));
				}
				it++;
			}

			for (int i = 0; i < (int)del.size(); i++) {
				edge[v].erase(del[i]);
			}
		}

		if (!st) {
			printf("-1\n");
		}
	}
	
	return 0;
}
