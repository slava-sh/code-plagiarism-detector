#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fornn(i, be, n) for(ll i = be; i < n; i++)
const int infi = 1e9 + 7;
const ll inf= 1e18 + 7;
const ll mod = 1e9 + 7;

ll n, k, c, d;
double t;
ll res, ans;
vector<ll> L, R, Q;
vector<ll> dp, pdp;

ll F(){
	if(Q.size() == 0)
		return 0;
	k--;
	dp.resize(k + 1, inf);
	pdp = dp;
	dp[k] = 0;
	forn(i, Q.size()){
		ll a = dp[0], b = dp[k];
		forn(j, k){
			dp[j] = min(dp[j] + Q[i] * d, dp[j + 1]);
		}
		dp[k] = min(b + Q[i] * d, a + c);
	}
	ll t = inf;
	forn(i, k + 1){
		t = min(t, dp[i]);
	}
	
	return t;
}

ll F2(){
	sort(Q.begin(), Q.end());
	reverse(Q.begin(), Q.end());
	vector<ll> T(n);
	forn(i, n - 1){
		T[i + 1] = T[i] + Q[i];
	}
	ll sum = 0, r = 0, ef = 0;
	forn(i, n - 1)
		sum += Q[i];
	ll t = k - 1;
	forn(i, n - 1){
		if(t > 0)
			t--, sum -= Q[i];
		else{
			ll a = T[min(i + k, n - 1)];
			ll b = T[i];
			if((a - b) * d > c){
				r += c;
				t = k - 1;
				sum -= Q[i];
			}
		}
	}
	return sum * d + r;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> k >> c >> d;
	R.resize(n);
	L.resize(n);
	forn(i, n){
		ll l, r;
		cin >> l >> r;
		L[i] = l;
		R[i] = r;
		res += (r - l) * d;
	}
	forn(i, n - 1){
		Q.push_back(L[i + 1] - R[i]);
	}
	cout << res + F2();
}