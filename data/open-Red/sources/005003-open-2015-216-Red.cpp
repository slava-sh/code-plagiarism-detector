#include <cstdio>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <set>
#include <map>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <queue>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;
const int N = 3e5;
const int INF = 2e9;

int u[N], v[N], t[N], f[N][2];
vector <int> edges[N];
set <int> base[N];
queue <pii> q;
queue <int> dele;
bool was[N];

void update(int i1, int i2, int val) {
    if (f[i1][i2] == INF) {
        q.push(make_pair(i1, i2));
    }
    int i3 = 1 - i2;
    if (f[i1][i3] != INF && f[i1][i2] == INF) {
        dele.push(i1);
    }
    f[i1][i2] = min(f[i1][i2], val);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    int n, m, d;
    cin >> n >> m >> d;
    for (int i = 1; i <= m; i++) {
        cin >> u[i] >> v[i] >> t[i];
        edges[u[i]].push_back(i);
        edges[v[i]].push_back(i);
    }
    int quests;
    cin >> quests;
    for (int qq = 1; qq <= quests; qq++) {
        memset(was, false, sizeof(was));
        int a, b;
        cin >> a >> b;
        while (!dele.empty()) {
            dele.pop();
        }
        for (int i = 0; i <= n; i++) {
            base[i].clear();
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < edges[i].size(); j++) {
                base[i].insert(edges[i][j]);
            }
        }
        for (int i = 0; i < N; i++) {
            f[i][0] = f[i][1] = INF;
        }
        for (int i = 0; i < edges[a].size(); i++) {
            int nom = edges[a][i];
            if (v[nom] == a) {
                update(nom, 1, 1);
                update(nom, 0, 2);
            } else {
                update(nom, 0, 1);
                update(nom, 1, 2);
            }
        }
        while (!q.empty()) {
            int i1 = q.front().first;
            int j1 = q.front().second;
            q.pop();
            int cur;
            if (j1 == 0) {
                cur = v[i1];
            } else {
                cur = u[i1];
            }
            for (set <int>::iterator it = base[cur].begin(); it != base[cur].end(); it++) {
                int nom = *it;
                if (abs(t[nom] - t[i1]) > d) {
                    continue;
                }
                int will;
                if (v[nom] == cur) {
                    will = 1;
                } else {
                    will = 0;
                }
                update(nom, will, f[i1][j1] + 1);
                update(nom, 1 - will, f[i1][j1] + 2);
            }
            while (!dele.empty()) {
                int x = dele.front();
                dele.pop();
                if (was[x]) {
                    continue;
                }
                was[x] = true;
                base[v[x]].erase(base[v[x]].find(x));
                base[u[x]].erase(base[u[x]].find(x));
            }
        }
        int ans = INF;
        for (int i = 1; i <= m; i++) {
            if (v[i] == b) {
                ans = min(ans, f[i][0]);
            }
            if (u[i] == b) {
                ans = min(ans, f[i][1]);
            }
        }
        if (ans == INF) {
            ans = -1;
        }
        cout << ans << "\n";
    }
    return 0;
}