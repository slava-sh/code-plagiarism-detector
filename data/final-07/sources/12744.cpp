#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <algorithm>

#define REP(i,n) for(int i=0; i<n; i++)
#define REPD(i,n) for(int i=(n-1); i>=0; i--)
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define FORD(i, a,b) for(int i=a; i>=b; i--)
#define FILL(a, v) memset(&a, v, sizeof(a))
#define DB(x) cout << #x << " : " << x << endl
#define pb push_back
#define mp make_pair
#define sz(x) (x).size()
#define x first
#define y second

using namespace std;

typedef long long LL;
typedef pair<int, int> pii;

const int maxn = 10009;
const int maxm = 100;
const int maxk = 200009;

int n, k; pii pnt[maxn], ans[maxk];
void solve(int l, int r) {
	if (l > r) return;
	if (l == r) {
		ans[k++] = pnt[l];
		return;
	}
	int m = (l + r) / 2;
	FOR(i, l, r) {
		ans[k++] = mp(pnt[m].x, pnt[i].y);
	}
	solve(l, m);
	solve(m+1, r);
}

void gen() {
	n = 40;
	printf("%d\n", n);
	REP(i, n)
	{
		int x = abs(rand()*rand())%10000000;
		int y = abs(rand()*rand())%10000000;
		printf("%d %d\n", x, y);
	}
}
bool check() {
	REP(i, k)
	{
		REP(j, i)
		{
			if (ans[i].x == ans[j].x || ans[i].y == ans[j].y) continue;
			bool flag = 0;
			int x1, y1, x2, y2;
			x1 = min(ans[i].x, ans[j].x);
			x2 = max(ans[i].x, ans[j].x);
			y1 = min(ans[i].y, ans[j].y);
			y2 = max(ans[i].y, ans[j].y);
			REP(r, k)
			{
				if (r == i || r == j) continue;
				if (x1 <= ans[r].x && ans[r].x <= x2
					&& y1 <= ans[r].y && ans[r].y <= y2)
					{
						flag = 1;
						r = k+1;
					}
			}
			if (flag == 0) { DB(x1); DB(x2); DB(y1); DB(y2); DB(i); DB(j); return 0; }
		}
	}
	return 1;
}

pii ans1[maxk]; int kk;

int main()
{
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
	//srand(time(NULL));
	//gen(); return 0;
	scanf("%d", &n);
	REP(i, n)
		scanf("%d%d", &pnt[i].x, &pnt[i].y);
	sort(pnt, pnt + n);
	solve(0, n-1);
	//if (check()) printf("OK\n"); else printf("NO\n");
	sort(ans, ans + k);
	REP(i, k)
	{
		if (i == k-1 || ans[i] != ans[i+1])
			ans1[kk++] = ans[i];
	}
	printf("%d\n", kk);
	REP(i, kk)
		printf("%d %d\n", ans1[i].x, ans1[i].y);
	return 0;
}
