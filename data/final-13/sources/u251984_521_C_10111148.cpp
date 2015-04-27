#include <bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a;i<b;i++)
#define mp make_pair
#define pb push_back
#define mod 1000000007
#define eps 0.00000001
#define maxn 1003

long long pre[100005],n,k,ck[100005],ck1[100005],res,cur,tmp;
string s;

long long inv(long long x)
{
    long long k0=1,k1=0,a0=0,a1=1,r0=mod,r1=x,q,tmpk,tmpa,tmpr;
    while(1)
    {
        q=r0/r1;
        tmpk=k1;tmpa=a1;tmpr=r1;
        k1=k0-q*k1;
        a1=a0-q*a1;
        r1=r0%r1;
        k0=tmpk;a0=tmpa;r0=tmpr;
        if(r1==0) return (mod+a0%mod)%mod;
    }
}

int main()
{
    //freopen("input.txt","r",stdin);
    cin>>n>>k>>s;
    pre[0]=1;
    For(i,1,n-k)
    {
        pre[i]=pre[i-1]*10;
        pre[i]%=mod;
    }
    res=0;
    if(k==0)
    {
        For(i,0,n)
        {
            res+=pre[i]*(s[n-1-i]-'0');
            res%=mod;
        }
        cout<<res;
        return 0;
    }
    //cout<<inv(1);return 0;
    memset(ck,0,sizeof(ck));
    memset(ck1,0,sizeof(ck1));
    ck[k]=ck1[k-1]=1;
    For(i,k+1,n)
    {
        cur=inv(i-k);
        ck[i]=ck[i-1]*i;
        ck[i]%=mod;
        ck[i]*=cur;
        ck[i]%=mod;
        ck1[i-1]=ck1[i-2]*(i-1);
        ck1[i-1]%=mod;
        ck1[i-1]*=cur;
        ck1[i-1]%=mod;
    }
    cur=0;
    //cout<<ck1[1]<<endl;
    For(i,0,n)
    {
        tmp=pre[i]*ck[n-1-i];
        tmp%=mod;
        tmp+=cur;
        tmp%=mod;
        res+=tmp*(s[n-1-i]-'0');
        res%=mod;
        tmp=pre[i]*ck1[n-2-i];
        tmp%=mod;
        cur+=tmp;
        cur%=mod;
        //cout<<cur<<endl;
    }
    cout<<res;
    return 0;
}
