#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

int main () {
	//freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);
	freopen("sochi.in", "r", stdin);freopen("sochi.out", "w", stdout);
	int n, d, ans, t, mx;
	cin >> n >> d;
	ans = 0;
	mx = 0;
	vector<int> iv, i3;
	iv.resize(3,0);
	for(int i = 0; i < n; i++){
		cin >> t;
		mx = max(mx,t);
		if(t > d * 2){	
			if(t >= d * 3){
				i3.push_back(t);
				ans += t;
			}else{
				iv[0] = t;
				sort(iv.begin(), iv.end());
			}
		}
	}
	if(mx <= d * 2){
		cout << mx;
		return 0;
	}
	ans -= i3.size() * d * 2;
	ans += max(iv[2], d * 2);
	ans += max(iv[1] - d * 2, 0);
	cout << ans;
	return 0;
}