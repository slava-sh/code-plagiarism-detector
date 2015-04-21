#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <cstring>
#include <iterator>
#include <vector>
#include <iomanip>
#include <cstdlib>
#include <queue>
#include <set>
#include <map>          

#define pb push_back
#define mp make_pair
#define F first
#define S second
#define scf scanf
#define prf printf

using namespace std;

typedef long long ll;

ll ol;
int ok;
map < pair < ll, int >, ll > mem;
map < pair < ll, int >, ll > :: iterator it;

ll get(ll n, int k) {                         
    if (k == 1) return (n + 1LL) / 2LL;
	it = mem.find(mp(n, k));
	if (it != mem.end()) return it -> S;
   	ll res = (ll)1e15 / 2LL;
	for (ll i = 1LL; i * i <= n; i++)
		if (n % i == 0LL) {
			ll d1 = i;
			ll d2 = n / i;
			res = min(res, get(n / d1, k - 1) * ((d1 + 1LL) / 2LL));
			res = min(res, get(n / d2, k - 1) * ((d2 + 1LL) / 2LL));
			                         
		} 	                       
	mem[mp(n, k)] = res;                                  
	return res;
}

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> ol >> ok;
	ol = (ll)1e13;
	ok = 10;
	if (ok == 1LL) {
		cout << ((ol + 1LL) / 2LL) << endl;
		return 0;
	}
	cout << get(ol, ok);
	return 0;
}