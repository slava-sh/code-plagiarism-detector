#include <cstdio>
using namespace std;

const int inf = 1e9;

struct rib {
	int x, y;
	/* were lld */ int w;
};

const int vertexes_count = 5100;

int a[vertexes_count], num[vertexes_count];
rib r[100100];
/* were lld */ int d[vertexes_count];

#define FILENAME "secure"
int main() {
	freopen(FILENAME ".in", "r", stdin);
	freopen(FILENAME ".out", "w", stdout);

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &r[i].x, &r[i].y, &r[i].w);
		r[i].x--;
		r[i].y--;
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == 1) {
			d[i] = 0;
			num[i] = i;
		} else
			d[i] = inf;
	}
	int par, ch;
	for (int i = 0; i < n + 1; i++) {
		for (int j = 0; j < m; j++) {
			par = r[j].x;
			ch = r[j].y;
			if (d[par] > d[ch]) {
				int tmp = par;
				par = ch;
				ch = tmp;
			}
			if (d[par] + r[j].w < d[ch]) {
				d[ch] = d[par] + r[j].w;
				num[ch] = num[par];
			}
		}
	}
	/* were lld */ int weight = inf, cur;
	for (int i = 0; i < n; i++) {
		if (a[i] == 2 && d[i] != inf && d[i] < weight) {
			weight = d[i];
			cur = i;
		}
	}
	if (weight < inf)
		printf("%d %d %d\n", num[cur] + 1, cur + 1, weight);
	else
		printf("-1\n");
	return 0;
}