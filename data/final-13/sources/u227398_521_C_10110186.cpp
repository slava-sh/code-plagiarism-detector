#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cstdlib>
#include<string>
#include<bitset>
#define INF 1000000000
#define fi first
#define se second
#define P 1000000007
#define debug(x) cout<<#x<<"="<<x<<endl
#define MP(x,y) make_pair(x,y)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
LL ksm(LL a,LL b)
{
    LL c=1,d=a;
    while(b)
    {
        if(b&1)
            c=(c*d)%P;
        d=(d*d)%P;
        b>>=1;
    }
    return c;
}
LL c[100005],c2[100005],s[100005],mi[100005];

char t[100005];
int main()
{
    int n,k,i,j;
    LL cf=1,ans=0,t1;
    cin>>n>>k;
    scanf("%s",t+1);
    mi[0]=1;
    for(i=1;i<=n;i++)
        mi[i]=mi[i-1]*10%P;
    c[k]=1;
    for(i=k+1;i<=n;i++)
        c[i]=c[i-1]*i%P*ksm(i-k,P-2)%P;
    c2[k-1]=1;
    for(i=k;i<n-1;i++)
        c2[i]=c2[i-1]*i%P*ksm(i-(k-1),P-2)%P;
    //debug(c2[1]);
    for(i=n-2;i>=k-1;i--)
    {
        s[i]=(s[i+1]+cf*c2[i])%P;
        cf=(cf*10)%P;
    }
    //debug(s[1]);
    //debug(s[0]);
    for(i=1;i<=n;i++)
    {
        j=max(i-1,k-1);
        t1=t[i]-48;
        if(i!=n)
            ans=(ans+s[j]*t1)%P;
        //debug(ans);
        if(i-1>=k)
            ans=(ans+c[i-1]*t1%P*mi[n-i])%P;
        //debug(ans);
    }
    cout<<ans<<endl;
    return 0;
}
// davidlee1999WTK 2015/
// srO myk Orz
//ios::sync_with_stdio(false);

