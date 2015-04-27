#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<vector>
#include<set>
#include<list>
#include<queue>
#include<cmath>
#include<functional>
#include<algorithm>
#define INF (1<<29)
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;


int n,m,MOD;
int dp1[501][501],dp2[501][501];



#define MAXN 500
int c[MAXN+1][MAXN+1];
void init(){
    c[0][0]=1;
    for(int i=1;i<=MAXN;i++){
        c[i][0]=1;
        for(int j=1;j<=i;j++)
            c[i][j] = (c[i-1][j-1]+c[i-1][j])%MOD;
    }
}


int main(){
    cin>>n>>m>>MOD;
    init();
    int col[500]={};
    int a=0,b=0;
    rep(i,m){
        rep(j,n){
            char c;
            cin>>c;
            if(c=='1')col[j]++;
        }
    }
    rep(j,n){
        if(col[j]==0)a++;
        else if(col[j]==1)b++;
    }
    int (*cur)[501],(*nxt)[501];
    cur=dp1;
    nxt=dp2;
    cur[a][b]=1;
    for(int i=m;i<n;i++){
        memset(nxt,0,sizeof(dp1));
        rep(j,n+1)rep(k,n+1){
            if(!cur[j][k])continue;
            long long x=cur[j][k];
            if(2<=j)
                (nxt[j-2][k+2]+=x*c[j][2]%MOD)%=MOD;
            if(1<=j&&1<=k)
                (nxt[j-1][k]+=x*j%MOD*k%MOD)%=MOD;
            if(2<=k)
                (nxt[j][k-2]+=x*c[k][2]%MOD)%=MOD;
        }
        swap(cur,nxt);
    }
    cout<<cur[0][0]<<endl;
    return 0;
}
