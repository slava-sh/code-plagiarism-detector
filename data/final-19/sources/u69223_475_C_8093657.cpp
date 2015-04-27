#include <bits/stdc++.h>

using namespace std;

#define MAXN 1010

char g[MAXN][MAXN];
int x, y, total;

bool simulate(int largura, int altura) {
    int q = largura*altura;
    bool canRight;
    bool canDown;
    pair<int, int> ul = make_pair(x, y);
    pair<int, int> ur = make_pair(x, y+largura-1);
    pair<int, int> dl = make_pair(x+altura-1, y);
    pair<int, int> dr = make_pair(x+altura-1, y+largura-1);
    //printf(">>>%d %d\n", dr.first, dr.second);
    while(1) {
        canRight = false;
        canDown = false;
        if(g[ur.first][ur.second+1] == 'X' && g[dr.first][dr.second+1] == 'X') {
            canRight = true;
        }
        if(g[dl.first+1][dl.second] == 'X' && g[dr.first+1][dr.second] == 'X') {
            canDown = true;
        }
        if(canRight && canDown) return false;
        else if(!canRight && !canDown) {
            if(q == total) return true;
            return false;
        }
        else {
            if(canDown) {
                ul.first++;
                ur.first++;
                dl.first++;
                dr.first++; 
                q+=largura;
            }
            else {
                ul.second++;
                ur.second++;
                dl.second++;
                dr.second++;
                q += altura;
            }
        }
        
    }

    
}

int main() {
    int n, m, k;
    total = 0;
    int r = MAXN*MAXN;
    int largura, altura;
    scanf("%d %d", &n, &m);
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            scanf(" %c", &g[i][j]);
            if(g[i][j] == 'X') total++;
        }
    }
    for(int i = 1; i<=n; i++) {
        for(int j = 1; j<=m; j++) {
            if(g[i][j]  == 'X') {
                x = i;
                y = j;
                for(k = j; g[i][k] == 'X'; k++);
                largura = k-j;
                for(k = i; g[k][j] == 'X'; k++);
                altura = k - i;
                i = j = MAXN;
            }
        }
    }
    //printf("%d\n", simulate(2, 2));
    for(int i = 1; i<=largura; i++) {
        if(simulate(i, altura)) r = min(r, i*altura);
    }
    for(int i = 1; i<=altura; i++) {
        if(simulate(largura, i)) r = min(r, largura*i);
    }
    //printf("%d %d %d %d\n", x, y, largura, altura);
    printf("%d", r==MAXN*MAXN?-1:r);
    return 0;
}
    
    
