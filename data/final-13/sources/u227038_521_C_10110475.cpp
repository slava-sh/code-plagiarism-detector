#include<cstdio>
#include<algorithm>
using namespace std;
#define mo 1000000007
#define ln printf("\n")
typedef long long LL;
const int NN=101111;
int a[NN],n,K;
LL f[NN],g[NN],fac[NN],ten[NN];
LL ksm(LL a,LL b)
{
	LL res=1;
	for (;b;b>>=1,a=a*a%mo) if (b&1) res=res*a%mo;
	return res;
}
LL C(int n,int m)
{
	if (n<0||m<0) return 0;
	return fac[n]*ksm(fac[m]*fac[n-m]%mo,mo-2)%mo;
}
int main()
{
	//freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	scanf("%d%d\n",&n,&K);
	int i;
	for (i=1;i<=n;i++)
	{
		char ch=getchar();
		a[i]=ch-'0';
	}
	fac[0]=1;
	for (i=1;i<=100005;i++) fac[i]=fac[i-1]*i%mo;
	ten[0]=1;
	for (i=1;i<=100005;i++) ten[i]=ten[i-1]*10%mo;
	for (i=1;i+K<=n;i++) f[i]=C(n-i-1,K-1);
	for (i=1;i+K<=n;i++) g[i]=(g[i-1]+f[i]*ten[i-1])%mo;
	//for (i=1;i<=4;i++) printf("%I64d ",g[i]);ln;
	LL ans=0;
	for (i=1;i<=n;i++)
	{
		int t=min(n-i,n-K);
		//printf("%d %d\n",i,t);
		ans=(ans+a[i]*g[t])%mo;
		//printf("ans=%I64d\n",ans);
		if (n-i+1<=n-K) ans=(ans+a[i]*C(i-1,K)%mo*ten[n-i])%mo;
		//printf("ans=%I64d\n",ans);
	}
	printf("%I64d\n",ans);
	return 0;
}
