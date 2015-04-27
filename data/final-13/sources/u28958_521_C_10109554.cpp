#include <bits/stdc++.h>
using namespace std;

#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define pb push_back
#define f(i,x,y) for(int i = x; i<y; i++ )
#define FORV(it,A) for(vector<int>::iterator it = A.begin(); it!= A.end(); it++)
#define FORS(it,A) for(set<int>::iterator it = A.begin(); it!= A.end(); it++)
#define quad(x) (x) * (x)
#define mp make_pair
#define clr(x, y) memset(x, y, sizeof x)
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef long long ll;
typedef long double ld;
#define N 110000
#define mod 1000000007
ll fat[N];


ll exp (ll a, ll b){
	if (b == 0) return 1;
	ll ret = exp(a, b/2);
	ret *= ret;
	ret %= mod;
	if (b%2 == 1) ret = (ret*a)%mod;
	return ret;
}

ll inv (ll a){
	return exp(a, mod-2);
}


ll B(ll a, ll b){
	if (b > a) return 0;
	if (b < 0) return 0;
	ll ret = fat[a];
	ret *= inv(fat[b]);
	ret %= mod;
	ret *= inv(fat[a-b]);
	ret %= mod;
	return ret;
}

int n, k;
string s;
int main (){
	fat[0] = 1;
	for (ll i = 1; i < N; i++){
		fat[i] = (fat[i-1]*i)%mod;
	}
	cin >> n >> k;
	cin >> s;
	int d = 2;
	ll mul = 1;
	ll C = 0;
	ll ans = 0;
	ans = (ll)(s[n-1]-'0')*B(n-1, k);
	for (int i = n-2; i >= 0; i--){
		C += (mul*B(i, k-1))%mod;
		C %= mod;
		ans += (ll)(s[i]-'0')*(C);
		ans %= mod;
		mul *= 10LL;
		mul %= mod;
		ll aux = ((ll)(s[i]-'0')*B(i, k));
		aux %= mod;
		aux *= mul; aux %= mod;
		ans += aux;
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}






