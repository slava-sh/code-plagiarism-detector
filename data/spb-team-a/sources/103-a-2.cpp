#include<iostream>
#include<cmath>

using namespace std;

int main(){
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