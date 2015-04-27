#include <cstdio>
#include <algorithm>
#define maxn 100005
#define mo 1000000007
using namespace std;

long long a[maxn],b[maxn],c,d,e,f[maxn],g[maxn],h,i,j,k,l,m,n,base[maxn],ans;
char s[maxn];

inline int C(int n,int m){return 1ll*g[n]*f[m]%mo*f[n-m]%mo;}

inline int ksm(int x,int y){
	int k=1;
	for(;y;y>>=1){
		if(y&1)k=1ll*k*x%mo;
		x=1ll*x*x%mo;
	}
	return k;
}

int main(){
	scanf("%I64d%I64d",&n,&m);
	scanf("%s",s+1);
	for(i=1;i<=n;i++)a[i]=s[i]-'0';
	if(m==0){
		ans=0;for(i=1;i<=n;i++)ans=(1ll*ans*10+a[i])%mo;
	}
	base[1]=1;
	for(i=2;i<=n;i++)base[i]=1ll*base[i-1]*10%mo;
	g[0]=1;
	for(i=1;i<=n;i++)g[i]=1ll*g[i-1]*i%mo;
	f[n]=ksm(g[n],mo-2);
	for(i=n-1;i>=0;i--)f[i]=1ll*f[i+1]*(i+1)%mo;
	for(i=1;i<=n-m;i++){
		b[i]=C(n-i-1,m-1);
		h=(h+1ll*base[i]*b[i]%mo)%mo;
	}
	for(i=1;i<=m+1;i++)ans=(ans+1ll*a[i]*h%mo)%mo;
	for(i=m+2;i<=n;i++){
		h=(h+1ll*(base[n-i+1]-base[n-i+2]+mo)*b[n-i+2]%mo)%mo;
		b[n-i+1]=(b[n-i+1]+b[n-i+2])%mo;
		ans=(ans+1ll*a[i]*h%mo)%mo;
	}
	printf("%I64d\n",ans);
	return 0;
}