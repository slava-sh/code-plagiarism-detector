#include<stdio.h>
#include<iostream>

using namespace std;

int main() {
	freopen("prizes.in","r",stdin);
	freopen("prizes.out","w",stdout);
	int n, m;
	cin >> n >> m;
	if(n == 1 ||  m == 1) {
		if(max(n, m) - 3 < 0) {
			cout << "0";
			return 0;
		}
		cout << ((max(n, m) - 3) / 4) + 1;
		return 0;
	}
	if(n >= 3 && m >= 3) {
		cout << "1";
		return 0;
	}
	else {
		cout << "0";
		return 0;
	}
}