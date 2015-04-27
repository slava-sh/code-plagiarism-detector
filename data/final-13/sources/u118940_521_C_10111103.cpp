#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#define vi vector<int>
#define pii pair<int,int>
#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define FOR(i,l,r) for(int i=(l);i<=(r);i++)
#define dbg(x) cout<<#x<<" = "<<x<<endl
#define bg(a,n) for(int i=1;i<=(n);printf("%d%s",a[i],i==n?"\n":" "),i++)
using namespace std;
typedef long long LL;
const LL MOD=1000000007;

int n,k;
char s[100002];
LL fact[100001],mi10[100001];

int sum;
LL ans;

LL ksm(LL a,LL n,LL p) {
	LL ret=1;
	for (a%=p;n;n>>=1) {
		if (n&1) (ret*=a)%=p;
		(a*=a)%=p;
	}
	return ret;
}
LL inv(LL a) {
	return ksm(a,MOD-2,MOD);
}
LL C(int n,int k) {
	return (fact[n]*inv(fact[n-k]))%MOD*inv(fact[k])%MOD;
}
int main() {
	fact[0]=1; for (int i=1;i<=100000;i++) fact[i]=fact[i-1]*i%MOD;
	mi10[0]=1; for (int i=1;i<=100000;i++) mi10[i]=mi10[i-1]*10%MOD;

	scanf("%d%d%s",&n,&k,s+1);
	for (int i=1;s[i];i++) sum+=s[i]-'0'; sum-=s[n]-'0';

	if (k)
	for (int i=n-1;i>=k;i--) {
		(ans+=sum*mi10[n-i-1]%MOD*C(i-1,k-1))%=MOD;
		sum-=s[i]-'0';
	}

	for (int i=n;i>k;i--) {
		(ans+=(s[i]-'0')*mi10[n-i]%MOD*C(i-1,k))%=MOD;
	}
	cout<<ans<<endl;
	return 0;
}

