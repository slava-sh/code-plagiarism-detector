#include <bits/stdc++.h>

#define ll long long
#define fn "secure"

using namespace std;

const int MXN = 300 * 1000 + 9;
const int INF = 1000 * 1000 * 1000 + 9;
int n, m;
long long int d[5050], ans;
int x, y, c;
vector <pair <int, int> > v[5050];
int q[1000 * 10000], a[5050];
ll q2[10000 *1000];
int p[5050];
int l, r, l2, r2, ansx, ansy;
int main()
{
    freopen(fn".in", "r", stdin);
    freopen(fn".out", "w", stdout);
    ans = 1000 * 1000 * 1000;
    ans *= ans;
    scanf("%d%d", &n, &m);

    l = 1;
    r = 0;
    for (int i = 1; i <= n; i++) {
        d[i] = INF;
        scanf("%d", &a[i]);
        if (a[i] == 1) {
            q[++r] = i;
            q2[r] = 0;
            d[i] = 0;
            p[i] = i;
        }
    }
    for (int i = 1; i <= m; i++) {
        scanf("%d%d%d", &x, &y, &c);
        if (a[x] != 0)
        v[x].push_back(make_pair(y, c));
        if (a[y] != 0)
        v[y].push_back(make_pair(x, c));
    }
    random_shuffle(q + 1, q + r+ 1);
    while(r - l + 1 > 0) {
        int x = q[l++];
        if (q2[l - 1] != d[x] || ans < d[x])
            continue;
        for (int i = 0; i < v[x].size(); i++) {
            if (a[v[x][i].first] == 2) {
                if (ans > v[x][i].second + d[x]) {
                    ansx = p[x];
                    ansy = v[x][i].first;
                    ans = v[x][i].second + d[x];
                }
            } else if (a[v[x][i].first] == 0){
                if (ans > d[x] + v[x][i].second && d[x] + v[x][i].second < d[v[x][i].first]) {
                    q[++r] = v[x][i].first;
                    p[v[x][i].first] = p[x];
                    d[v[x][i].first] = d[x] + v[x][i].second;
                    q2[r] = d[v[x][i].first];
                }
            }
        }
    }
    ll tmp = 1000 * 1000 * 1000;
    tmp *= tmp;
    if (ans == tmp) {
        cout << -1;
    }
    else cout << ansx << ' ' << ansy << ' ' << ans;

    return 0;
}
