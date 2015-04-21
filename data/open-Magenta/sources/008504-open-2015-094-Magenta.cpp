#include<iostream>
#include<cstdlib>
#include<set>
#include<map>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<cstdio>
#include<string>
#include<cstring>
#include<time.h>
#include<queue>
#include<stack>
#define ll long long
#define ld long double
#define cs(a) ((int)a.size())
#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define BAD -1001230000
#define MOD 1000000007LL
#define P 5
using namespace std;

vector<int> a;
vector<int> tree;
int nn;
int nl, nr;

int get(int x, int l, int r) {
	if (l >= nr) return 0;
	if (r <= nl) return 0;
	if ((l >= nl) && (r <= nr)) return tree[x];
	return get(x * 2, l, (l + r) / 2) + get(x * 2 + 1, (l + r) / 2, r);
}

void add(int x) {
	x += nn;
	tree[x]++;
	for (x /= 2; x > 0; x /= 2) {
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
	}
}
int b[1000100];
int c[1000100];

bool cmp(int a, int b) {
	return c[a] > c[b];
}

int ansc, ansp1, ansp2;
void solve(int x) {
	for (int i = 0; i < cs(tree); ++i)
		tree[i] = 0;
	for (int i = 0; i < x; ++i)
		add(a[i]);
	for (int i = 0; i <= x; ++i) {
		nl = a[i] + 1;
		nr = nn;
		b[i] = get(1, 0, nn);
	}
	for (int i = 0; i < cs(tree); ++i)
		tree[i] = 0;
	int ansp = 0, ans = -10000;
	int t;
	for (int i = 0; i < x; ++i) {
		nl = a[x] + 1;
		nr = nn;
		t = c[x] - get(1, 0, nn) + c[i] - b[i];
		if (t > ans) {
			ans = t;
			ansp = i;
		}
		add(a[i]);
	}
	if (ans > ansc) {
		ansc = ans;
		ansp1 = x + 1;
		ansp2 = ansp + 1;
	}
}
int timec = 0;
int x[1000100];
int CLOCKS_PER = 0;
int sstime;
int main(void) {
	int n = 1000000;
	//scanf("%d", &n);
	a.resize(n);
	for (nn = 1; nn < n; nn *= 2);
	tree.resize(nn * 3);
	for (int i = 0; i < n; ++i)
		x[i] = i;
	for (int i = 0; i < n; ++i) {
		a[i] = n - i;
		//scanf("%d", &a[i]);
		a[i]--;
	}
	int badv = 0;
	int badp = 0;
	int t;
	
	for (int i = 0; i < n; ++i) {
		nl = a[i] + 1;
		nr = nn;
		t = get(1, 0, nn);
		c[i] = t;
		if (t >= badv) {
			badp = i;
			badv = t;
		}
		add(a[i]);
	}
	if (badv == 0) {
		printf("-1 -1\n");
		return 0;
	}
	sort(x, x + n, cmp);
	for (int i = 0; i < min(n, 2000000 / n); ++i) {
		solve(x[i]);
	}
	printf("%d %d\n", ansp1, ansp2);
	return 0;
}