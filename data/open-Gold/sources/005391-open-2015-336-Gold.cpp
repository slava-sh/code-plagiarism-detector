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
const ll inf = 1e18 + 7;
const ll mod = 1e9 + 7;

ll n, k, c, d;
ll res, ans = inf;
vector<ll> L, R, Q;

ll F(ll x){
	int cc = k - 1;
	ll te = 0;
	forn(i, n - 1){
		if(n - i - 1 <= cc)
			break;
		if(Q[i] > x){
			if(cc == 0)
				cc = k - 1, te += c;
			cc--;
		}
		else
			te += Q[i] * d;
	}
	ans = min(ans, te);
	return te;
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
	ll l = -1, r = infi;

	while(r - l > 2){
		ll lq = (l + (r - l) / 3), rq = (r - (r - l) / 3);
		if(F(lq) < F(rq))
			l = lq;
		else
			r = rq;
	}
	F(l), F(r), F((l + r) / 2);
	cout << ans + res;
}