#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

struct rib {
	int x, y;
	long long w;
};

const int vertexes_count = 5100;

int a[vertexes_count], num[vertexes_count];
rib r[100100];
long long d[vertexes_count];

#define FILENAME "secure"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%lld", &r[i].x, &r[i].y, &r[i].w);
		r[i].x--;
		r[i].y--;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			d[i] = 0;
			num[i] = i;
		} else
			d[i] = 1e18;
	}
	int par, ch;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			par = r[j].x;
			ch = r[j].y;
			if (d[par] > d[ch])
				swap(par, ch);
			if (d[par] + r[j].w < d[ch]) {
				d[ch] = d[par] + r[j].w;
				num[ch] = num[par];
			}
		}
	}
	long long weight = 1e18, cur;
	for (int i = 0; i < n; i++) {
		if (a[i] == 2 && d[i] != 1e18 && d[i] < weight) {
			weight = d[i];
			cur = i;
		}
	}
	if (weight < 1e18)
		cout << num[cur] + 1 << " " << cur + 1 << " " << weight << "\n";
	else
		cout << -1;
	return 0;
}