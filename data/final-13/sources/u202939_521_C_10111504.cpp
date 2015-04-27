#include<cstdio>
#define N 100005
using namespace std;
const int P=1000000007;
int fac[N],inv[N],tmp,sum[N],ans,t,i,n,m,k;
char a[N];
inline int Pow(int a,int b)
{
  int res=1;
  for (;b;b>>=1,a=a*1ll*a%P) if (b&1) res=res*1ll*a%P;
  return res;
}
inline int C(int n,int m)
{
  if (m<0) return 0;
  if (n<m) return 0;
  return fac[n]*1ll*inv[m]%P*1ll*inv[n-m]%P;
}
int main()
{
  scanf("%d%d",&n,&k);
  scanf("%s",a+1);
  for (i=fac[0]=1;i<=n;i++) fac[i]=fac[i-1]*1ll*i%P;
  inv[n]=Pow(fac[n],P-2);
  for (i=n-1;i>=0;i--) inv[i]=inv[i+1]*1ll*(i+1)%P;
  sum[0]=0;
  for (i=1;i<=n;i++)
    sum[i]=(sum[i-1]+a[i]-'0')%P;
  //for (P[1]=i=1;i<=n;i++) P[i]=P[i-1]*1ll*10%P;
  t=1;
  for (i=1;n-3-(i-1)>=k-2;i++)
  {
    //n-i+1  get
    tmp=sum[n-i];
    tmp=tmp*1ll*C(n-2-(i-1),k-1)%P;
    tmp=tmp*1ll*t%P;
    ans=(ans+tmp)%P;
    tmp=sum[n-i+1]-sum[n-i];
    tmp=tmp*1ll*C(n-1-(i-1),k)%P;
    tmp=tmp*1ll*t%P;
    ans=(ans+tmp)%P;
    t=t*1ll*10%P;
  }
  printf("%d\n",ans);
}
