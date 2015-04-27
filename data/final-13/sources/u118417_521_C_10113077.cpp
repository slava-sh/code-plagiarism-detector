#include <bits/stdc++.h>
using namespace std;
#define fo(i,a,b) for (int i = (a); i < (b); i++)
#define MOD 1000000007LL
#define N 123456
#define mp make_pair
typedef long long ll;

int n, k; char str[N];
ll poww10[N] = {1}, fct[N] = {1}, spc[N], spc2[N], fnl[N], fnl2[N], ans;
pair<ll,ll> finv(ll a, ll b) {
	if (b==0) return mp(1, 0);
	ll qt = a/b, r = a%b;
	pair<ll,ll> tmp = finv(b, r);
	return mp(tmp.second, ((tmp.first - qt*tmp.second)%MOD + MOD)%MOD);
}
int main() {
	scanf("%d %d %s", &n, &k, str);
	fo(i,1,N) poww10[i] = (10*poww10[i-1])%MOD;
	fo(i,1,N) fct[i] = (i*fct[i-1])%MOD; 
	if (k) fo(i,k-1,n) spc[i] = ((((fct[i] * finv(fct[k-1], MOD).first)%MOD)* finv(fct[i-k+1], MOD).first)%MOD);
	fo(i,k,n) spc2[i] = ((((fct[i] * finv(fct[k], MOD).first)%MOD)* finv(fct[i-k], MOD).first)%MOD);
	if (k) fo(i,k,n) fnl[i] = (spc[i-1] * poww10[n-i-1])%MOD;
	fo(i,k,n) fnl2[i] = (spc2[i] * poww10[n-i-1])%MOD;
	ll tmp = 0;
	if (k) fo(i,k,n) tmp = (tmp + fnl[i])%MOD;
	tmp = (tmp + fnl2[0])%MOD;
	fo(i,0,n) {
		//printf("%lld\n", tmp);
		ans = (ans + tmp*(str[i]-'0'))%MOD;
		if (k) tmp = (tmp - fnl[i+1] + MOD)%MOD;
		if (i != n-1) tmp = (tmp - fnl2[i] + fnl2[i+1] + MOD)%MOD;
	}
	printf("%lld\n", ans);

	return 0;
}