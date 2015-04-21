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
typedef pair <int, pii> piii;
const int N = 3e5;
const int INF = 2e9;

int u[N], v[N], t[N], f[N][2];
vector <int> edges[N];
set <pii> base[N];
queue <int> dele;
set <piii> q;
bool was[N];

void update(int i1, int i2, int val) {
    if (f[i1][i2] <= val) {
        return;
    }
    q.insert(make_pair(val, make_pair(i1, i2)));
    f[i1][i2] = val;
    if (f[i1][1 - i2] != INF && f[i1][i2] != INF) {
        dele.push(i1);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
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
        q.clear();
        while (!dele.empty()) {
            dele.pop();
        }
        for (int i = 0; i <= n; i++) {
            base[i].clear();
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < edges[i].size(); j++) {
                base[i].insert(make_pair(t[edges[i][j]], edges[i][j]));
            }
        }
        //cout << base[1].lower_bound({3, 0})->first << " " << base[1].lower_bound({3, 0})->second << "\n";
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
        while (!dele.empty()) {
            int x = dele.front();
            dele.pop();
            if (was[x]) {
                continue;
            }
            was[x] = true;
            base[v[x]].erase(base[v[x]].find(make_pair(t[x], x)));
            if (v[x] != u[x]) {
                base[u[x]].erase(base[u[x]].find(make_pair(t[x], x)));
            }
        }
        while (!q.empty()) {
            piii cc = *q.begin();
            q.erase(q.begin());
            int val = cc.first;
            int i1 = cc.second.first;
            int j1 = cc.second.second;
            if (val != f[i1][j1]) {
                continue;
            }
            //cout << v[i1] << " " << u[i1] << " " << t[i1] << " " << j1 << " " << val << "\n";
            int cur;
            if (j1 == 0) {
                cur = v[i1];
            } else {
                cur = u[i1];
            }
            set <pii>::iterator it = base[cur].lower_bound(make_pair(t[i1] - d, 0));
            while (it != base[cur].end()) {
                int nom = it->second;
                it++;
                if (abs(t[nom] - t[i1]) > d) {
                    break;
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
                base[v[x]].erase(base[v[x]].find(make_pair(t[x], x)));
                if (v[x] != u[x]) {
                    base[u[x]].erase(base[u[x]].find(make_pair(t[x], x)));
                }
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