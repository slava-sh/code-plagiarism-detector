#define N (1<<17)
#define M 1000000007
#define ll long long
#include <bits/stdc++.h>
using namespace std;

int n,k;
char s[N];
ll f[N],g[N],p[N];

ll quickpow(ll x,ll y)
{
	ll cur=x,res=1;
	for(;y;y>>=1,cur=cur*cur%M)
		if(y&1) res=res*cur%M;
	return res;
}

ll inv(ll x)
{
	return quickpow(x,M-2);
}

void calc(int k)
{
	f[k]=1;
	for(ll i=k+1;i<=n;i++)
		f[i]=f[i-1]*i%M*inv(i-k)%M;
}

void init()
{
	g[0]=1;
	for(ll i=1;i<=n;i++)
		g[i]=g[i-1]*10%M;

}

int main()
{
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		s[i]-=48;
	if(k==0)
	{
		ll res=0;
		for(int i=0;i<n;i++)
			res=res*10+s[i],res%=M;
		cout<<res<<endl;
	}
	else
	{
		init();
		calc(k);
		ll res=0;
		for(int i=k;i<n;i++)
			res+=g[n-i-1]*f[i]%M*s[i]%M,res%=M;

		calc(k-1);
		for(int i=n-2;i>=k-1;i--)
			p[i]=p[i+1]+g[n-i-2]*f[i]%M,p[i]%=M;

		for(int i=0;i<n-1;i++)
			res+=(ll)s[i]*p[max(k-1,i)]%M,res%=M;

		cout<<res<<endl;
	}
	return 0;
}
