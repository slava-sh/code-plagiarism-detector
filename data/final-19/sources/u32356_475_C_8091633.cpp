#include <bits/stdc++.h>
using namespace std;

int m, n, res;
char a[1111][1111];
int s[1111][1111];
int cx, cy, lx, ly, tx, ty, allx;

int getsum(int x0, int y0, int h, int w){
    return s[x0+h-1][y0+w-1] - s[x0-1][y0+w-1] - s[x0+h-1][y0-1] + s[x0-1][y0-1];
}

void check(int h, int w, int dx, int dy){
    //printf("CHECK %d, %d\n", h, w);
    int x = cx, y = cy, all = h * w;
    if (getsum(x, y, h, w) != h*w) return;
    while (true){
        //printf("FROM %d, %d, %d, %d\n", x, y, dx, dy);
        if (getsum(x + dx, y + dy, h, w) == h*w){
            if (dx) all += w; else all += h;
            x += dx; y += dy;
        }
        else if (getsum(x + dy, y + dx, h, w) == h*w){
            swap(dx, dy);
            if (dx) all += w; else all += h;
            x += dx; y += dy;
        }
        else break;
    }
    if (all == allx) res = min(res, h * w);
}

int main(){
    //freopen("C.inp", "r", stdin);
    scanf("%d%d", &m, &n);
    memset(s, 0, sizeof s);
    allx = 0;
    for (int i = 1; i <= m; i++){
        scanf("%s", a[i] + 1);
        for (int j = 1; j <= n; j++){
            if (a[i][j] == 'X' && allx == 0){
                cx = i; cy = j;
            }
            allx += (a[i][j] == 'X');
            s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + (a[i][j] == 'X');
        }
        s[i][n+1] = s[i][n];
    }
    for (int j = 0; j <= n + 1; j++) s[m+1][j] = s[m][j];

    for (int j = cy; j <= n + 1; j++) if (a[cx][j] != 'X'){
        ly = j - cy; break;
    }
    for (int i = cx; i <= m + 1; i++) if (a[i][cy] != 'X'){
        lx = i - cx; break;
    }
    //printf("%d, %d\n", cx+lx, cy+ly);

    tx = 1; ty = 1;
    for (int j = cy; j < cy + ly; j++) if (a[cx+lx][j] == 'X'){
        ty = cy + ly - j; break;
    }
    for (int i = cx; i < cx + lx; i++) if (a[i][cy+ly] == 'X'){
        tx = cx + lx - i; break;
    }

    res = m * n + 1;
    check(lx, ty, 0, 1); // Right
    check(tx, ly, 1, 0); // down

    if (res > m * n) printf("-1\n");
    else printf("%d\n", res);
    return 0;
}
