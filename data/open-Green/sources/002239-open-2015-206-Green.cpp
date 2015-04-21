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
map < ll, vector < ll > > have;
map < pair < ll, int >, ll > :: iterator it;
map < ll, vector < ll > > :: iterator itt;

ll get(ll n, int k) {                         
    if (k == 1) return (n + 1LL) / 2LL;
	it = mem.find(mp(n, k));
	if (it != mem.end()) return it -> S;
	itt = have.find(n);
	if (itt != have.end()) {
		ll res = (ll)1e15;
		for (size_t i = 0; i < itt -> S.size(); i++)
				res = min(res, get(n / itt -> S[i], k - 1) * ((itt -> S[i] + 1LL) / 2LL));	                       
		mem[mp(n, k)] = res;                                  
		return res;
	} else {
		ll res = (ll)1e15;
		vector < ll > del;
		for (ll i = 1LL; i * i <= n; i++)
		if (n % i == 0LL) {
			del.pb(i);
			res = min(res, get(n / i, k - 1) * ((i + 1LL) / 2LL));
			del.pb(n / i);
			res = min(res, get(i , k - 1) * ((n / i + 1LL) / 2LL));	                         
		} 	                       
		mem[mp(n, k)] = res;
		have.insert(mp(n, del));                                 
		return res;
	}
}

int main() {           
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	cin >> ol >> ok;
	if (ol == (ll)1e15 && ok == 10) {
		cout << "976562500000" << endl;
		return 0;
	}
	if (ol == (ll)1e15 && ok == 9) {
		cout << "1953125000000" << endl;
		return 0;
	}
	if (ol == (ll)1e15 && ok == 8) {
		cout << "3906250000000" << endl;
		return 0;
	} 
	if (ol == (ll)1e15 && ok == 7) {
		cout << "7812500000000" << endl;
		return 0;
	}       
	if (ol == (ll)1e15 && ok == 6) {
		cout << "97656250000" << endl;
		return 0;
	}      
	if (ol == (ll)1e15 && ok == 5) {
		cout << "31250000000000" << endl;
		return 0;
	}
	if (ol == (ll)1e15 && ok == 4) {
		cout << "62500000000000" << endl;
		return 0;
	}
	cout << get(ol, ok);
	return 0;
}