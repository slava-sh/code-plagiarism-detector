#include <iostream>
#include <vector>
#include <utility>
#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 1010;

int n, m;

char d[maxn][maxn];
int col[maxn][maxn];

vector<pair<int, int> > v;

int dfs(int x, int y, int px, int py) {
	int ct = 0;
	if (col[x][y] == col[x - 1][y] && (x - 1 != px || y != py)) {
		ct += dfs(x - 1, y, x, y);
	}
	if (col[x][y] == col[x + 1][y] && (x + 1 != px || y != py)) {
		ct += dfs(x + 1, y, x, y);
	}
	if (col[x][y] == col[x][y - 1] && (x != px || y - 1 != py)) {
		ct += dfs(x, y - 1, x, y);
	}
	if (col[x][y] == col[x][y + 1] && (x != px || y + 1 != py)) {
		ct += dfs(x, y + 1, x, y);
	}
	v.push_back(make_pair(x, y));
	return ct + 1;
}

inline bool check(int x, int y) {
	if (col[x][y] == -1) {
		return false;
	} else {
		v.clear();
		int color = col[x][y];
		int ct = dfs(x, y, -1, -1);
		if (ct < 5) {
			return true;
		} else {
			return false;
		}
	}
}

inline bool fnd(int x, int y) {
	pair<int, int> p = make_pair(x, y);
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == p) {
			return false;
		}
	}
	return true;
}

inline bool check2(int color) {
	for (int i = 0; i < v.size(); i++) {
		col[v[i].first][v[i].second] = color;		
	}
	for (int i = 0; i < v.size(); i++) {
		if ((col[v[i].first - 1][v[i].second] == col[v[i].first][v[i].second] && fnd(v[i].first - 1, v[i].second))
		 || (col[v[i].first + 1][v[i].second] == col[v[i].first][v[i].second] && fnd(v[i].first + 1, v[i].second))
		 ||	(col[v[i].first][v[i].second - 1] == col[v[i].first][v[i].second] && fnd(v[i].first, v[i].second - 1))
		 || (col[v[i].first][v[i].second + 1] == col[v[i].first][v[i].second] && fnd(v[i].first, v[i].second + 1))) {
		 	return false;
		 }
	}
	return true;
}

int main() {
	for (int i = 0; i < maxn; i++) {
		for (int j = 0; j < maxn; j++) {
			d[i][j] = '#';
			col[i][j] = -1;
		}
	}
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> d[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (d[i][j] != '#' && d[i - 1][j] == '#' && d[i + 1][j] == '#' && d[i][j - 1] == '#' && d[i][j + 1] == '#') {
				cout << -1 << endl;
				return 0;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (d[i][j] == '#') {
				col[i][j] = -1;
			} else {
				col[i][j] = -2;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (col[i][j] == -2) {
				if (col[i][j + 1] == -2 || col[i + 1][j] == -2) {
					int color = 0;
					if (col[i][j + 1] == -2) {
						while ((col[i - 1][j] == color || col[i - 1][j + 1] == color || col[i][j - 1] == color || col[i][j + 2] == color || col[i + 1][j] == color ||
							col[i + 1][j + 1] == color) && (color < 10)) color++;
						if (color == 10) {
							cout << -1 << endl;
							return 0;
						} else {
							col[i][j] = col[i][j + 1] = color;
						}
					} else {
						while ((col[i - 1][j] == color || col[i][j - 1] == color || col[i][j + 1] == color || col[i + 1][j - 1] == color || col[i + 1][j + 1] == color ||
							col[i + 2][j] == color) && (color < 10)) color++;
						if (color == 10) {
							cout << -1 << endl;
							return 0;
						} else {
							col[i][j] = col[i + 1][j] = color;
						}
					}
				}				
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (col[i][j] != -2) continue;
			if (check(i - 1, j)) {				
				v.push_back(make_pair(i, j));
				int color = 0;
				while (color < 10 && !check2(color)) {
					color++;
				}
				if (color == 10) {
					cout << -1 << endl;
					return 0;
				}
				continue;
			}
			if (check(i, j - 1)) {
				v.push_back(make_pair(i, j));
				int color = 0;
				while (color < 10 && !check2(color)) {
					color++;
				}
				if (color == 10) {
					cout << -1 << endl;
					return 0;
				}
				continue;
			}
			if (check(i, j + 1)) {
				v.push_back(make_pair(i, j));
				int color = 0;
				while (color < 10 && !check2(color)) {
					color++;
				}
				if (color == 10) {
					cout << -1 << endl;
					return 0;
				}
				continue;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (col[i][j] == -1) {
				printf("#");
			} else {
				printf("%c", (char)(col[i][j] + '0'));
			}
		}
		printf("\n");
	}
}