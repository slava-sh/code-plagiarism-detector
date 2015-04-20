#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <stdio.h>
#include <queue>
#include <deque>
#include <cmath>
#include <set>
#include <map>
#include <stack>
#include <utility>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;
typedef double de;
typedef pair<de, de> pde;
typedef vector<ll> vecl;
typedef vector<pll> vecpl;
typedef string str;
typedef vector<bool> veb;

#define x first
#define y second
#define mp make_pair
#define pb push_back
#define si size

const ll INF = 1e18 + 1, maxn = 1e5 + 1;
const de eps = 1e-9;

ll n, i, j, k, m, answer, a[maxn];

bool f(ll x0){
	ll s = 0, i1, id, ans = 1;
	if(x0 > a[0]){
		return 0;
	}
	for(i1 = 0; i1 < n; ++i1){
		s = max(s + x0, a[i1] - s);
	}
	if(s > k){
		ans = 0;
	}
	return ans;
}

ll bin_s(){
	ll l = 0, r = k, mid, i1;
	for(i1 = 0; i1 < 40; ++i1){
		mid = (l + r) / 2;
		if(f(mid)){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	if(f(r)){
		return r;
	}
	return l;
}

int main(){

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
#endif

	cin >> n >> k;
	for(i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a + n);
	answer = bin_s();
	cout << answer;
}