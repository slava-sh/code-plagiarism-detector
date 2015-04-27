#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
using namespace std;
typedef long long ll;

const int N = 505;

int c[N], mod;
char s[N];
ll C[N][N], f[N], F[N];
int d[N/2][N][N];

int dp(int k, int n1, int n2){
    //cout<<"?"<<k<<' '<<n1<<' '<<n2<<endl;
    if(k==0){
        if(n1==0 && n2==0) return 1;
        return 0;
    }
    if(d[k/2][n1][n2]==-1){
        ll res = 0;
        if(n1==0){
            if(k*2==n2) res = F[n2];
        }else
        if(k>1){
            ///ll, =
            if(n1>=2) res += 1LL*(n1-1)*dp(k-2, n1-2, n2);
            ///ll, !=
            if(n1>=3 && n2+2<N) res += C[n1-1][2]*2%mod*dp(k-2,n1-3,n2+2);
            ///lr
            if(n1>=2 && n2>=1) res += 1LL*(n1-1)*n2*2%mod*dp(k-2,n1-2,n2);
            ///rr
            if(n1>=1 && n2>=2) res += C[n2][2]*2%mod*dp(k-2,n1-1,n2-2);
            res%=mod;
            res = res*C[k][2]%mod;
        }
        d[k/2][n1][n2] = res;
        //cout<<"?"<<k<<' '<<n1<<' '<<n2<<" = "<<res<<endl;
    }
    
    return d[k/2][n1][n2];
}

ll ANS;
void go(int i, int n){
    if(i==n){
        for(int i=0;i<n;++i) if(c[i]!=2) return ;
        ++ANS;
        return ;
    }
    
    for(int j1=0;j1<n;++j1)
    for(int j2=j1+1;j2<n;++j2) if(c[j1]<2 && c[j2]<2){
        ++c[j1];
        ++c[j2];
        go(i+1, n);
        --c[j1];
        --c[j2];
    }
}

int main(){
    //freopen("input.txt","r",stdin);// freopen("output.txt","w",stdout);
    
    
    int n, m;
    
    scanf("%d%d%d",&n,&m,&mod);
    
    for(int i=0;i<N;++i) C[i][0] = 1;
    for(int i=1;i<N;++i)
    for(int j=1;j<N;++j) C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
    
    f[0] = 1;
    for(int i=1;i<N;++i) f[i]=f[i-1]*i%mod;
    
    F[0] = 1;
    for(int i=2;i<N;i+=2) F[i]=F[i-2]*C[i][2]%mod;
    
    
    ll ans = 1;
    for(int i=0;i<m;++i){
        scanf("%s",&s);
        int k = 0;
        for(int j=0;j<n;++j) if(s[j]=='1') ++c[j], ++k;
        if(k!=2) ans=0;
    }
    
    //go(m,n);
    //cout<<"!"<<ANS<<endl;
    
    int n1 = 0, n2 = 0, n3 = 0;
    for(int i=0;i<n;++i)
    if(c[i]>2) ans=0;
    else if(c[i]==0) ++n1; else if(c[i]==1) ++n2;
    
    int m2 = n-m;
    memset(d, -1, sizeof d);
    ans = ans*dp(m2, n1, n2)%mod;
    
    cout<<ans<<endl;
    
    return 0;
}

