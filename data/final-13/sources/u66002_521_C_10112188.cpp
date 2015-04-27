#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <bitset>
#include <stack>
#include <string>
#include <map>
#include <assert.h>


#define abs(x) ((x)>=0?(x):-(x))
#define i64 long long
#define u32 unsigned int
#define u64 unsigned long long
#define clr(x,y) memset(x,y,sizeof(x))
#define pb(x) push_back(x)
#define SZ(x) x.size()
#define PI acos(-1.0)
#define sqr(x) ((x)*(x))
#define MP(x,y) make_pair(x,y)
#define EPS 1e-11



#define pii pair<int,int>
#define FFF freopen("test","r",stdin)
#define all(a) a.begin(),a.end()

using namespace std;


void output(i64 x)
{
    if(x<0) putchar('-'),x=-x;
    if(x==0)
    {
        putchar('0');
        return;
    }
    int a[20],num=0;
    while(x) a[++num]=x%10,x/=10;
    while(num>0) putchar('0'+a[num--]);
}

inline i64 myInt()
{
    char c=getchar();
    while(!isdigit(c)&&c!='-') c=getchar();
    int flag=1;
    if(c=='-') flag=-1,c=getchar();
    i64 x=0;
    while(isdigit(c))
    {
        x=(x*10)+(c-'0');
        c=getchar();
    }
    if(-1==flag) return -x;
    return x;
}

const int mod=1000000007;
const int N=100005;


char s[N];
int a[N];

int n,m;

i64 p[N];

i64 exGcd(i64 a,i64 b,i64 &x,i64 &y)
{
    i64 r,t;
    if(b==0)
   {
       x=1;
       y=0;
       return a;
   }
   r=exGcd(b,a%b,x,y);
   t=x;
   x=y;
   y=t-a/b*y;
   return r;
}

i64 reverse(i64 a,i64 b)
{
    i64 x,y;
    exGcd(a,b,x,y);
    if(x<0) x+=mod;
    return x;
}



i64 C(int n,int m)
{
    if(m>n) return 0;
    if(m==n||m==0) return 1;
    return p[n]*reverse(p[m]*p[n-m]%mod,mod)%mod;
}

i64 A[N],B[N];
i64 po[N];

i64 f[N];

i64 sum;
int pp[N];

void dfs(int cur,int num)
{
    if(num==m)
    {
        i64 tmp=0;
        int cur=0;
        for(int i=1;i<=n;i++)
        {
            tmp=tmp*10+a[i];
            tmp%=mod;
            if(i==pp[cur])
            {
                sum+=tmp;
                sum%=mod;
                tmp=0;
                cur++;
            }
        }
        sum+=tmp;
        sum%=mod;
        return;
    }
    if(cur==n) return;

    dfs(cur+1,num);
    pp[num]=cur;
    dfs(cur+1,num+1);
}

void BAOLI()
{
    dfs(1,0);

    printf("%d\n",(i64)sum);
}

int main()
{
    n=myInt();
    m=myInt();
    scanf("%s",s+1);
    for(int i=1;i<=n;i++)
    {
        a[i]=s[i]-'0';
    }

 //   BAOLI();


    p[0]=1;
    po[0]=1;
    for(int i=1;i<N;i++)
    {
        p[i]=p[i-1]*i%mod;
        po[i]=po[i-1]*10%mod;
    }



    if(m==0)
    {
        i64 ans=0;
        for(int i=1;i<=n;i++) ans=(ans*10+a[i])%mod;
        printf("%d\n",(int)ans);
        return 0;
    }
    if(m==1)
    {
        for(int i=1;i<=n;i++)
        {
            A[i]=(A[i-1]*10+a[i])%mod;
        }
        for(int i=n;i>=1;i--)
        {
            B[i]=(B[i+1]+a[i]*po[n-i])%mod;
        }
        i64 ans=0;
        for(int i=1;i<n;i++)
        {
            ans+=A[i]+B[i+1];
            ans%=mod;
        }
        printf("%d\n",(int)ans);
        return 0;
    }

    for(int i=0;i<=n;i++)
    {
        if(i) f[i]=f[i-1];
        f[i]+=C(n-2-i,m-1)*po[i]%mod;
        f[i]%=mod;
    }

    i64 ans=0;
    for(int i=1;i<=n;i++)
    {
        ans+=a[1]*po[i-1]%mod*C(n-i-1,m-1)%mod;
        ans%=mod;
    }
    ans+=a[n]*C(n-1,m);
    ans%=mod;
    for(int i=2;i<n;i++)
    {
        i64 tmp=f[n-1-i]*a[i]%mod+C(i-1,m)*a[i]%mod*po[n-i]%mod;
        tmp%=mod;

        ans+=tmp;
        ans%=mod;
    }
    printf("%d\n",(int)ans);

}
/*

6 4
123466
*/
