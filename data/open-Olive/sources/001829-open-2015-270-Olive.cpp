#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <cstring>
#include <cmath>
#include <cassert>
#include <cstdlib>
#include <queue>
#include <bitset>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 1200000;

int n;

int a[MAXN];
int gol[MAXN];
int gor[MAXN];
pair<int, int> rmq[MAXN * 4];
int dd[MAXN * 4];
int mx[MAXN];


void add(int v, int tl, int tr, int l, int r, int k) {
	if (r <= tl || tr <= l)
		return;
	if (l <= tl && tr <= r) {
		dd[v] += k;
		rmq[v].first += k;
		return;
	}
	int m = (tl + tr) >> 1;
	add(v * 2 + 1, tl, m, l, r, k);
	add(v * 2 + 2, m, tr, l, r, k);
	if (rmq[v * 2 + 1].first >= rmq[v * 2 + 2].first)
		rmq[v] = rmq[v * 2 + 1], rmq[v].first += dd[v];
	else
		rmq[v] = rmq[v * 2 + 2], rmq[v].first += dd[v];
}

pair<int, int> get(int v, int tl, int tr, int l, int r) {
	if (r <= tl || tr <= l)
		return {-MAXN * 2, l};
	if (l <= tl && tr <= r)
		return rmq[v];
	int m = (tl + tr) >> 1;
	pair<int, int> g1 = get(v * 2 + 1, tl, m, l, r);
	pair<int, int> g2 = get(v * 2 + 2, m, tr, l, r);
	if (g1.first >= g2.first) {
		g1.first += dd[v];
		return g1;
	}
	else {
		g2.first += dd[v];
		return g2;
	}
}

bool cmp(int x, int y) {
	return a[x] > a[y];
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]), --a[i];
	int bans = 0;
	int ansl = -2;
	int ansr = -2;
	mx[0] = a[0];
	for (int i = 1; i < n; ++i)
		mx[i] = max(mx[i - 1], a[i]);
	vector<int> st;
	int now = 0;
	int lst = n;
	for (int i = n - 1; i >= 0; --i) {
		if (mx[i] == a[i]) {
			for (int j = a[i] + 1; j < lst; ++j)
				add(0, 0, n, gol[j], gor[j], -1);
			lst = a[i];
			while (now < (int)st.size() && a[st[now]] > a[i])
				++now;
			pair<int, int> x = get(0, 0, n, now, st.size());
			if (x.first > bans)
				bans = x.first, ansl = i, ansr = st[x.second];
		}
		else {
			int l = lower_bound(st.begin(), st.end(), i, cmp) - st.begin();
			add(0, 0, n, l, st.size(), 1);
			gol[a[i]] = l;
			gor[a[i]] = st.size();
		}
		if (st.empty() || a[i] < a[st[st.size() - 1]])
			st.push_back(i);
	}

	cout << ansl + 1 << " " << ansr + 1;
	return 0;
}

