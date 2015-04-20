#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
using namespace std;
const int inf = 1000000001;
const int maxn = 5001;
vector< pair<int,int> >yul[maxn];
pair<int, int>nestle[maxn][3];
int t[maxn<<2], b[maxn], n;
void yangi(int v, int l, int r, int pos, int x, int k){
    if(l == r){
        t[v] = x; return ;
    }
    int m = (l+r) >> 1;
    if(pos>m) yangi(v << 1|1, m+1, r, pos, x, k);
    else yangi(v<<1, l, m, pos, x, k);
    t[v] = t[v<<1] == 0 || (t[v<<1|1] && nestle[t[v<<1]][k]>nestle[t[v<<1|1]][k]) ? t[v<<1|1] : t[v<<1] ;
}
void make_ip(int k){
    int u, v, w;
    memset(t,0,sizeof t);
    for(int i=1; i<=n; i++)
        if(b[i] == 0 && nestle[i][k].first ) yangi(1,1,n, i, i,k);
        while(t[1]){
            u = t[1];
            for(int i=0; i<yul[u].size(); i++){
                v = yul[u][i].second;
                w = yul[u][i].first;
                if(!nestle[v][k].first || nestle[v][k].first > nestle[u][k].first + w){
                    nestle[v][k] = nestle[u][k];
                    nestle[v][k].first += w;
                    yangi(1,1,n,v,v,k);
                }
            }
            yangi(1,1,n,u,0,k);
        }
}
int main(){
    freopen("secure.in","r",stdin);
    freopen("secure.out","w",stdout);
    int u,v,w,m;
    int result = inf, l = -1, j = -1;
    scanf("%i %i", &n, &m);
    for(int i=1; i<=n; i++)
        scanf("%i", b+i);
    for(int i=0; i<m; i++){
        scanf("%i %i %i", &u, &v, &w);
        if(b[u]+b[v] && b[u] == b[v]) continue;
        if(b[u]+b[v] == 3){
            if(result > w){
                if(b[u] == 1) l = u, j = v;
                else l = v, j = u;
                result = w;
            }
            continue;
        }
        if(b[u]+b[v]){
            if(b[u] == 0){
                if(nestle[u][b[v]].first == 0 || nestle[u][b[v]].first > w)
                    nestle[u][b[v]] = pair<int, int>(w,v);
            }
            else{
                if(nestle[v][b[u]].first == 0 || nestle[v][b[u]].first > w)
                    nestle[v][b[u]] = pair<int, int>(w,u);
            }
            continue;
        }
        yul[u].push_back(pair<int, int>(w,v));
        yul[v].push_back(pair<int, int>(w,u));
    }
    make_ip(1);
    make_ip(2);
    for(int i=1; i<=n; i++)
        if(b[i] == 0 && nestle[i][1].first && nestle[i][2].first && result > nestle[i][1].first + nestle[i][2].first){
            result = nestle[i][1].first + nestle[i][2].first;
            l = nestle[i][1].second;
            j = nestle[i][2].second;
        }
    if(l != -1) printf("%i %i %i\n", l, j, result);
    else puts("-1");
    return 0;
}

