#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>

using namespace std;

char g[1010][1010], a[1010][1010], tmp[1010][1010];

bool check(char g[1010][1010], int n, int m, int x, int y, int w, int h) {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j)
            tmp[i][j] = '.';
        tmp[i][m] = 0;
    }
    for(int i = x; i < x+h; ++i)
        for(int j = y; j < y+w; ++j)
            tmp[i][j] = 'X';
    while(1) {
        if (g[x+h][y] == 'X') {
            for(int i = 0; i < w; ++i)
                tmp[x+h][y+i] = 'X';
            ++x;
        }
        else if (g[x][y+w] == 'X'){
            for(int i = 0; i < h; ++i)
                tmp[x+i][y+w] = 'X';
            ++y;
        }
        else break;
    }
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
        if (g[i][j] != tmp[i][j])
            return 0;
    return 1;
}

int find(char g[1010][1010], int n, int m) {
    int x = 0, y, f = 0;
    while(x < n) {
        for(y = 0; y < m; ++y)
            if (g[x][y] == 'X') {
                f = 1;
                break;
            }
        if (f) break;
        x++;
    }
    
    int h = 1, w = y, x0 = x;
    while(w < m && g[x][w] == 'X') ++w;
    while(x0 < n && g[x0][w] != 'X') ++x0;

    w -= y;
    if (x0 < n) {
        h = x0;
        while(h < n && g[h][y] == 'X') ++h;
        h -= x0;
    }
    
    if (check(g, n, m, x, y, w, h))
        return w*h;
    return -1;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; ++i)
        scanf("%s", g[i]);
    
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            a[i][j] = g[j][i];
    
    int a1 = find(g, n, m);
    int a2 = find(a, m, n);
    
    if (a1 == -1) printf("%d\n", a2);
    else if (a2 == -1) printf("%d\n", a1);
    else printf("%d\n", min(a1, a2));
    return 0;
}