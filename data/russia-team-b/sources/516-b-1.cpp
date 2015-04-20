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

const ll INF = 1e18 + 1, maxn = 3 * (1e5 + 1);
const de eps = 1e-9;

ll n, i, j, k, m, answer, t[maxn], a[maxn];

ll bin_s(ll x0){
	ll i1, l = 0, r = n - 1, mid;
	for(i1 = 0; i1 < 40; ++i1){
		mid = (l + r) / 2;
		if(a[mid] > x0 + k){
			r = mid;
		}
		else{
			l = mid;
		}
	}
	if(a[l] > x0 + k){
		return l;
	}
	if(a[r] <= x0 + k){
		return n;
	}
	return r;
}

int main(){

#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
#else
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
#endif

	cin >> n >> k;
	for(i = 0; i < n; ++i){
		cin >> a[i];
	}
	for(i = 0; i < n; ++i){
		answer += (n - bin_s(a[i]));
	}
	cout << answer;
}