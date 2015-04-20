#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;



int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("sochi.in", "r", stdin);freopen("sochi.out", "w", stdout);
	int n, d, t, ans;
	ans = 0;
	vector<int> iv;
	iv.resize(3, 0);
	cin >> n >> d;
	if(n == 1){
		cin >> t;
		cout << t;
		return 0;
	}
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t >= d * 3){
			t -= d * 2;
			ans += t;
		} else {
			iv[0] = t;
			sort(iv.begin(), iv.end());
		}
	}
	ans += max(d, iv[1] - d);
	ans += max(d, iv[2] - d);
	cout << ans;
	return 0;
}