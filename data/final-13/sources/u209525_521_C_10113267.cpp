#include <bits/stdc++.h>

#define rep(i,j,k) for (int i=j;i<=k;++i)
#define dep(i,j,k) for (int i=j;i>=k;--i)

using namespace std;

typedef long long int64;

const int N=(int)1e5,mod=(int)1e9+7;

int n,k;
char s[N+10];
int64 ans,po[N+10],fac[N+10],inv[N+10],sum[N+10];

inline int64 qpow(int64 a,int64 b){
	int64 ans=1;
	for (;b;b>>=1,a=(int64)a*a%mod)
		if (b&1) ans=(int64)ans*a%mod;
	return ans;
}

inline int64 C(int n,int m){
	if (m>n) return 0;
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}

void initialize(){
	fac[0]=1;
	rep(i,1,n) fac[i]=fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	dep(i,n-1,0) inv[i]=(int64)inv[i+1]*(i+1)%mod;
	po[0]=1;
	rep(i,1,n) po[i]=po[i-1]*10%mod;
	sum[0]=C(n-2,k-1);
	rep(i,1,n) sum[i]=(sum[i-1]+(int64)po[i]*C(n-2-i,k-1)%mod)%mod;
}

int main(){
	scanf("%d%d%s",&n,&k,s+1);
	initialize();
	rep(i,1,n){
		ans=(ans+(int64)(s[i]-'0')*sum[n-i-1]%mod)%mod;
		int t=(int64)(s[i]-'0')*C(i-1,k)%mod*po[n-i]%mod;
		ans=(ans+t)%mod;
	}
	printf("%I64d\n",ans);
	return 0;
}
