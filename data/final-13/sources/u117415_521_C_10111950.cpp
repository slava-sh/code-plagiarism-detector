#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#define MASK 1000000007
#define MAXN 100005
long long ans=0,c1[MAXN],c2[MAXN],sum[MAXN];
int n,k;
char str[MAXN];
long long mul_inv(long long a)
{
    long long b=MASK,b0=b,t,q,x0=0,x1=1;
    if(b==1) return 1;
    while(a>1)
    {
        q=a/b;
        t=b,b=a%b,a=t;
        t=x0,x0=x1-q*x0,x1=t;
    }
    if(x1<0) x1+=b0;
    return x1;
}
inline long long getsum(int x){return x>=0?sum[x]:0;}
int main()
{
    scanf("%d%d%s",&n,&k,str);
    c1[k-1]=c2[k]=1;
    for(int i=k;i<MAXN;i++) c1[i]=((c1[i-1]*i)%MASK*mul_inv(i-k+1))%MASK;
    for(int i=k+1;i<MAXN;i++) c2[i]=((c2[i-1]*i)%MASK*mul_inv(i-k))%MASK;
//  for(int i=0;i<100;i++) printf("%lld ",c2[i]);
//  printf("\n");
    sum[0]=str[0]-'0';
    for(int i=1;i<n;i++) sum[i]=sum[i-1]+str[i]-'0';
    long long off=1;
    for(int i=0;i<n;i++)
    {
        ans=(ans+(((getsum(n-i-2)*c1[n-i-2])%MASK+((str[n-i-1]-'0')*c2[n-i-1])%MASK)*off)%MASK)%MASK;
        off=(off*10)%MASK;
    }
    printf("%I64d\n",ans);
    return 0;
}
