#include <set>
#include <map>
#include <cmath>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
#include <algorithm>

using namespace std;

#define ll long long
#define ld long double

const int MAXN = 300100;

ll n, r, a[MAXN];

char check(ll i, int j){
	if (i >= n) return false;
	return abs(a[i] - a[j]) <= r;
}

int main(){
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#else
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
#endif
	cin >> n >> r;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	ll uk1 = 0, uk2 = 0, ans = 0;
	for (int i = 0; i < n; i++){
		while (!check(uk1, i)) uk1++;
		while (check(uk2, i)) uk2++;
		ans += uk1 + (n - uk2);
	}
	cout << ans / 2;
	return 0;
}