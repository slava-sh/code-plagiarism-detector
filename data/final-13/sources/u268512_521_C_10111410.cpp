#include <bits/stdc++.h>
#define pb push_back
#define sqr(x) (x)*(x)
#define sz(a) int(a.size())
#define reset(a,b) memset(a,b,sizeof(a))
#define oo 1000000007

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

const int maxn=100007;

ll fr[maxn], ifr[maxn];
int n,a[maxn],k;
char s[maxn];

ll mypow(ll base, ll n){
    if(n==0) return 1;
    ll t=mypow(base,n/2);
    t=t*t%oo;
    if(n&1) return t*base%oo;
    return t;
}

ll com(int n, int k){
    if(k>n) return 0;
    return fr[n]*ifr[k]%oo*ifr[n-k]%oo;
}

int main(){
//    freopen("input.txt","r",stdin);
    fr[0]=1; ifr[0]=1;
    for(int i=1; i<=100001; ++i){
        fr[i]=fr[i-1]*i%oo;
        ifr[i]=mypow(fr[i],oo-2);
    }
    scanf("%d%d",&n,&k);
    scanf("%s",s+1);
    for(int i=1; i<=n; ++i) a[i]=s[i]-'0';

    ll sum = 0, res = 0, p10=1, t=n-1;
    for(int i=n; i>=1; --i){
        ll x=a[i];
        if(k>0){
            res = (res + x*sum)%oo;
            sum = (sum + p10*com(--t,k-1))%oo;
        }
        res = (res + x*p10%oo*com(i-1,k))%oo;
        p10=p10*10%oo;
    }
    cout<<res<<endl;
}
