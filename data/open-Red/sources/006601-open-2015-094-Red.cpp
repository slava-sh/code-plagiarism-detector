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


int u[400100], v[400100], t[400100];
int d[400100];
int q[400300];
int qs, qc;
int ptr[400100];
vector<int> nxt[100100];
vector<int> vv[100100];
vector<bool> used(400100);
int n, m, D;

int get(int cv, int x) {
	if (x >= cs(nxt[cv])) return -1;
	if (x == -1) return -1;
	if (!used[vv[cv][x]]) return x;
	else
		return nxt[cv][x] = get(cv, nxt[cv][x]);
}

int solve(int f, int to) {
	for (int i = 0; i < 2 * m; ++i)
		d[i] = -1, used[i] = false;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < cs(nxt[i]) - 1; ++j)
			nxt[i][j] = j + 1;
		nxt[i][cs(nxt[i]) - 1] = -1;
	}
	qs = 0;
	qc = 0;
	for (int i = 0; i < cs(vv[f]); ++i) {
		d[vv[f][i]] = 1;
		nxt[f][i] = -1;
		used[vv[f][i]] = true;
		q[qs++] = vv[f][i];
	}
	int c;
	int cv;
	int cu;
	int hc;
	while (qc != qs) {
		c = q[qc++];
		cv = v[c];
		hc = c;
		if (hc % 2 ) hc--;
		else hc++;
		while (true) {
			cu = get(cv, ptr[hc]);
			if (cu == -1) break;
			while (t[c] - t[vv[cv][cu]] > D) {
				cerr << "BAD" << endl;
			}
			if (t[vv[cv][cu]] - t[c] > D) break;
			used[vv[cv][cu]] = true;
			q[qs++] = vv[cv][cu];
			d[vv[cv][cu]] = d[c] + 1;
		}
	}
	int ans = 1000000000;
	for (int i = 0; i < 2 * m; ++i)
		if ((v[i] == to) && (d[i] > 0))
			ans = min(ans, d[i]);
	if (ans == 1000000000)
		ans = -1;
	return ans;
}

int main(void) {
	scanf("%d%d%d", &n, &m, &D);
	int t1, t2, t3;
	for (int i = 0; i < m; ++i) {
		scanf("%d%d%d", &t1, &t2, &t3);
		--t1, --t2;
		vv[t1].pb(i * 2);
		nxt[t1].pb(0);
		u[2 * i] = t1;
		v[2 * i] = t2;
		t[2 * i] = t3;
		vv[t2].pb(i * 2 + 1);
		nxt[t2].pb(0);
		u[2 * i + 1] = t2;
		v[2 * i + 1] = t1;
		t[2 * i + 1] = t3;
	}
	int l, r, m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < cs(vv[i]); ++j) {
			l = 0;
			r = cs(vv[i]);
			if (t[vv[i][j]] - t[vv[i][0]] <= D) {
				ptr[vv[i][j]] = 0;
			} else {
				while (l + 1 < r) {
					m = (l + r) / 2;
					if (t[vv[i][j]] - t[vv[i][m]] > D) {
						l = m;
					} else {
						r = m;
					}
				}
				ptr[vv[i][j]] = r;
			}
		}
	}
	int Q;
	scanf("%d", &Q);
	while (Q-->0) {
		scanf("%d%d", &t1, &t2);
		t1--, t2--;
		printf("%d\n", solve(t1, t2));
	}
}