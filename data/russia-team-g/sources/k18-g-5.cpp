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
	if (m > 2 && n > 2) {
		cout << (min(m, n) - 3)/4 + 1;
	} else {
		if(n == 2 || m == 2) {
			cout << 0;
		} else if(n == 1) {
			cout << (m - 3)/4 + 1;
		} else if(m == 1){
			cout << (n - 3)/4 + 1;		
		}	
	}
	return 0;
}
