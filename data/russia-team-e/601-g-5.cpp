#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

#define TASK "prizes"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ll n,m;
	cin>>n>>m;
	ll k = min(n, m);
	if (k == 1) {
	    k = max(n, m);
		cout << (k + 1)/4;
	}
	else {
		cout<<(k + 1) / 4;
	}
}