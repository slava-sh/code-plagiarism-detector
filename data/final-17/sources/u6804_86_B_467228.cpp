#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

int n, m;
char st[1100], col[1100][1100];
int ans[1100][1100];
vector<pair<int, int> > v[1100 * 1100];


bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++) {
        scanf("%s", st);
        for (int j = 0; j < m; j++) {
            if (st[j] == '#') ans[i][j] = -1;
        }
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j]) continue;
            cnt++;
            if (j + 1 < m && ans[i][j + 1] == 0) {
                ans[i][j] = ans[i][j + 1] = cnt;
                continue;
            }
            if (i + 1 < n && ans[i + 1][j] == 0) {
                ans[i][j] = ans[i + 1][j] = cnt;
                continue;
            }
            if (i - 1 >= 0 && ans[i - 1][j] > 0) {
                ans[i][j] = ans[i - 1][j];
                continue;
            }
            if (j - 1 >= 0 && ans[i][j - 1] > 0) {
                ans[i][j] = ans[i][j - 1];
                continue;
            }
            if (j + 1 < m && ans[i][j + 1] > 0) {
                ans[i][j] = ans[i][j + 1];
                continue;
            }
            if (i + 1 < n && ans[i + 1][j] > 0) {
                ans[i][j] = ans[i + 1][j];
            }
            puts("-1"); return 0;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            col[i][j] = '#';
            if (ans[i][j] > 0) v[ans[i][j]].push_back(make_pair(i, j));
        }
    }

    bool used[20];
    for (int i = 0; i <= cnt + 10; i++) {
        memset(used, false, sizeof(used));
        for (int j = 0; j < (int)v[i].size(); j++) {
            int x = v[i][j].first, y = v[i][j].second;
            for (int d = 0; d < 4; d++) {
                int xx = x + dx[d], yy = y + dy[d];
                if (valid(xx, yy) && col[xx][yy] != '#') {
                    used[col[xx][yy] - '0'] = true;
                }
            }   
        }
        int color = -1;
        for (int j = 1; j < 10; j++) {
            if (!used[j]) color = j;
        }
        for (int j = 0; j < (int)v[i].size(); j++) {
            col[v[i][j].first][v[i][j].second] = color + '0';
        }
    }

/*  for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (ans[i][j] == -1) col[i][j] = '#';
            else {
//              col[i][j] = gao(i, j);

                if (i > 0 && ans[i][j] == ans[i - 1][j]) {
                    col[i][j] = col[i - 1][j];
                } else if (j > 0 && ans[i][j] == ans[i][j - 1]) {
                    col[i][j] = col[i][j - 1];
                } else {
                    char ch1 = '#', ch2 = '#';
                    if (i > 0 && col[i - 1][j] != '#') {
                        ch1 = col[i - 1][j];
                    }
                    if (j > 0 && col[i][j - 1] != '#') {
                        ch2 = col[i][j - 1];
                    }
                    char ch;
                    for (ch = '1'; ch <= '9'; ch++) {
                        if (ch == ch1 || ch == ch2) continue;
                        break;
                    }
                    col[i][j] = ch;
                }
            }
        }
    }
*/  for (int i = 0; i < n; i++) {
        col[i][m] = '\0';
        printf("%s\n", col[i]);
    }
    return 0;
}
