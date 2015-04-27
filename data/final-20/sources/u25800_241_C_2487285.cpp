#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#define clear(a, b)	memset(a, b, sizeof a)
using namespace std;

const int N = 1000;

int h1[N], h2[N];
int ans, earn, n, m, tpe;
double tan, x;

struct ND {
	int v, a, b;
	char c[2];
}s1[N], s2[N];

int cmp(ND a, ND b) {
	return a.a < b.a;
}

void calc(int k) {
	clear(h1, 0);
	clear(h2, 0);
	earn = 0;
	int tt = 1, ff = 1;
	for (int j = 1; j <= k; j++) {
		if (!tpe) {
			for (tt = 1; tt <= n; tt++)
				if (s1[tt].a <= x && s1[tt].b >= x)
					break;
			if (tt <= n && !h1[tt]) {
				h1[tt] = true;
				earn += s1[tt].v;
			}
			else {
				earn = -1;
				break;	
			}
		}
		else {
			for (ff = 1; ff <= m; ff++)
				if (s2[ff].a <= x && s2[ff].b >= x)
					break;
			if (ff <= m && !h2[ff]) {
				h2[ff] = true;
				earn += s2[ff].v;	
			}	
			else {
				earn = -1;	
				break;	
			}
		}
		x += 100 * tan;
		tpe ^= 1;
	}
	if (earn > ans)
		ans = earn;
}

int main() {
	int hl, hr;
	scanf("%d%d%d", &hl, &hr, &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d%s%d%d", &s1[i].v, s1[i].c, &s1[i].a, &s1[i].b);
		if (s1[i].c[0] == 'F') {
			s2[++m] = s1[i];
			i--;
			n--;
		}
	}
	if (n > 0)
		sort(s1 + 1, s1 + n, cmp);
	if (m > 0)
		sort(s2 + 1, s2 + m, cmp);
	ans = 0;
	for (int k = 1; k <= n + m; k++) {
		if (k & 1)
			tan = 100000.0 / (hl + hr + 100.0 * (k - 1));
		else tan = 100000.0 / (hl + (100 - hr) + 100.0 * (k - 1));
		x = hl * tan;
		tpe = 1;
		calc(k);
	}
	for (int k = 1; k <= n + m; k++) {
		if (k & 1)
			tan = 100000.0 / ((100 - hl) + (100 - hr) + 100.0 * (k - 1));
		else tan = 100000.0 / ((100 - hl) + hr + 100.0 * (k - 1));
		x = (100 - hl) * tan;
		tpe = 0;
		calc(k);
	}
	printf("%d\n", ans);
	return 0;
}
