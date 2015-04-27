#include <algorithm>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <utility>
#include <vector>
using namespace std;

const int MAXN = 1010;
const int MAXM = 1000010;
const int MAXL = 10;

int n, m, idx[MAXN][MAXN], idx0;
bool tag[MAXL];
char mat[MAXN][MAXN];
vector < pair <int, int> > v[MAXM];

bool isValid(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void cover(int o) {
	for (vector < pair <int, int> >::const_iterator it = v[o].begin(); it != v[o].end(); it++) {
		int x = it->first, y = it->second;
		if (isValid(x - 1, y) && isdigit(mat[x - 1][y])) {
			tag[mat[x - 1][y] - '0'] = true;
		}
		if (isValid(x + 1, y) && isdigit(mat[x + 1][y])) {
			tag[mat[x + 1][y] - '0'] = true;
		}
		if (isValid(x, y - 1) && isdigit(mat[x][y - 1])) {
			tag[mat[x][y - 1] - '0'] = true;
		}
		if (isValid(x, y + 1) && isdigit(mat[x][y + 1])) {
			tag[mat[x][y + 1] - '0'] = true;
		}
	}
}

bool isValid() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '#' || idx[i][j] != -1) {
				continue;
			}
			if (isValid(i, j + 1) && mat[i][j + 1] == '.' && idx[i][j + 1] == -1) {
//printf("0 %d %d\n", i, j);
				v[idx0].push_back(make_pair(i, j));
				v[idx0].push_back(make_pair(i, j + 1));
				idx[i][j] = idx0;
				idx[i][j + 1] = idx0;
				idx0++;
			} else if (isValid(i + 1, j) && mat[i + 1][j] == '.' && idx[i + 1][j] == -1) {
//printf("1 %d %d\n", i, j);
				v[idx0].push_back(make_pair(i, j));
				v[idx0].push_back(make_pair(i + 1, j));
				idx[i][j] = idx0;
				idx[i + 1][j] = idx0;
				idx0++;
			} else if (isValid(i, j - 1) && mat[i][j - 1] == '.' && v[idx[i][j - 1]].size() < 5U) {
//printf("2 %d %d\n", i, j);
				v[idx[i][j - 1]].push_back(make_pair(i, j));
				idx[i][j] = idx[i][j - 1];
			} else if (isValid(i - 1, j) && mat[i - 1][j] == '.' && v[idx[i - 1][j]].size() < 5U) {
//printf("3 %d %d\n", i, j);
				v[idx[i - 1][j]].push_back(make_pair(i, j));
				idx[i][j] = idx[i - 1][j];
			} else if (isValid(i, j + 1) && mat[i][j + 1] == '.' && v[idx[i][j + 1]].size() < 5U) {
//printf("4 %d %d\n", i, j);
				v[idx[i][j + 1]].push_back(make_pair(i, j));
				idx[i][j] = idx[i][j + 1];
			} else if (isValid(i + 1, j) && mat[i + 1][j] == '.' && v[idx[i + 1][j]].size() < 5U) {
//printf("5 %d %d\n", i, j);
				v[idx[i + 1][j]].push_back(make_pair(i, j));
				idx[i][j] = idx[i + 1][j];
			} else {
				return false;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (mat[i][j] == '.') {
				fill(tag, tag + MAXL, false);
				int o = idx[i][j];
				cover(o);
				int color;
				for (color = 0; tag[color]; color++) ;
				for (vector < pair <int, int> >::const_iterator it = v[o].begin(); it != v[o].end(); it++) {
					int x = it->first, y = it->second;
					mat[x][y] = color + '0';
				}
			}
		}
	}
	return true;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", mat[i]);
		fill(idx[i], idx[i] + m, -1);
	}
	if (isValid()) {
		for (int i = 0; i < n; i++) {
			puts(mat[i]);
		}
	} else {
		puts("-1");
	}
	return 0;
}
