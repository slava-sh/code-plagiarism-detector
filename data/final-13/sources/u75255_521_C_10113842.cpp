#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
#include<assert.h>
using namespace std;
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define REP(i,n) FOR(i,0,(n)-1)
#define RI(i,n) FOR(i,1,n)
#define pb push_back
#define mp make_pair
#define st first
#define nd second
#define mini(a,b) a=min(a,b)
#define maxi(a,b) a=max(a,b)
bool debug;
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
const int inf = 1e9 + 5;
const int nax = 1e5 + 5;
const int mod = 1e9 + 7;

int n,k;
ll silnia[nax], odwr[nax], suma_plus[nax], bez_plus[nax];
char s[nax];

ll pot(ll a, ll b) {
	ll res = 1;
	while (b) {
		if (b&1)
			res = (res*a)%mod;
		a = (a*a)%mod;
		b /= 2;
	}
	return res;
}

ll newton(int n, int k) {
	if (k > n) return 0;
	return (((silnia[n] * odwr[k])%mod)*odwr[n-k])%mod;
}

int main(int argc, char * argv[]) {
	debug = argc > 1;
	scanf("%d%d",&n,&k);
	scanf(" %s",s);
	
	silnia[0] = 1;
	FOR(i,1,n) silnia[i] = (silnia[i-1]*i)%mod;
	FOR(i,0,n) odwr[i] = pot(silnia[i],mod-2);
	ll pot = 1;
	FOR(dl,1,n) {
		bez_plus[dl] = (pot * newton(n-dl,k))%mod;
		suma_plus[dl] = (suma_plus[dl-1] + (pot * newton(n-dl-1,k-1)))%mod;
		pot *= 10;
		pot %= mod;
	}
	
	ll wyn = 0;
	REP(i,n) wyn = (wyn + ll(s[i]-'0')*(bez_plus[n-i] + suma_plus[n-i-1]))%mod;
	printf("%d\n",(int)wyn); 
	return 0;
}
