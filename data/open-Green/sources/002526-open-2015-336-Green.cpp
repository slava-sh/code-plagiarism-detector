#include <iostream>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <algorithm>
#include <string>

using namespace std;


typedef long long ll;
typedef unsigned long long ull;
#define forn(i, n) for(ll i = 0; i < n; i++)
#define fornn(i, be, n) for(ll i = be; i < n; i++)
#define mk make_pair
const int infi = 1e9 + 7;

vector<ll> Z;

ll res = (ll)1e18;
ll n, k, e;

ll dfs(int i, int z){
	if(z > k)
		return -1;
	if(i == -1){
		return 1;
	}
	ll s = 1, q = 1e18;
	for(int w = i; w >= 0; w--){
		s *= Z[w];
		ll t = dfs(w - 1, z + 1);
		if(t != -1)
			q = min(q, t * (s / 2 + s % 2));
	}
	return q;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> k;
	e = n;
	if(k == 1){
		cout << n / 2 + (n % 2);
		return 0;
	}
	for(ll i = 2; i * i <= n; i++){
		ll u = 0;
		while(n % i == 0)
			n /= i, Z.push_back(i);
	}
	if(n != 1)
		Z.push_back(n);
	cout << dfs(Z.size() - 1, 0);
}