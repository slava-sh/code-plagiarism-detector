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
tri path[502][502];

void wayback(int x, int y) {
    if((x != 0) && (y != 0))
        wayback(path[x][y].first, path[x][y].second);
    else
        return;
    if (path[x][y].thrid)
        fout << path[x][y].thrid;
}

void bfs(int x, int y) {
    int k = 1;
    queue<pair<int, int> > q;
    q.push(make_pair(x, y));
    visited[x][y] = 1;
    path[x][y] = make_tri(0, 0, 0);
    while (!q.empty()) {
        x = q.front().first;
        y = q.front().second;
        q.pop();
        if (m[x][y] == 'T')
            break;
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
    wayback(x, y);
    if (m[x - 1][y] == 'T') {
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
    if (m[x + 1][y] == 'T') {
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
    if (m[x][y - 1] == 'T') {
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
    if (m[x][y + 1] == 'T') {
        int st = 0;
        while (k < n) {
            if (st % 2 == 0) {
                fout << 'E', k++;
            } else {
                fout << 'W', k++;
            }
        }
    }
    else
    if (m[x - 1][y] == 'A') {
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
    if (m[x + 1][y] == 'A') {
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
    if (m[x + 1][y] == 'A') {
        int st = 0;
        while (k < n) {
            if (st % 2 == 0) {
                fout << 'S';
            } else {
                fout << 'N', k++;
            }
            st++;
        }
    }
    else
    if (m[x][y - 1] == 'A') {
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
