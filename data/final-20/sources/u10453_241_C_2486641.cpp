#include <iostream>
#include <cstdio>
#include <string.h>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;

const double eps = 1e-8;
const int maxn = 100 + 10;
struct node
{
	int op, a, b, v;
} c[maxn];
double hl, hr;
int n;
int ans = 0;
double deg, H, L;
bool mark[maxn];

int Solve(double deg, int op)
{
	memset(mark, 0, sizeof(mark));
	int tmp = 0;
	double x = 0.0, y = hl;
	bool bj;
	while (x < L) {
		if (op == 0) {
			x += y / deg;
			y = 0;
		} else {
			x += (H - y) / deg;
			y = H;
		}
		if (x >= L) break;
		bj = false;
		for (int i = 1; i <= n; i++)
			if (op == c[i].op && c[i].a <= x && x <= c[i].b) {
				// cout << c[i].v << " " ;
				if (mark[i]) return 0;
				mark[i] = true;
				tmp += c[i].v;
				bj = true;
			}
		if (!bj && x < L) return 0;
		op = 1 - op;
	}
	return tmp;
}

int main()
{
	H = 100.0, L = 100000.0;
	char ss[10];
	while (scanf("%lf%lf%d", &hl, &hr, &n)!=EOF) {
		for (int i = 1; i <= n; i++) {
			scanf("%d%s%d%d", &c[i].v, ss, &c[i].a, &c[i].b);
			if (ss[0] == 'T') c[i].op = 1;
			else c[i].op = 0;
		}
		ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i & 1) {
				deg = (H * (i - 1) + hl + hr) / L;
			} else {
				deg = (H * (i - 1) + hl + H - hr) / L;
			}
			// if (i == 1) cout << i << " " << deg << endl;
			ans = max(ans, Solve(deg, 0));
			// cout << endl;
		}	
		
		for (int i = 1; i <= n; i++) {
			if (i & 1) {
				deg = (H * (i - 1) + H - hl + H - hr) / L;
			} else {
				deg = (H * (i - 1) + H - hl + hr) / L;
			}
			ans = max(ans, Solve(deg, 1));
			// cout << endl;
		}			
		
		printf("%d\n", ans);
	}	
	return 0;
}