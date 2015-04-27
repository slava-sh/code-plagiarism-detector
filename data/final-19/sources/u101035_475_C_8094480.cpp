#include <cstdio>
#include <cstring>
#include <set>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAXN = 1010 ;

char s[MAXN][MAXN] ;
int sum[MAXN][MAXN] ;
int n,m;
int sx,sy;
int ans;

bool check(int a,int b,int c,int d){
    return (c-a+1) * (d-b+1) == (sum[c][d] - sum[a-1][d] - sum[c][b-1] + sum[a-1][b-1]) ;
}

bool solve(int x,int y){

    int cover = x*y ;
    int nx = sx , ny = sy ;
    while (true){
        if (nx + x <= n && check(nx+x,ny,nx+x,ny+y-1)){
            nx++ ;
            cover += y ;
        }else if (ny + y <= m && check(nx,ny+y,nx+x-1,ny+y)){
            ny++ ;
            cover += x ;
        }else
            break ;
    }
    if (cover == sum[n][m]){
        if (ans == -1 || x * y < ans)
            ans = x * y ;
    }
}

int main(){

    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
        scanf("%s",s[i]+1);
    for (int i=1;i<=n;i++)
        for (int j=1;j<=m;j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1] + (s[i][j]=='X');

    bool flag = false ;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            if (s[i][j]=='X'){
                sx = i ;
                sy = j ;
                flag = true ;
                break ;
            }
        if (flag) break ;
    }
    ans=-1;
    int ty = sy ;
    while (ty <= m && s[sx][ty] == 'X') ty++ ;
    ty--;
    for (int i = 1 ; sx + i - 1 <= n ; i++){
        if (check(sx,sy,sx+i-1,ty))
        {
            solve(i,ty-sy+1);
        }
        else break ;
    }
    int tx = sx;
    while (tx <= n && s[tx][sy] == 'X') tx++ ;
    tx--;
    for (int i = 1 ; sy + i - 1 <= m ; i++){
        if (check(sx,sy,tx,sy+i-1))
            solve(tx-sx+1,i);
        else break ;
    }
    printf("%d\n",ans);
}
