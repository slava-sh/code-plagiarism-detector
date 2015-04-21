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

using namespace std;

typedef long long ll;
typedef long double ld;

const int MAXN = 120000;

vector<pair<int, int> > eds[MAXN];
vector<int> tt[MAXN];
vector<int> bck[MAXN];
vector<int> nx[MAXN];
vector<int> pr[MAXN];
vector<int> gg[MAXN];
int d;

int n, m;
queue<pair<int, int> > qu;


void init() {
	for (int i = 0; i < n; ++i) {
		int k = eds[i].size();
		tt[i].resize(k);
		nx[i].resize(k);
		pr[i].resize(k);
		gg[i].resize(k);
		for (int j = 0; j < (int)eds[i].size(); ++j) {
			tt[i][j] = 1000000;
			nx[i][j] = j + 1;
			pr[i][j] = j - 1;
			gg[i][j] = 0;
		}
	}
}


void upd(int x, int y, int dd) {
	gg[x][y] = 1;
	int gx = eds[x][y].first;
	int gy = bck[x][y];
	//cout << gx << " " << gy << "\n";
	if (tt[gx][gy] == 1000000) {
		tt[gx][gy] = dd + 1;
		qu.push({gx, gy});
	}
}


int getnx(int x, int y) {
	if (y == (int)eds[x].size())
		return y;
	if (!gg[x][y])
		return y;
	return nx[x][y] = getnx(x, nx[x][y]);
}

int getpr(int x, int y) {
	if (y == -1)
		return y;
	if (!gg[x][y])
		return y;
	return pr[x][y] = getpr(x, pr[x][y]);
}

int main() {
	freopen("input.txt", "r", stdin);
	scanf("%d%d%d", &n, &m, &d);
	for (int i = 0; i < m; ++i) {
		int a, b, t;
		scanf("%d%d%d", &a, &b, &t);
		--a;
		--b;
		eds[a].push_back({b, t});
		eds[b].push_back({a, t});
		bck[a].push_back(eds[b].size() - 1);
		bck[b].push_back(eds[a].size() - 1);
	}


	int q;
	scanf("%d", &q);

	for (int qq = 0; qq < q; ++qq) {
		int a, b;
		scanf("%d%d", &a, &b);
		--a;
		--b;
		init();
		for (int i = 0; i < (int)eds[a].size(); ++i) {
			tt[a][i] = 0;
			qu.push({a, i});
		}
		while (!qu.empty()) {
			int x = qu.front().first;
			int y = qu.front().second;
			qu.pop();
			if (!gg[x][y])
				upd(x, y, tt[x][y]);
			while (true) {
				int bb = getnx(x, y);
				if (bb == (int)eds[x].size() || eds[x][bb].second > eds[x][y].second + d)
					break;
				upd(x, bb, tt[x][y]);
			}
			while (true) {
				int bb = getpr(x, y);
				if (bb == -1 || eds[x][bb].second < eds[x][y].second - d)
					break;
				upd(x, bb, tt[x][y]);
			}
		}
		int ans = 1000000;
		for (int i = 0; i < (int)eds[b].size(); ++i)
			if (tt[b][i] < ans)
				ans = tt[b][i];
		if (ans == 1000000)
			printf("-1\n");
		else
			printf("%d\n", ans);
	}

	return 0;
}

