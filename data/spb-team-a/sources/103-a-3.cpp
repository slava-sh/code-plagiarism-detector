#include<iostream>
#include<cmath>
#include<cstdio>

using namespace std;

int main(){
	freopen("abcd.in", "r", stdin);
	freopen("abcd.out", "w", stdout);
	int t;
	int a[10000];
	int i;
	int x, y;
	cin >> t;
	for ( i = 0; i < t; i++){
		cin >> a[i];
	}
	for (i = 0; i < t; i++){
		x = a[i] / 100;
		y = a[i] % 100;
		if ((x*x + y*y) % 7 == 1){
			cout << "YES" << endl;
		}
		else cout << "NO" << endl;
	}
	return 0;
}