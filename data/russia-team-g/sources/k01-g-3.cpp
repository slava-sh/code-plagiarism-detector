#include <iostream>
#include <fstream>

using namespace std;
#define fname "prizes"
typedef long long ll;

ll n, k, m, kk;

int main() {

	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin >> n >> m;
	k = min(n, m);
	kk = max(n, m);
	if(k == 1) {
		if(kk % 4 == 3) cout << (kk + 1) / 4;
		else
		cout << kk / 4;
	}
	else
	if(k == 2) cout << 0; else cout << 1;
		return 0;

	
}