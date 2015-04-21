#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <bitset>
#include <algorithm>
#include <string>
#include <cassert>
#include <queue>

using namespace std;

typedef long long ll;
typedef long double ld;
const int INF = (int)2e9;
const ll LINF = (ll)8e18;
const ld EPS = 1e-9;

ll n, k, c, d;
ll alla, sumb;
vector<ll> allb;
ll last, a, b;

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	//freopen("xxx.in", "r", stdin);
	//freopen("xxx.out", "w", stdout);
#endif
	cin >> n >> k >> c >> d;
	cin >> a >> b;
	last = b;
	alla += (b - a);
	allb.reserve(n);
	for(int i = 1; i < n; i++){
		cin >> a >> b;
		alla += (b - a);
		allb.push_back(a - last);
		last = b;
	}
	alla *= d;
	sort(allb.begin(), allb.end());
	ll mint = LINF;
	for(int i = 0; i < (int)allb.size(); i++){
		mint = min(mint , ((allb.size() + 1 - i) / k  - 1) * c + sumb * d);
		sumb += allb[i];
	}
	mint = min(mint, sumb * d);
	cout << alla + mint;
	return 0;
}