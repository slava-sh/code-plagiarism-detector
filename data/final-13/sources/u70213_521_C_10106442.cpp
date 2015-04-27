#include<bits/stdc++.h>
#define int64 long long
#define mk make_pair
#define pb push_back
#define fi first
#define se second
#define SZ(x) ((int)x.size())
#define sqr(x) (x)*(x)
#define rep(i,x,y) for(int i=x;i<=y;++i)
#define VI vector<int>
#define VS vector<string>
#define PII pair<int,int>
#define PDD pair<double,double>
#define VPII vector< PII >
#define N 120000
using namespace std;
const double pi=acos(-1);
const int mo=1e9+7;
int Pow10[N],ni_fac[N],fac[N],sum[N],n,K;
char c[N];
int Pow(int x,int y){
	int res=1;
	while(y){
		if(y&1)res=1ll*res*x%mo;
		y/=2;
		x=1ll*x*x%mo;
	}
	return res;
}
int C(int n,int m){
	if(m>n)return 0;
	return 1ll*fac[n]*ni_fac[m]%mo*ni_fac[n-m]%mo;
}
int main(){
	scanf("%d%d",&n,&K);
	scanf("%s",c+1);
	rep(i,1,n){
		sum[i]=sum[i-1]+(c[i]-'0');
	}
	Pow10[0]=1;
	rep(i,1,n)Pow10[i]=1ll*Pow10[i-1]*10%mo;
	fac[0]=1;
	rep(i,1,n)fac[i]=1ll*fac[i-1]*i%mo;
	ni_fac[n]=Pow(fac[n],mo-2);
	for(int i=n-1;i>=0;--i)ni_fac[i]=1ll*ni_fac[i+1]*(i+1)%mo;
	int ans=0;
	for(int i=0;i<n;++i){
		ans=(ans+1ll*(c[n-i]-'0')*Pow10[i]%mo*C(n-1-i,K))%mo;
		ans=(ans+1ll*sum[n-i-1]*Pow10[i]%mo*C(n-2-i,K-1))%mo;
	}
	printf("%d\n",ans);
}
