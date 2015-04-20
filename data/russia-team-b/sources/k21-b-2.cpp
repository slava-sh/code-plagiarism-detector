#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <deque>

#define goo(i,k,n) for(int i=k;i<n;i++)
#define go(i,n) goo(i,0,n)
#define ll long long
#define f first
#define s second

using namespace std;

ll n, r, a[300005];
ll ans = 0;

int main(){
	freopen("che.in", "r", stdin);
	freopen("che.out", "w", stdout);
	cin >> n >> r;
	for (ll i = 0; i < n; i++)
		cin >> a[i];
	int i = 0;
	int j = 1;
	while (i < n && j < n && j >= i) {
		if ( (a[j] - a[i]) > r ) {
			ans += (n - j);
			i++;
			}
		else
			j++;
	}
	cout << ans;
	return 0;
}




