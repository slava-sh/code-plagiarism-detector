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

struct point {
	ll x, y;
	ll operator*(point a) {
		return x * a.y - y * a.x;
	}
	point operator-(point a) {
		return {x - a.x, y - a.y};
	}
};

const int MAXN = 120000;

ll a, b;
int n;
int len[MAXN];
vector<point> vv[MAXN];
int now[MAXN];
int al[MAXN];
int pl[MAXN];
vector<pair<ll, int> > ev;
ll ss[MAXN];

bool cmp(int a, int b) {
	return ss[a] < ss[b];
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%lld%lld", &a, &b);
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &len[i]);
		++len[i];
		ss[i] = 0;
		for (int j = 0; j < len[i]; ++j) {
			point a;
			scanf("%lld%lld", &a.x, &a.y);
			vv[i].push_back(a);
			if (j != 0) {
				if (j != len[i] - 1)
					ev.push_back({a.x, i});
				ss[i] += (vv[i][j].x - vv[i][j - 1].x) * (vv[i][j].y + vv[i][j - 1].y);
			}
		}
		now[i] = 0;
	}
	sort(ev.begin(), ev.end());
	for (int i = 0; i < n; ++i)
		pl[i] = i;
	sort(pl, pl + n, cmp);
	for (int i = 0; i < n; ++i)
		al[pl[i]] = i;
	for (int i = 0; i < n - 1; ++i) {
		if (vv[pl[i]][0].y > vv[pl[i + 1]][0].y) {
			cout << "No\n";
			cout << pl[i] + 1 << " " << pl[i + 1] + 1;
			return 0;
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		if (vv[pl[i]][len[pl[i]] - 1].y > vv[pl[i + 1]][len[pl[i + 1]] - 1].y) {
			cout << "No\n";
			cout << pl[i] + 1 << " " << pl[i + 1] + 1;
			return 0;
		}
	}


	for (int i = 0; i < (int)ev.size(); ++i) {
		int x = ev[i].second;
		int x2 = al[x];
		++now[x];
		if (x2 != 0) {
			int pr = pl[x2 - 1];
			if ((vv[pr][now[pr] + 1] - vv[pr][now[pr]]) * (vv[x][now[x]] - vv[pr][now[pr]]) < 0) {
				cout << "No\n";
				cout << x + 1 << " " << pr + 1;
				return 0;
			}
		}
		if (x2 != n - 1) {
			int pr = pl[x2 + 1];
			if ((vv[pr][now[pr] + 1] - vv[pr][now[pr]]) * (vv[x][now[x]] - vv[pr][now[pr]]) > 0) {
				cout << "No\n";
				cout << x + 1 << " " << pr + 1;
				return 0;
			}
		}
	}
	cout << "Yes\n";
	return 0;
}

