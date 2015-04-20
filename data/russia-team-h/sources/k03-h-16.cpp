#include <bits/stdc++.h>

#define ll long long
#define fn "secure"

using namespace std;

const int MXN = 300 * 1000 + 9;
const int INF = 1000 * 1000 * 1000;
int n, m;
ll ans;
int a[5050];
int x, y, c;
vector <pair <int, int> > v[5050];
vector <int> q;
int ansx, ansy;
int color[5050];
void dfs(int x, int c, long long int d) {
    for (int i = 0; i < v[x].size(); i++) {
        if (a[v[x][i].first] == 2) {
            if (ans > v[x][i].second + d) {
                ansx = q[c - 1];
                ansy = v[x][i].first;
                ans = v[x][i].second + d;
            }
        } else if(a[v[x][i].first] == 0) {
            if (ans > v[x][i].second + d) {
                dfs(v[x][i].first, c, v[x][i].second + d);
            }
        }
    }
}
int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
        ll tmp = INF;
        tmp *= tmp;
    ans = tmp;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            q.push_back(i);
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &c);
        v[x].push_back(make_pair(y, c));

        v[y].push_back(make_pair(x, c));
    }
    for (int i = 0; i < q.size(); i++) {
        dfs(q[i], i + 1, 0);
    }

    if (ans != tmp)
        cout << ansx << ' ' << ansy << " " << ans;
    else {
        cout << -1;

    }
    return 0;
}
