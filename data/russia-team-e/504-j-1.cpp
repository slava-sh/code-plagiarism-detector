#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>

using namespace std;

char c[510][510];
int dist[510][510];
int h[510][510];
int dx[4] = {
	-1, 0, 1, 0
};
int dy[4] = {
	0, 1, 0, -1
};
char f[4] = {
	'N', 'E', 'S', 'W'
};

void go(int x, int y, int x1, int y1) {
	if (!(x == x1 && y == y1)) {
		int dir = (h[x1][y1] + 2) % 4;
		go(x, y, x1 + dx[dir], y1 + dy[dir]);
		printf("%c", f[h[x1][y1]]);
	}
}

int main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	int n, m;
	int t;
	scanf("%d %d %d", &m, &n, &t);
	int x, y;
	for (int i = 0; i < n; i++) {
		scanf("\n");
		for (int j = 0; j < m; j++) {
			scanf("%c", &c[i][j]);
			if (c[i][j] == 'V') {
				x = i;
				y = j;
				c[i][j] = 'A';
			}
		}
	}
	queue <pair <int, int> > q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			dist[i][j] = -1;
			h[i][j] = -1;
		}
	}
	dist[x][y] = 0;
	h[x][y] = -2;
	q.push(make_pair(x, y));
	while (!q.empty()) {
		int i = q.front().first, j = q.front().second;
		q.pop();
		for (int i1 = 0; i1 < 4; i1++) {
			int nx = i + dx[i1];
			int ny = j + dy[i1];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && dist[nx][ny] == -1) {
				dist[nx][ny] = dist[i][j] + 1;
				h[nx][ny] = i1;
				q.push(make_pair(nx, ny));
			}
		}
	}
	t--;
	int x1, y1;
	int res = 1000000000;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (c[i][j] == 'T') {
				bool yes = false;
				for (int p = 0; p < 4; p++) {
					int nx = i + dx[p];
					int ny = j + dy[p];
					if (0 <= nx && nx < n && 0 <= ny && ny < m && c[nx][ny] == 'T') {
						yes = true;
					}
				}
				if (yes) {
					if (res > dist[i][j] + t) {
						res = dist[i][j] + t;
						x1 = i;
						y1 = j;
					}
				} else {
					if (res > dist[i][j] + 2 * t) {
						res = dist[i][j] + 2 * t;
						x1 = i;
						y1 = j;
					}
				}
			}
		}
	}
	go(x, y, x1, y1);
	while (t != 0) {
		bool yes = false;
		for (int p = 0; p < 4; p++) {
			int nx = x1 + dx[p];
			int ny = y1 + dy[p];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && c[nx][ny] == 'T') {
				yes = true;
			}
		}
		if (yes) {
			for (int p = 0; p < 4; p++) {
				int nx = x1 + dx[p];
				int ny = y1 + dy[p];
				if (0 <= nx && nx < n && 0 <= ny && ny < m && c[nx][ny] == 'T') {
					printf("%c", f[p]);
					x1 = nx;
					y1 = ny;
					break;
				}
			}
		} else {
			for (int p = 0; p < 4; p++) {
				int nx = x1 + dx[p];
				int ny = y1 + dy[p];
				if (0 <= nx && nx < n && 0 <= ny && ny < m) {
					printf("%c%c", f[p], f[(p + 2) % 4]);
					break;
				}
			}
		}
		t--;
	}
	return 0;
}
