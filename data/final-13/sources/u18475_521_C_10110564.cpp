#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int p=1e9+7;
ll pm(ll a,ll n=p-2){
	ll r=1;
	for(;n;n>>=1,a=a*a%p)if(n&1)r=r*a%p;
	return r;
}
char s[102400];
int n,k;
ll f[102400],r[102400];
ll C(int n,int m){
	return m<=n?f[n]*r[m]%p*r[n-m]%p:0;
}
int main(){
	scanf("%d%d ",&n,&k);
	for(int j=n-1;j>=0;--j)scanf("%c",s+j);
	ll ans=0,s=0,d=1;
	f[0]=r[0]=1;
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]*i%p;
		r[i]=pm(f[i]);
	}
	for(int i=0;i<n;++i,d=d*10%p){
		ans=(ans+(C(n-i-1,k)*d+s)%p*(::s[i]-'0'))%p;
		s=(s+d*C(n-i-2,k-1))%p;
	}
	printf("%d\n", (int)ans);
}
