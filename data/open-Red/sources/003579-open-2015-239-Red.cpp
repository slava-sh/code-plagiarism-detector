#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define mp make_pair
#define x first
#define y second
#define point pair<int, int>
#define pb push_back
#define For(i, a, b) for(int i = a; i < b; ++i)

using namespace std;

int n, m, d;
vector <pair<int, int> > t[100001];

int finding(int i, int s) {
    int L = 0, R = t[i].size();
    while (R - L > 1) {
        int M = (R + L) / 2;
        if (t[i][M].x > s) {
            R = M;
        }
        else {
            L = M;
        }
    }
    return L;
}

int bfs(int s, int f) {
    if (s == f) {
        return 0;
    }
    vector <bool> used[100001];
    queue <pair<point, int> > q;
    For(i, 0, n) {
        For(q, 0, t[i].size()) {
            used[i].pb(false);
        }
    }
    q.push(mp(mp(s, 0), 0));
    while (!q.empty()) {
        pair<point, int> now = q.front();
        q.pop();
        int temp = now.x.y;
        int cost = now.y, i = now.x.x;
        if (i == f) {
            return cost;
        }
        For(j, 0, t[i].size()) {
            if (abs(temp - t[i][j].x) <= d) {
                int ind = finding(t[i][j].y, t[i][j].x);
                if (!used[t[i][j].y][ind]) {
                    used[t[i][j].y][ind] = true;
                    q.push(mp(mp(t[i][j].y, t[j][ind].x), cost + 1));
                }
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> m >> d;
    For(i, 0, m) {
        int S, F, T;
        cin >> S >> F >> T;
        S--; F--;
        t[S].pb(mp(T, F));
        t[F].pb(mp(T, S));
    }
    For(i, 0, n) {
        sort(t[i].begin(), t[i].end());
    }
    int q;
    cin >> q;
    For(i, 0, q) {
        int S, F;
        cin >> S >> F;
        cout << bfs(S - 1, F - 1) << endl;
    }
}

