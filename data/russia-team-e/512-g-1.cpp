#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
using namespace std;



int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("prizes.in", "r", stdin);freopen("prizes.out", "w", stdout);
	int n, m;
	cin >> n >> m;
	if((n == 2) || (m == 2)){
		cout << 0;
		return 0;
	}
	if((n > 2) && (m > 2)){
		cout << 1;
		return 0;
	}
	if(n == 1){
		swap(n, m);
	}
	int ans = n / 4;
	if(n % 4 == 3){
		ans++;
	}
	cout << ans;
	return 0;
}