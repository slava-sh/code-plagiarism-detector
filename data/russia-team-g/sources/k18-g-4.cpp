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
	if(n == 1 && m > 2) {
		cout << (m + 1)/4;
		return 0;
	}

	if(m == 1 && n > 2) {
		cout << (n + 1)/4;
		return 0;
	}

	if(n > 2 && m > 2) {
		if(n > m) { 
			if(n - 2 < m) {	
				cout << (n - 1)/4 + 1;	
			} else {
				cout<< (m - 3)/4 + 1;
			}
		} else {
			if(n > m - 2) {
				cout << (m - 1)/4 + 1;
			} else {
				cout<< (n + 1)/4;
			}
		}	
	} else {
		cout << 0;
	}
	return 0;
}
