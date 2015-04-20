//H solution
#include <string.h>
#include <stdio.h>
#include <vector>
using namespace std;

const int maxn = 5001;
vector <pair<int,int> > myvector[maxn];

pair<int,int>zeros[maxn][3];

int t[maxn<<2];
int b[maxn];
int n;

void rqm_insert(int v, int l, int r, int pos, int new_val, int K){
    if(l == r){
        t[v] = new_val;
        return ;
    }
    int m = (l + r) >> 1;
    if(pos > m)rqm_insert(v<<1|1,m+1,r,pos,new_val,K);
    else rqm_insert(v<<1,l,m,pos,new_val,K);
    t[v] = t[v<<1] == 0 || (t[v<<1|1] && zeros[t[v<<1]][K] > zeros[t[v<<1|1]][K]) ? t[v<<1|1] : t[v<<1];
}

void Insert_myVector(int K){
    int u,v,w;
    memset(t,0,sizeof t);
    for(int i = 1; i <= n; i ++)
      if(b[i] == 0 && zeros[i][K].first)
          rqm_insert(1,1,n,i,i,K);
    while(t[1]){
        u = t[1];
        for(int i = 0; i < myvector[u].size(); i ++){
            v = myvector[u][i].second;
            w = myvector[u][i].first;
            if(!zeros[v][K].first || zeros[v][K].first > zeros[u][K].first + w){
                zeros[v][K] = zeros[u][K];
                zeros[v][K].first += w;
                rqm_insert(1,1,n,v,v,K);
            }
        }
        rqm_insert(1,1,n,u,0,K);
    }
}

int main(){
    int u,v,w,m;
    int result = 1000000000, I = -1, J = -1;
    scanf("%i %i",&n,&m);
    for(int i = 1; i <= n; i ++)scanf("%i",b + i);
    for(int i = 0; i < m; i ++){
        scanf("%i %i %i",&u,&v,&w);
        if(b[u] + b[v] == 3){
            if(result > w){
                if(b[u] == 1)I = u, J = v;
                else I = v, J = u;
                result = w;
            }
            continue;
        }

        if(b[u] + b[v]  && b[u] == b[v])continue ;
        if(b[u] + b[v]){
            if(b[u] == 0){
                if(zeros[u][b[v]].first == 0 || zeros[u][b[v]].first > w)
                zeros[u][b[v]] = pair<int,int>(w,v);
            }else{
                if(zeros[v][b[u]].first == 0 || zeros[v][b[u]].first > w)
                zeros[v][b[u]] = pair<int,int>(w,u);
            }
            continue ;
        }
        myvector[u].push_back(pair<int,int>(w,v));
        myvector[v].push_back(pair<int,int>(w,u));
    }
    for(int i = 1; i <= 2; i ++) Insert_myVector(i);
    for(int i = 1; i <= n; i ++)
      if(b[i] == 0 && zeros[i][1].first && zeros[i][2].first && result > zeros[i][1].first + zeros[i][2].first){
          result = zeros[i][1].first + zeros[i][2].first;
          I = zeros[i][1].second;
          J = zeros[i][2].second;
      }
    if(I != -1)printf("%i %i %i\n",I,J,result);
    else puts("-1");
    return 0;
}
