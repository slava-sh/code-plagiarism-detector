#include <iostream>
#include <fstream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>

using namespace std;

ifstream fin("travel.in");
ofstream fout("travel.out");

struct tri {
    int first;
    int second;
    char thrid;
};

tri make_tri(int a, int b, char c) {
    tri x;
    x.first = a;
    x.second = b;
    x.thrid = c;
    return x;
}

char m[502][502];
bool visited[502][502];
int n;
int k, ktt, kta, xtt, xta, ytt, yta;
tri path[502][502];
int minta = 1e9, mintt = 1e9;

void wayback(int x, int y) {
    if((x != 0) && (y != 0))
        wayback(path[x][y].first, path[x][y].second);
    else
        return;
    if (path[x][y].thrid)
        fout << path[x][y].thrid;
}

int pathsize(int x, int y) {
    if((x != 0) && (y != 0))
        return pathsize(path[x][y].first, path[x][y].second) + 1;
    else
        return 0;
}


void bfs(int x, int y) {
    queue<pair<int, int> > q;
    k = 1;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    path[x][y] = make_tri(0, 0, 0);
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (m[x][y] == 'T') {
            if(m[x + 1][y] == 'T' || m[x - 1][y] == 'T' || m[x][y + 1] == 'T' || m[x][y - 1] == 'T') {
                mintt = min(mintt, pathsize(x, y));
                xtt = x;
                ytt = y;
                break;
            } else {
                minta = min(minta, pathsize(x, y));
                xta = x;
                yta = y;
            }
        }
        if (m[x + 1][y] != 0 && !visited[x + 1][y]) {
            q.push(make_pair(x + 1, y));
            visited[x + 1][y] = 1;
            path[x + 1][y] = make_tri(x, y, 'S');
        }
        if (m[x - 1][y] != 0 && !visited[x - 1][y]) {
            q.push(make_pair(x - 1, y));
            visited[x - 1][y] = 1;
            path[x - 1][y] = make_tri(x, y, 'N');
        }
        if (m[x][y + 1] != 0 && !visited[x][y + 1]) {
            q.push(make_pair(x, y + 1));
            visited[x][y + 1] = 1;
            path[x][y + 1] = make_tri(x, y, 'E');
        }
        if (m[x][y - 1] != 0 && !visited[x][y - 1]) {
            q.push(make_pair(x, y - 1));
            visited[x][y - 1] = 1;
            path[x][y - 1] = make_tri(x, y, 'W');
        }
    }
    if (mintt < minta * 2) {
        wayback(xtt, ytt);
        if (m[xtt - 1][ytt] == 'T') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'N', k++;
                } else {
                    fout << 'S', k++;
                }
                st++;
            }
        }
        else
        if (m[xtt + 1][ytt] == 'T') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'S', k++;
                } else {
                    fout << 'N', k++;
                }
                st++;
            }
        }
        else
        if (m[xtt][ytt - 1] == 'T') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'W', k++;
                } else {
                    fout << 'E', k++;
                }
            }
        }
        else
        if (m[xtt][ytt + 1] == 'T') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'E', k++;
                } else {
                    fout << 'W', k++;
                }
            }
        }
    }
    else {
        wayback(xta, yta);
        if (m[xta - 1][yta] == 'A') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'N', k++;
                } else {
                    fout << 'S';
                }
                st++;
            }
        }
        else
        if (m[xta + 1][yta] == 'A') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'S', k++;
                } else {
                    fout << 'N';
                }
                st++;
            }
        }
        else
        if (m[xta][yta + 1] == 'A') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'E';
                } else {
                    fout << 'W', k++;
                }
                st++;
            }
        }
        else
        if (m[xta][yta - 1] == 'A') {
            int st = 0;
            while (k < n) {
                if (st % 2 == 0) {
                    fout << 'W';
                } else {
                    fout << 'E', k++;
                }
                st++;
            }
        }
    }
}

int main() {
    int w, h, si, sj;
    fin >> w >> h >> n;
    for (int i = 1; i <= h; ++i)
        for (int j = 1; j <= w; ++j) {
            fin >> m[i][j];
            if (m[i][j] == 'V') {
                si = i, sj = j;
                m[i][j] = 'A';
            }
        }
    bfs(si, sj);
    return 0;
}
