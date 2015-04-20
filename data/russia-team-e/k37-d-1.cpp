#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int n, k, x;
	cin >> n >> k;
	int mx = k / n, mn = 1000000000;
	for(int i = 1; i <= n; i++){
		cin >> x;
		mn = min(mn, x);
	}
	cout << min(mn, mx);
	return 0;
}