#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <utility>
#include <algorithm>
#include <string>
#include <set>
#include <stdio.h>
#include <sstream>
#include <math.h>
#include <complex>

using namespace std;

struct result {
    int win;
    int moves;
    bool operator<(const result& res) const {
        if (win != res.win) {
            return win < res.win;
        } else if (win == 2) {
            return moves > res.moves;
        } else if (win == 0) {
            return moves < res.moves;
        } else {
            return false;
        }
    }
    result(): win(0), moves(-2){}
    result(int w, int m): win(w), moves(m) {}
};

int R;
vector<pair<int, int> > head;
vector<pair<int, int> > tail;

enum Color {WHITE, GREY, BLACK};
vector<vector<Color> > color;
bool canDraw;

void dfs(int h, int t) {
    if (h+t == 0 || h+t > R) {
        return;
    }
    if (color[h][t] != BLACK) {
        if (color[h][t] == GREY) {
            canDraw = true;
        } else {
            color[h][t] = GREY;
            for (int i = 0; i < (int)head.size() && i+1 <= h; ++i) {
                dfs(h - (i+1) + head[i].first, t + head[i].second);
            }
            for (int i = 0; i < (int)tail.size() && i+1 <= t; ++i) {
                dfs(h + tail[i].first, t - (i+1) + tail[i].second);
            }
            color[h][t] = BLACK;
        }
    }
}

vector<vector<result> > res;

result rec(int h, int t) {
    if (h+t == 0) {
        return result(2, 0);
    } else if (h+t > R) {
        return result(0, 0);
    } else if (res[h][t].moves == -2) {
        res[h][t].moves = -10;
        result best(0, -1);
        for (int i = 0; i < (int)head.size() && i+1 <= h; ++i) {
            result ch = rec(h - (i+1) + head[i].first, t + head[i].second);
            if (ch.moves == -10) {
                ch.win = 1;
            }
            ch.moves++;
            best = max(best, ch);
        }
        for (int i = 0; i < (int)tail.size() && i+1 <= t; ++i) {
            result ch = rec(h + tail[i].first, t - (i+1) + tail[i].second);
            if (ch.moves == -10) {
                ch.win = 1;
            }
            ch.moves++;
            best = max(best, ch);
        }
        res[h][t] = best;
    }
    return res[h][t];
}

vector<vector<int> > mm;

int maxMoves(int h, int t) {
    if (h+t == 0 || h+t > R) {
        return 0;
    } else if (mm[h][t] < 0) {
        int best(-1);
        for (int i = 0; i < (int)head.size() && i+1 <= h; ++i) {
            int ch = maxMoves(h - (i+1) + head[i].first, t + head[i].second);
            ch++;
            best = max(best, ch);
        }
        for (int i = 0; i < (int)tail.size() && i+1 <= t; ++i) {
            int ch = maxMoves(h + tail[i].first, t - (i+1) + tail[i].second);
            ch++;
            best = max(best, ch);
        }
        mm[h][t] = best;
    }
    return mm[h][t];
}

int main() {
    cout << fixed;
    cout.precision(9);


    int h, t;
    cin >> h >> t >> R;
    int n;
    cin >> n;
    head.resize(n);
    for (int i = 0; i < n; ++i) {
        cin >> head[i].first >> head[i].second;
    }
    int m;
    cin >> m;
    tail.resize(m);
    for (int i = 0; i < m; ++i) {
        cin >> tail[i].first >> tail[i].second;
    }


    color = vector<vector<Color> > (R+1, vector<Color>(R+1, WHITE));
    
    canDraw = false;
    dfs(h, t);

    
    vector<vector<int> > res(R+1, vector<int>(R+1, -1));
    
    int moves = -1;
    res[h][t] = 0;
    list<int> q;
    q.push_back(h);
    q.push_back(t);
    while (!q.empty()) {
        int H = q.front(); q.pop_front();
        int T = q.front(); q.pop_front();
        if (H + T == 0) {
            moves = res[H][T];
            break;
        }
        for (int i = 0; i < (int)head.size() && i+1 <= H; ++i) {
            int h1 = H - (i+1) + head[i].first, t1 = T + head[i].second;
            if (h1 + t1 <= R && res[h1][t1] == -1) {
                res[h1][t1] = res[H][T] + 1;
                q.push_back(h1); q.push_back(t1);
            }
        }
        for (int i = 0; i < (int)tail.size() && i+1 <= T; ++i) {
            int h1 = H + tail[i].first, t1 = T - (i+1) + tail[i].second;
            if (h1 + t1 <= R && res[h1][t1] == -1) {
                res[h1][t1] = res[H][T] + 1;
                q.push_back(h1); q.push_back(t1);
            }
        }
    }
    
    if (moves >= 0) {
        cout << "Ivan\n" << moves << endl;
    } else if (canDraw) {
        cout << "Draw\n";
    } else {
        mm = vector<vector<int> > (R+1, vector<int>(R+1, -1));
        int moves = maxMoves(h, t);
        cout << "Zmey\n" << moves << endl;
    } 
    
    return 0;
}
