#include <bits/stdc++.h>

using namespace std;

const int INF = 0x3fffFFFF;

char g[1010][1010];
int s[1010][1010];

int get(int x0, int y0, int wx, int wy)
{
	int x1 = x0 + wx - 1;
	int y1 = y0 + wy - 1;
	return s[x1][y1] + s[x0 - 1][y0 - 1] - s[x1][y0 - 1] - s[x0 - 1][y1];
}

int check(int x, int y, int wx, int wy) {
	if (get(x + 1, y, wx, wy) == wx * wy) return wy + check(x + 1, y, wx, wy);
	if (get(x, y + 1, wx, wy) == wx * wy) return wx + check(x, y + 1, wx, wy);
	return 0;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", g[i] + 1);
	}
	int sx, sy, tag = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (g[i][j] == 'X') {
				if (!tag) tag = 1, sx = i, sy = j;
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + 1;
			}
			else {
				s[i][j] = s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1] + 0;
			}
		}
	}
	int x0, y0;
	for (y0 = sy; y0 <= m && g[sx][y0] == 'X'; y0++);
	for (x0 = sx; x0 <= n && g[x0][sy] == 'X'; x0++);
	int wx = x0 - sx, wy = y0 - sy;
	int ans = INF;
	for (int i = 1; i <= wx; i++) {
		if (check(sx, sy, i, wy) + i * wy == s[n][m]) {
			ans = min(ans, i * wy);
		}
	}
	for (int j = 1; j <= wy; j++) {
		if (check(sx, sy, wx, j) + wx * j == s[n][m]) {
			ans = min(ans, wx * j);
		}
	}
	if (ans == INF) ans = -1;
	cout << ans << '\n';
	return 0;
}
