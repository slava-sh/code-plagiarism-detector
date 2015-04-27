#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

const int N=(int)1e5+100,M=N*6,mo=(int)1e9+7;

int n,k;

int inv[N],fac[N],ifac[N];

ll pw[N],f[N];

ll C(int n,int m){
	if(n<0||m>n) return 0;
	return 1LL*fac[n]*ifac[n-m]%mo*ifac[m]%mo;
}

char s[N];

int main(){
	scanf("%d%d",&n,&k);
	inv[1]=1;
	for(int i=2;i<=n+5;i++) inv[i]=ll(mo-mo/i)*inv[mo%i]%mo;
	fac[0]=ifac[0]=1;
	for(int i=1;i<=n+5;i++) fac[i]=1LL*fac[i-1]*i%mo,ifac[i]=1LL*ifac[i-1]*inv[i]%mo;
	pw[0]=1;
	for(int i=1;i<=n+5;i++) pw[i]=pw[i-1]*10LL%mo;
	for(int i=0;i<=n+5;i++)
		f[i]=((i?f[i-1]:0)+pw[i]*C(n-2-i,k-1))%mo;
	scanf("%s",s+1);
	ll ans=0;
	for(int i=1;i<=n;i++)
		ans=(ans+(f[n-i-1]+pw[n-i]*C(i-1,k))%mo*(s[i]-'0'))%mo;
	printf("%d\n",(int)ans);
}
