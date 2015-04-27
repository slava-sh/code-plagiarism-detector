#include <bits/stdc++.h>
#ifdef ONLINE_JUDGE
    #define out(x)
#else
    #define out(x) cerr<<#x"="<<(x)<<endl
#endif
using namespace std;
typedef long long LL;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
#define REP(i,n) for(int i=0; i<int(n); i++)
#define pb push_back
#define mp make_pair
#define X first
#define Y second
char g[1123][1123], a[1123][1123];
char t[1123][1123];
void print(int n){
    REP(i,n)puts(t[i]);
    puts("--------");
}
bool check(char g[1123][1123], int n, int m,
            int x, int y, int w, int h){
    REP(i,n){
        REP(j,m)t[i][j]='.';
        t[i][m]=0;
    }
    for(int i=x; i<x+h; ++i)
        for(int j=y; j<y+w; ++j)
            t[i][j]='X';
    for(;;){
        //print(n);
        if(g[x+h][y]=='X'){
            REP(i,w)t[x+h][y+i]='X';
            ++x;
        } else if(g[x][y+w]=='X'){
            REP(i,h)t[x+i][y+w]='X';
            ++y;
        } else break;
    }
    REP(i,n)REP(j,m)if(g[i][j]!=t[i][j])return 0;
    return 1;
}
int gao(char g[1123][1123], int n, int m){
    int x=0, y;
    bool found=0;
    for(;x<n;++x){
        for(y=0;y<m;++y)
            if(g[x][y]=='X'){
                found=1;
                break;
            }
        if(found)break;
    }
    //REP(i,n)puts(g[i]);
    assert(found);
    int h=1, w=y, x0=x;
    for(;w<m&&g[x][w]=='X';++w);
    for(;x0<n&&g[x0][w]!='X';++x0);
    w-=y;
    if(x0<n){
        h=x0;
        for(;h<n&&g[h][y]=='X';++h);
        h-=x0;
    }
    //printf("x=%d, y=%d, w=%d, h=%d\n", x, y, w, h);
    if(check(g,n,m,x,y,w,h))return w*h;
    return -1;
}
int main(){
    int n, m;
    scanf("%d%d ",&n,&m);
    REP(i,n)scanf("%s",g[i]);
    int ans0=gao(g,n,m);
    REP(i,m)REP(j,n)
        a[i][j]=g[j][i];
    int ans=gao(a,m,n);
    if(ans==-1)ans=ans0;
    if(ans0!=-1 && ans>ans0)ans=ans0;
    printf("%d\n", ans);
}
