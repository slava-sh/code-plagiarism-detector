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
vector <pair<point, int> > t[500001];
pair<point, int> q[500001];
vector <bool> used[500001];

int bfs(int s, int f) {
    if (s == f) {
        return 0;
    }
    int L = 0, R = 0;
    For(i, 0, n) {
        For(q, 0, used[i].size()) {
            used[i][q] = 0;
        }
    }
    For(i, 0, t[s].size()) {
        used[s][i] = true;
        q[R] = mp(mp(s, i), 0);
        ++R;
    }
    while (L != R) {
        pair<point, int> now = q[L];
        ++L;
        int temp = t[now.x.x][now.x.y].x.x;
        int cost = now.y, i = now.x.x;
        if (i == f) {
            return cost;
        }
        For(j, 0, t[i].size()) {
            if (abs(temp - t[i][j].x.x) <= d) {
                int ind = t[i][j].y;
                if (!used[t[i][j].x.y][ind]) {
                    used[t[i][j].x.y][ind] = true;
                    q[R] = mp(mp(t[i][j].x.y, ind), cost + 1);
                    ++R;
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
        used[S].pb(0);
        used[F].pb(0);
        t[S].pb(mp(mp(T, F), t[F].size()));
        t[F].pb(mp(mp(T, S), (int)t[S].size() - 1));
    }
    int q;
    cin >> q;
    For(i, 0, q) {
        int S, F;
        cin >> S >> F;
        cout << bfs(S - 1, F - 1) << endl;
    }
}

