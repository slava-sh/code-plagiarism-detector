#include <bits/stdc++.h>

#define ll long long
#define fn "secure"

using namespace std;

const int MXN = 300 * 1000 + 9;
const int INF = 1000 * 1000 * 1000 + 9;
int n, m, ans = INF;
int d[5050];
int x, y, c;
vector <pair <int, int> > v[5050];
queue <int> q;
int a[5050];
int p[5050];
int ansx, ansy;
int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            q.push(i);
            d[i] = 0;
            p[i] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &c);
        v[x].push_back(make_pair(y, c));
        v[y].push_back(make_pair(x, c));
    }
    while(!q.empty()) {
        int x = q.front();
        //cout << x << ' '<< d[x] << ' ' endl;
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            if (a[v[x][i].first] == 2) {
                if (ans > v[x][i].second + d[x]) {
                    ansx = p[x];
                    ansy = v[x][i].first;
                    ans = v[x][i].second + d[x];
                }
            } else if (a[v[x][i].first] == 0){
                if (d[x] + v[x][i].second < d[v[x][i].first]) {
                    q.push(v[x][i].first);
                    p[v[x][i].first] = p[x];
                    d[v[x][i].first] = d[x] + v[x][i].second;
                }
            }
        }
    }
    if (ans == INF) {
        cout << -1;
    }
    else cout << ansx << ' ' << ansy << ' ' << ans;

    return 0;
}
