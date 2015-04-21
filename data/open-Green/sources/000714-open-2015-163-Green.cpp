#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <deque>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <array>
#include <random>
#include <string>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

inline ll pown(ll p, int n){
	ll res = p;
	for(int i = 1; i < n; i++){
		res *= p;
	}
	return res;
}

inline ll find_root_n(ll from, int n){
	ll L = 1, R = 2;
	while(pown(R, n) <= from){
		R <<= 1;
	}
	while(L + 1 < R){
		ll M = (L + R) >> 1;
		if(pown(M, n) <= from){
			L = M;
		} else {
			R = M;
		}
	}
	return L;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	ll n;
	int k;
	cin >> n >> k;
	ll res = n;
	while(k && !(res & 1)){
		k--;
		n >>= 1;
		res >>= 1;
	}
	while(k){
		ll nw = find_root_n(n, k);
		while(n % nw){
			nw--;
		}
		n /= nw;
		res /= nw;
		res *= (nw >> 1) + 1;
		k--;
	}
	cout << res;
	return 0;
}