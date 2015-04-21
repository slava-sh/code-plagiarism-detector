#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#define ll long long

using namespace std;

ll a, b, c, d, e, f;
vector<ll> v;

int main(){
	ll ans = 0;
	cin >> a >> b >> c >> d;
	ll last = 0;
	for(int i = 0; i < a; ++i){
		cin >> e >> f;
		ans += (f - e) * d;
		if(i != 0) v.push_back(e - last);
		last = f;
	}
	ll min_ = 2E18;
	sort(v.begin(), v.end());
	min_ = ((a - 1) / b) * c;
	ll len = 0;
	for(int i = 0; i < v.size(); ++i){
		len += v[i];
		--a;
		min_ = min(min_, ((a - 1) / b) * c + len * d);
	}
	cout << ans + min_;

	return 0;
}