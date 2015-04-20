#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int w, h, n, mas[500][500], bx, by, dmas[500][500], din[500][500], dopdin[500][500], dmasb[500][500];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector <int> ansv;

bool masb[500][500];
string s, outs = "NWSE", outs2 = "ESWN";

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> w >> h >> n;
    for (int i = 0; i < h; ++i) {
        cin >> s;
        for (int j = 0; j < w; ++j) {
            if (s[j] == 'T') {
                mas[i][j] = 1;
            }
            if (s[j] == 'V') {
                bx = i;
                by = j;
            }
        }
    }
    int ans = 0, ml = 2000;
    int mx = 0, my = 0;
    for (int i = 0; i < h; ++i) {
        //cin >> s;
        for (int j = 0; j < w; ++j) {
            if (mas[i][j] == 1) {
                if (ml > abs(i - bx) + abs(j - by)) {
                    ml = abs(i - bx) + abs(j - by);
                    mx = i;
                    my = j;   
                }
                for (int k = 0; k < 4; ++k) {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < h && ny >= 0 && ny < w && mas[nx][ny] == 1) {
                        masb[i][j] = true;
                        dmasb[i][j] = k;
                        //cout << i << " " << j  << " " << k << endl;
                    }
                }
            }
            //bool truly = false;
            
        }
    }
    ans = abs(bx - mx) + abs(by - my) + 2 * (n - 1);
    int dopm = 0;
    int mmx = mx, mmy = my;
    ml = 2000;
    mx = 0, my = 0;
    for (int i = 0; i < h; ++i) {
        //cin >> s;
        for (int j = 0; j < w; ++j) {
            if (masb[i][j]) {
                if (ml > abs(i - bx) + abs(j - by)) {
                    ml = abs(i - bx) + abs(j - by);
                    mx = i;
                    my = j;   
                }

            }
            
        }
    }
    //cout << "#" << mx << " " << my << endl;
    if (ml != 2000) {   
        int delx = 0, dely = 0;
        if (mx < bx) {
            delx = -1;
        } else {
            delx = 1;
        }
        if (my < by) {
            dely = -1;
        } else {
            dely = 1;
        }
        for (int i = bx; i != mx + delx; i += delx) {
            for (int j = by; j != my + dely; j += dely) {
                dmas[(int) abs(i - bx)][(int) abs(j - by)] = mas[i][j];
            }
        } 
        int nh = abs(bx - mx) + 1, nw = abs(by - my) + 1;
        for (int i = 0; i < nh; ++i) {
            for (int j = 0; j < nw; ++j) {
                if (i > 0) {
                    if (din[i][j] <= din[i - 1][j]) {
                        din[i][j] = din[i - 1][j];
                        dopdin[i][j] = 1;
                    }
                    //din[i][j] = max(din[i][j], din[i - 1][j]);
                }
                if (j > 0) {
                    if (din[i][j] < din[i][j - 1]) {
                        din[i][j] = din[i][j - 1];
                        dopdin[i][j] = 2;
                    }
                }
                if (dmas[i][j] == 1) {
                    ++din[i][j];
                }
            }

        }
        //cout << din[nh - 1][nw - 1] << " " << dmas[nh - 1][nw - 1] << endl;
        if (din[nh - 1][nw - 1] <= n) {
            if (ans > nh + nw - 2 + (n - din[nh - 1][nw - 1])) {
                ans = nh + nw - 2 + (n - din[nh - 1][nw - 1]);
                dopm = 1;
            }
            
        }
    }
    //cout << "@" << ans << " " << dopm;
    

    if (dopm == 0) {
        int delx = 0, dely = 0;
        if (mmx < bx) {
            delx = -1;
        } else {
            delx = 1;
        }
        if (mmy < by) {
            dely = -1;
        } else {
            dely = 1;
        }
        for (int i = bx; i != mmx; i += delx) {
            cout << outs[1 + delx];
        }
        for (int i = by; i != mmy; i += dely) {
            cout << outs[2 + dely];
        }
        for (int i = 0; i < n - 1; ++i) {
            //cout << "@";
            if (mmx != bx) {
                cout << outs[1 - delx] << outs[1 + delx];
            } else {
                cout << outs[2 - dely] << outs[2 + dely];
            }
        }
    } else {
        int nh = abs(bx - mx) + 1, nw = abs(by - my) + 1;
        int nx = nh - 1, ny = nw - 1;

        //cout << nx << " " << ny << endl;
        while (nx > 0 || ny > 0) {
            //cout << nx << " " << ny << endl;
            if (dopdin[nx][ny] == 1) {
                nx -= 1;
                ansv.push_back(1);
            } else {
                ny -= 1;
                ansv.push_back(2);
            }
        }
        reverse(ansv.begin(), ansv.end());
        int delx = 0, dely = 0;
        if (mx < bx) {
            delx = -1;
        } else {
            delx = 1;
        }
        if (my < by) {
            dely = -1;
        } else {
            dely = 1;
        }
        for (int i = 0; i < (int) ansv.size(); ++i) {
            if (ansv[i] == 1) {
                cout << outs[1 + delx];
            } else {
                cout << outs[2 + dely];
            }

        }
        nx = mx;
        ny = my;
        for (int i = 0; i < n - din[nh - 1][nw - 1]; ++i) {
            cout << outs2[dmasb[nx][ny]];
            nx += dx[dmasb[nx][ny]];
            ny += dy[dmasb[nx][ny]];
        }
    }
    return 0;
}