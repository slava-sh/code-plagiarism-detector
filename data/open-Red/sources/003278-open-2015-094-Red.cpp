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
char mem[100000000];
int ptr = 0;
void *ptt;
void *operator new(const size_t x) {
	ptt = mem + ptr;
	ptr += x;
	return ptt;
}

void operator delete(void *p) {
}

int u[400100], v[400100], t[400100];
int d[400100];
int q[400300];
int qs, qc;

int n, m, D;
set<pii> vv[100000];
int solve(int f, int to) {
	for (int i = 0; i < 2 * m; ++i)
		d[i] = -1;
	for (int i = 0; i < n; ++i)
		vv[i].clear();
	qs = 0;
	qc = 0;
	for (int i = 0; i < 2 * m; ++i)
		vv[u[i]].insert(pii(t[i], i));
	for (auto i = vv[f].begin(); i != vv[f].end(); ++i) {
		d[i->second] = 1;
		q[qs++] = i->second;
	}
	vv[f].clear();
	int c;
	int cv;
	while (qc != qs) {
		c = q[qc++];
		cv = v[c];
		set<pii>::iterator it;
		while ((it = vv[cv].lower_bound(mp(t[c] - D, 0))) != vv[cv].end()) {
			if (it->first > t[c] + D) break;
			d[it->second] = d[c] + 1;
			q[qs++] = it->second;
			vv[cv].erase(it);
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
		u[2 * i] = t1;
		v[2 * i] = t2;
		t[2 * i] = t3;
		u[2 * i + 1] = t2;
		v[2 * i + 1] = t1;
		t[2 * i + 1] = t3;
	}
	int Q;
	scanf("%d", &Q);
	while (Q-->0) {
		scanf("%d%d", &t1, &t2);
		t1--, t2--;
		printf("%d\n", solve(t1, t2));
	}
}