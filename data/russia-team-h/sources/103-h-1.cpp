#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

const int N = 5005;
const int INF = 1e9;

int a[N][N], n, m, x , y, z, d[N], par[N], c[N];
bool used[N];

int main()
{
    freopen("secure.in", "r", stdin);
    freopen("secure.out", "w", stdout);
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            a[i][j] = INF;
    for (int i = 0; i < n; i++)
        cin >> c[i];
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> z;
        x--;
        y--;
        if ((c[x] == c[y]) && ((c[x] == 1) || (c[x] == 2)))
            continue;
        if (c[x] == 1)
            a[x][y] = z;
        else if (c[y] == 1)
            a[y][x] = z;
        else if (c[x] == 2)
            a[y][x] = z;
        else if (c[y] == 2)
            a[x][y] = z;
        else {
            a[x][y] = z;
            a[y][x] = z;
        }
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (c[i] == 1 && c[j] != 1)
                a[n][j] = min(a[n][j], a[i][j]);
    for (int i = 0; i <= n; i++)
        d[i] = INF;
    d[n] = 0;
    n++;
    while (1) {
        int mn = INF;
        int ind = -1;
        for (int i = 0; i < n; i++)
            if (!used[i] && d[i] < mn) {
                mn = d[i];
                ind = i;
            }
        if (ind == -1)
            break;
        used[ind] = 1;
        for (int i = 0; i < n; i++)
            if (!used[i] && d[i] > d[ind] + a[ind][i]) {
                d[i] = d[ind] + a[ind][i];
                par[i] = ind;
            }
    }
    int mn = INF;
    int ind = -1;
    for (int i = 0; i < n; i++)
        if (c[i] == 2 && mn > d[i]) {
            mn = d[i];
            ind = i;
        }
    if (mn == INF) {
        cout << -1;
        return 0;
    }
    int ind0 = ind;
    while (par[ind] != n - 1)
        ind = par[ind];
    int t = d[ind];
    for (int i = 0; i < n; i++)
        if (c[i] == 1 && a[i][ind] == t) {
            cout << i + 1 << " ";
            break;
        }
    cout << ind0 + 1 << " " << mn;
    return 0;
}
