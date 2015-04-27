#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, m, mod, C[2000][2000];
ll dp[510][510];
string in[500];

const int N = 4;
bool good(int ptn[100][100]){
	rep(i, N){
		int a = 0, b = 0;
		rep(j, N) a += ptn[i][j], b += ptn[j][i];
		if(a != 2 || b != 2) return 0;
	}
	rep(i, N) rep(j, N) cerr<<ptn[i][j]<<(j==2?"\n":" "); cerr<<endl;
	
	return 1;
}

int main(){
	#if 0
	int ptn[100][100], cnt = 0;
	rep(i, 1 << N*N){
		rep(j, N*N) ptn[j / N][j % N] = (i >> j & 1);
		if(good(ptn)) cnt++;
	}
	dbg(cnt);
	exit(0);
	#endif
	
	cin >> n >> m >> mod;
	int rem[500] = {};
	
	rep(i, 2000) rep(j, i+1) C[i][j] = j==0||j==i ? 1 : (C[i-1][j] + C[i-1][j-1]) % mod;
	
	rep(i, n) rem[i] = 2;
	rep(i, m){
		cin >> in[i];
		rep(j, n) rem[j] -= in[i][j] - '0';
	}
	rep(i, n){
		if(rem[i] < 0 || rem[i] > 2){
			cout << 0 << endl;
			return 0;
		}
		//cerr<<rem[i]<<(i==n-1?"\n":" ");
	}
	
	int sum = 0;
	dp[0][0] = 1;
	rep(i, n){
		rep(j, n + 1) if(dp[i][j]){
			int notuse = n - m - (sum - j) / 2 - j;
			
			/*
			cerr<<"i: "<<i<<" j: "<<j<<" dp: "<<dp[i][j]<<endl;
			dbg(rem[i]);
			dbg(notuse);
			*/
			
			if(rem[i] == 0) (dp[i + 1][j] += dp[i][j]) %= mod;
			if(rem[i] == 1){
				if(j) (dp[i + 1][j - 1] += dp[i][j] * (ll)j % mod) %= mod;
				if(notuse) (dp[i + 1][j + 1] += dp[i][j] * (ll)notuse % mod) %= mod;
			}
			if(rem[i] == 2){
				if(j >= 2) (dp[i + 1][j - 2] += dp[i][j] * (ll)C[j][2] % mod) %= mod;
				if(j >= 1 && notuse) (dp[i + 1][j] += dp[i][j] * (ll)j % mod * notuse % mod) %= mod;
				if(notuse >= 2) (dp[i + 1][j + 2] += dp[i][j] * (ll)C[notuse][2] % mod) %= mod;
			}
		}
		sum += rem[i];
	}
	if(sum != 2 * (n - m)) cout << "0" << endl;
	else cout << dp[n][0] << endl;
	
	return 0;
}
