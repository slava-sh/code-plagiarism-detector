//In the name of God
//...
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
const int N = 1000 + 10, oo = 1e9;

int n, m, x = -1, y = -1, r[N][N], c[N][N], ans = oo, mark[N][N];
char a[N][N];

void check(int s, int t) {
    int x = ::x, y = ::y;
    fill(mark[0], mark[N], false);
    for (int i = 0; i < s; i++)
        for (int j = 0; j < t; j++)
            mark[x + i][y + j] = true;
    while (true) {
        if (x + s < n && a[x + s][y] == 'X') {
            for (int i = 0; i < t && y + i < m; i++)
                mark[x + s][y + i] = true;
            x++;
        }
        else if (y + t < m && a[x][y + t] == 'X') {
            for (int i = 0; i < s && x + i < n; i++)
                mark[x + i][y + t] = true;
            y++;
        }
        else
            break;
    }
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((mark[i][j] && a[i][j] == '.') || (!mark[i][j] && a[i][j] == 'X'))
                return;
    ans = min(ans, s * t);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
            if (x == -1 && a[i][j] == 'X')
                x = i, y = j;
        }
    for (int i = n - 1; i >= 0; i--)
        for (int j = m - 1; j >= 0; j--)
            if (a[i][j] == 'X') {
                r[i][j] = r[i][j + 1] + 1;
                c[i][j] = c[i + 1][j] + 1;
            }
    int s = c[x][y];
    for (int t = y; t <= m; t++)
        if (t == m)
            check(s, 1);
        else if (a[s + x][t] == 'X') {
            check(s, r[x][y] - (t - y));
            break;
        }
    int t = r[x][y];
    for (int tmp = x; tmp <= n; tmp++) {
        if (tmp == n)
            check(1, t);
        else if (a[tmp][y + t] == 'X') {
            check(c[x][y] - (tmp - x), t);
            break;
        }
    }
    cout << (ans == oo? -1: ans) << '\n';
    return 0;
}
