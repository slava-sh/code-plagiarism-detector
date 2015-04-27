#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <cctype>

using namespace std;

const int MAXN = 1024;

char maze[MAXN][MAXN];
int done[MAXN][MAXN];
int n, m;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int qx[MAXN * MAXN], qy[MAXN * MAXN];
int head, tail;
int d[MAXN][MAXN];

bool isok(int x, int y)
{
    return x >= 0 && x < n && y >= 0 && y < m;
}

void colorit(vector<pair<int, int> > &v)
{
    int apped[10] = {false};
    for (int i = 0; i < v.size(); ++i) {
        int x = v[i].first, y = v[i].second;
        for (int k = 0; k < 4; ++k) {
            int nx = x + dx[k], ny = y + dy[k];
            if (isok(nx, ny) && isdigit(maze[nx][ny])) {
                apped[maze[nx][ny] - '0'] = true;
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (!apped[i]) {
            for (int j = 0; j < v.size(); ++j) {
                int x = v[j].first, y = v[j].second;
                maze[x][y] = char(i + '0');
            }
            return;
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i) {
        scanf("%s", maze[i]);
    }
    memset(done, 0, sizeof(done));
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (!done[i][j] && maze[i][j] != '#') {
                head = 0;
                tail = 1;
                qx[head] = i;
                qy[head] = j;
                done[i][j] = 1;
                while (head < tail) {
                    int cx = qx[head];
                    int cy = qy[head++];
                    for (int k = 0; k < 4; ++k) {
                        int nx = cx + dx[k], ny = cy + dy[k];
                        if (!isok(nx, ny) || maze[nx][ny] == '#') continue;
                        if (!done[nx][ny]) {
                            qx[tail] = nx;
                            qy[tail++] = ny;
                        }
                        done[nx][ny] = 1;
                        ++d[cx][cy];
                    }
                }
                if (head == 1) {
                    puts("-1");
                    return 0;
                }
                for (head = 0; head < tail; ++head) {
                    int x = qx[head], y = qy[head];
                    if (done[x][y] == 2) continue;
                    vector<pair<int, int> > v;
                    v.push_back(make_pair(x, y));
                    for (int k = 0; k < 4; ++k) {
                        int nx = x + dx[k], ny = y + dy[k];
                        if (isok(nx, ny) && maze[nx][ny] != '#' && done[nx][ny] != 2 && d[nx][ny] == 1) {
                            v.push_back(make_pair(nx, ny));
                        }
                    }
                    if (v.size() < 2) {
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (isok(nx, ny) && maze[nx][ny] != '#' && done[nx][ny] != 2) {
                                v.push_back(make_pair(nx, ny));
                                for (int kk = 0; kk < 4; ++kk) {
                                    int nnx = nx + dx[kk], nny = ny + dy[kk];
                                    if ((nnx != x || nny != y) && isok(nnx, nny) && maze[nnx][nny] != '#' && done[nnx][nny] != 2 && d[nnx][nny] == 1) {
                                        v.push_back(make_pair(nnx, nny));
                                    }
                                }
                                break;
                            }
                        }
                    }
                    colorit(v);
                    for (int i = 0; i < v.size(); ++i) {
                        int x = v[i].first, y = v[i].second;
                        done[x][y] = 2;
                        for (int k = 0; k < 4; ++k) {
                            int nx = x + dx[k], ny = y + dy[k];
                            if (isok(nx, ny) && maze[nx][ny] != '#') {
                                --d[nx][ny];
                            }
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        puts(maze[i]);
    }
    return 0;
}
