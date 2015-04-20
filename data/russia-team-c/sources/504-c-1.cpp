#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector <int> ed[200010];
bool state[200010];
int res[200010];
int dist = 0;

int a, b;

bool dfs(int v, int p) {
	if (v == b) {
		state[v] = true;
	} else {
		for (int i = 0; i < (int)ed[v].size(); i++) {
			if (ed[v][i] != p) {
				state[v] = max(state[v], dfs(ed[v][i], v));
			}
		}
	}
	if (state[v]) {
		dist++;
	}
	return state[v];
}

int went(int v, int p) {
	res[v] = 1;
	for (int i = 0; i < (int)ed[v].size(); i++) {
		if (!state[ed[v][i]] && ed[v][i] != p) {
			res[v] = max(res[v], 1 + went(ed[v][i], v));
		}
	}
	for (int i = 0; i < (int)ed[v].size(); i++) {
		if (state[ed[v][i]] && ed[v][i] != p) {
			went(ed[v][i], v);
		}
	}
	return res[v];
}

int main() {
	freopen("dwarfs.in", "r", stdin);
	freopen("dwarfs.out", "w", stdout);
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		ed[x].push_back(y);
		ed[y].push_back(x);
	}
	scanf("%d %d", &a, &b);
	dfs(a, -1);
	dist--;
	int ans_a;
	went(a, -1);
	ans_a = res[a];
	set <pair <int, int> > s;
	int t = -1;
	{
		int ds = dist;
		int v = a;
		int p = -1;
		while (v != b) {
			for (int i = 0; i < (int)ed[v].size(); i++) {
				if (ed[v][i] != p && state[ed[v][i]]) {
					p = v;
					v = ed[v][i];
					break;
				}
			}
			ds--;
			if (t == -1) {
				t = v;
			}
			s.insert(make_pair(ds + res[v], v));
		}
	}
	int v = t;
	int p = a;
	int ans = 0;
	int ds = 0;
	while (true) {
		set <pair <int, int> >::iterator it = s.end();
		it--;
		ans = max(ans, min(ans_a, (*it).first));
		if (v == b) {
			break;
		}
		ds++;
		ans_a = max(ans_a, res[v] + ds);
		s.erase(make_pair(res[v] + dist - ds, v));
		for (int i = 0; i < (int)ed[v].size(); i++) {
			if (ed[v][i] != p && state[ed[v][i]]) {
				p = v;
				v = ed[v][i];
				break;
			}
		}
	}
	printf("%d", ans);
	return 0;
}

