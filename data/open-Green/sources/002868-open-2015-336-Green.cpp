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

ll mas[100][100];

ll dfs(int i, int z){
	if(z > k)
		return -1;
	if(i == -1){
		return 1;
	}
	if(mas[i][z] != -2)
		return mas[i][z];
	ll s = 1, q = (ll)1e18;
	for(int w = i; w >= 0; w--){
		s *= Z[Z.size() - w - 1];
		ll t = dfs(w - 1, z + 1);
		if(t != -1){
			q = min(q, t * (s / 2 + s % 2));
		}
	}
	if(q == 1e18)
		return mas[i][z] = -1;
	return mas[i][z] = q;
}

ll fyu(ll n, ll k){
	e = n;
	forn(i, 100){
		forn(j, 100){
			mas[i][j] = -2;
		}
	}
	if(k == 1){
		return n / 2 + (n % 2);
	}
	Z.clear();
	for(ll i = 2; i * i <= n; i++){
		ll u = 0;
		while(n % i == 0)
			n /= i, Z.push_back(i);
	}
	if(n != 1)
		Z.push_back(n);
	return dfs(Z.size() - 1, 0);
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	cin >> n >> k;
	cout << fyu(n, k);
	return 0;
}