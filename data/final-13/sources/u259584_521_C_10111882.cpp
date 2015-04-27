#include<cstdio>
#include<cstring>
#include<cctype>
#include<climits>
#include<iostream>
#include<algorithm>
using namespace std;

typedef long long LL;
static const int mod=(1e9)+7;

#define N 100010
int fac[N];

inline int ksm(int x,int y){
    int re=1,t=x;for(;y;y>>=1,t=(LL)t*t%mod)if(y&1)re=(LL)re*t%mod;return re;
}
inline int rev(int x){
    return ksm(x,mod-2);
}
inline int C(int n,int m){
    if(n<m)return 0;
    if(n==m)return 1;
    int re=fac[n];
    re=(LL)re*rev(fac[m])%mod;
    re=(LL)re*rev(fac[n-m])%mod;
    return re;
}

char s[N];
int a[N];
inline int get(int l,int r){if(l>r)return 0;else return a[r]-a[l-1];}

int main(){
    int n,k;scanf("%d%d",&n,&k);
    
    register int i,j;
    for(fac[0]=1,i=1;i<=n;++i)fac[i]=(LL)fac[i-1]*i%mod;
    
    scanf("%s",s+1);
    
    if(n==1){
        printf("%c",s[1]);
        return 0;
    }
    if(k==0){
        int re=0;
        for(i=1;i<=n;++i)re=((LL)re*10+s[i]-'0')%mod;
        printf("%d",re);
        return 0;
    }
    
    for(i=1;i<=n;++i)a[i]=s[i]-'0';
    for(i=2;i<=n;++i)a[i]+=a[i-1];
    
    int re=0,now;
    for(int l=1;n-l-1>=k-1;++l){
        now=C(n-l-1,k-1);
        now=(LL)now*get(2,n-l)%mod;
        now=(LL)now*ksm(10,l-1)%mod;
        re=(re+now)%mod;
    }
    
    for(int l=1;n+1-l>1;++l){
        now=C(n-l,k);
        now=(LL)now*get(n-l+1,n-l+1)%mod;
        now=(LL)now*ksm(10,l-1)%mod;
        re=(re+now)%mod;
    }
    
    for(int l=1;l<=n-1;++l){
        now=C(n-l-1,k-1);
        now=(LL)now*get(1,1)%mod;
        now=(LL)now*ksm(10,l-1)%mod;
        re=(re+now)%mod;
    }
    
    printf("%d",re);
    
    return 0;
}