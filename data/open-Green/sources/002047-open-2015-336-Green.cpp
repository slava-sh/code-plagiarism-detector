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

vector<pair<ll, ll> > Z;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	ll n, k, e;
	cin >> n >> k;
	e = n;
	if(k == 1){
		cout << n / 2 + (n % 2);
		return 0;
	}
	for(ll i = 2; i * i <= n; i++){
		ll u = 0;
		while(n % i == 0)
			n /= i, u++;
		if(u)
			Z.push_back(mk(i, u));
	}
	if(n != 1)
		Z.push_back(mk(n, 1));
	int l = 0;
	vector<ll> P;
	for(int i = 0; i < k && l < Z.size(); i++){
		if(Z[l].first == 2){
			while(Z[l].second > 0 && i + 1 < k)
				Z[l].second--, P.push_back(1), i++, e /= 2;
			i--;
			l++;
		}
		else{
			while(Z[l].second > 0 && i + 1 < k)
				Z[l].second--, P.push_back(Z[l].first / 2 + 1), i++, e /= Z[l].first;
			i--;
			l++;
		}
	}
	P.push_back(e / 2 + e % 2);
	ll res = P.back();
	for(int i = P.size() - 2; i >= 0; i--){
		res *= P[i];
	}
	cout << res;
}