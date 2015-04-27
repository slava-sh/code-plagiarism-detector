#include <cstdio>
#include <queue>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;

int h, t, R;
int n, m;
pair<int, int> hh[300];
pair<int, int> tt[300];

void init()
{
	scanf("%d%d%d", &h, &t, &R);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d%d", &hh[i].first, &hh[i].second);
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) scanf("%d%d", &tt[i].first, &tt[i].second);
}

bool vis[300][300];
int vv[300][300], tim;
int dist[300][300];
pair<int, int> Q[50000];
vector<pair<int, int> > pre[300][300];
int AA, BB;
int ttt = 0;

bool dfs(int a, int b)
{
	vv[a][b] = tim;
	for (int i = 1; i <= min(n, a); i++) {
		ttt++;
		if (ttt > 30000000) return false;
		int nh = a - i + hh[i].first, nt = b + hh[i].second;
		if (nh + nt > R) {
		} else {
			if (nh == AA && nt == BB) return true;
			if (vv[nh][nt] == tim) continue;
			if (dfs(nh, nt)) return true;
		}
	}
	for (int i = 1; i <= min(m, b); i++) {
		ttt++;
		if (ttt > 30000000) return false;
		int nh = a + tt[i].first, nt = b - i + tt[i].second;
		if (nh + nt > R) {
		} else {
			if (nh == AA && nt == BB) return true;
			if (vv[nh][nt] == tim) continue;
			if (dfs(nh, nt)) return true;
		}
	}
	return false;
}

int ff[300][300];

void dp(int a, int b)
{
	vis[a][b] = true;
	for (int i = 0; i < pre[a][b].size(); i++) {
		int ph = pre[a][b][i].first, pt = pre[a][b][i].second;
		if (!vis[ph][pt]) dp(ph, pt);
		ff[a][b] = max(ff[a][b], ff[ph][pt] + 1);
	}
}

void work()
{
	int f = 0, l = 1;
	Q[1] = make_pair(h, t);
	vis[h][t] = true;
	while (f < l) {
		pair<int, int> u = Q[++f];
		for (int i = 1; i <= min(n, u.first); i++) {
			int nh = u.first - i + hh[i].first, nt = u.second + hh[i].second;
			//if (u.first == 2 && u.second == 2) printf("%d %d\n", nh, nt);
			if (nh + nt > R) {
				pre[R + 1][0].push_back(u);
			} else {
				if (!vis[nh][nt]) {
					vis[nh][nt] = true;
					Q[++l] = make_pair(nh, nt);
					dist[nh][nt] = dist[u.first][u.second] + 1;
				}
				pre[nh][nt].push_back(u);
			}
		}
		for (int i = 1; i <= min(m, u.second); i++) {
			int nh = u.first + tt[i].first, nt = u.second - i + tt[i].second;
			if (nh + nt > R) {
				pre[R + 1][0].push_back(u);
			} else {
				if (!vis[nh][nt]) {
					vis[nh][nt] = true;
					Q[++l] = make_pair(nh, nt);
					dist[nh][nt] = dist[u.first][u.second] + 1;
				}
				pre[nh][nt].push_back(u);
			}
		}
	}
	if (vis[0][0]) {
		printf("Ivan\n");
		printf("%d\n", dist[0][0]);
		return;
	}
	for (int i = 0; i <= R; i++) {
		for (int j = 0; j <= R; j++) {
			if (i + j <= R  && vis[i][j]) {
				tim++;
				AA = i;
				BB = j;
				if (dfs(i, j)) {
					printf("Draw\n");
					return;
				}
			}
		}
	}
	memset(vis, 0, sizeof(vis));
	dp(R + 1, 0);
	printf("Zmey\n");
	printf("%d\n", ff[R + 1][0]);
}

int main()
{
	//freopen("e.in", "r", stdin);
	init();
	work();
}