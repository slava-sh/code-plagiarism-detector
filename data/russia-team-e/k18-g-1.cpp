#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <cstdio>
#define ll long long

using namespace std;

ll n, m;

int main () {
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	
	cin >> n >> m;
	if(n > 2 && m > 2) {
		if(n > m) cout<< (m - 3)/4 + 1;
		else cout<< (n - 3)/4 + 1;	
	} else {
		cout << 0;
	}
	return 0;
}
