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

ll F(ll x, int y){
	int cc = k - 1;
	ll te = 0;
	forn(i, n - 1){
		if(n - i - 1 <= cc)
			break;
		if(Q[i] > x && y < 0){
			if(cc == 0)
				cc = k, te += c;
			cc--;
			y--;
		}
		else
			te += Q[i] * d, y--;
	}
	ans = min(ans, te);
	return te;
}

ll Fq(ll x){
	ll l = -1, r = n + 5, w = inf;

	while(r - l > 2){
		ll lq = (l + (r - l) / 3), rq = (r - (r - l) / 3);
		ll a = F(x, lq), b = F(x, rq);
		if(a > b)
			l = lq;
		else
			r = rq;
		w = min(w, min(a, b));
	}
	for(int i = max(l - 5, 0ll); i < r + 5; i++)
		w = min(w, F(x, i));
	return w;
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
		if(Fq(lq) > Fq(rq))
			l = lq;
		else
			r = rq;
	}
	Fq(l), Fq(r), Fq((l + r) / 2);
	for(int i = max(l - 5, 0ll); i < r + 5; i++)
		Fq(i);
	cout << ans + res;
}