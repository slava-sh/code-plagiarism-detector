// Enjoy your stay.

#include <bits/stdc++.h>

#define long long long
#define LOOPVAR_TYPE long

#define all(x) (x).begin(), (x).end()
#define sz(x) ((LOOPVAR_TYPE)(x).size())
#define foreach(it, X) for(__typeof((X).begin()) it = (X).begin(); it != (X).end(); it++)
#define GET_MACRO(_1, _2, _3, NAME, ...) NAME
#define _rep(i, n) _rep2(i, 0, n)
#define _rep2(i, a, b) for(LOOPVAR_TYPE i = (LOOPVAR_TYPE)(a); i < (LOOPVAR_TYPE)(b); i++)
#define rep(...) GET_MACRO(__VA_ARGS__, _rep2, _rep)(__VA_ARGS__)

#define fir first
#define sec second
#define mp make_pair
#define mt make_tuple
#define pb push_back

const double EPS = 1e-9;
const double PI = acos(-1.0);
const long INF = 1070000000LL;
const long MOD = 1000000007LL;

using namespace std;

typedef istringstream iss;
typedef stringstream sst;
typedef pair<LOOPVAR_TYPE, LOOPVAR_TYPE> pi;
typedef vector<LOOPVAR_TYPE> vi;

long inv[1000010];
void getinv(long n){
	inv[1]=1;
	rep(i,2,n+1)inv[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
}

long n,k,a[100010];
long nCr[100010];
long nCr2[100010];
long sum[100010];
long pw10[100010];

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	
	getinv(1000009);
	string str;
	cin>>n>>k>>str;
	rep(i,n){
		a[i] = str[i] - '0';
	}
	if(k == 0){
		long ans = 0;
		long pw10 = 1;
		for(int i = n-1; i>=0; i--){
			ans += a[i] * pw10 % MOD;
			pw10 = pw10 * 10 % MOD;
		}
		cout<<ans%MOD<<endl;
		return 0;
	}
	reverse(a,a+n);

	nCr[k-1] = 1;
	rep(i,k-1,n){
		nCr[i+1] = nCr[i] * (i+1) % MOD * inv[i-k+2] % MOD;
	}
	nCr2[k] = 1;
	rep(i,k,n){
		nCr2[i+1] = nCr2[i] * (i+1) % MOD * inv[i-k+1] % MOD;
	}
	pw10[0] = 1;
	rep(i,n){
		pw10[i+1] = pw10[i] * 10 % MOD;
	}
	sum[0] = 0;
	rep(i,n-1){
		sum[i+1] = (sum[i] + nCr[n-2-i] * pw10[i] % MOD) % MOD;
	}
	long ans = 0;
	rep(i,n){
		long subSum = sum[i];
		long last = pw10[i] * nCr2[n-1-i] % MOD;
		long mul = (subSum + last) % MOD;
		//cout<<i<<":"<<a[i]<<" "<<subSum<<" "<<last<<endl;
		ans += a[i] * mul % MOD;
	}
	cout<<ans%MOD<<endl;
}
