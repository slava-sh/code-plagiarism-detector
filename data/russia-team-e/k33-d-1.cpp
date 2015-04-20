#include <bits/stdc++.h>

using namespace std;

int mn = 2000000,mx,a[111111],n,k;

bool f(int x)
{
	if ( x > mn) return false;
	if ( n * x <= k ) return true;
		return false;
}

int main()
{	
	ios_base :: sync_with_stdio(0);
		
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);

	cin >> n >> k;

	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		mn = min(mn,a[i]);	
		mx = max(mx,a[i]);
	}
	if (n > k ) { cout << 0; return 0; }
	if ( n == k ) { cout << 1; return 0; }

	int l = 0,r =  k / n + 1;
	while (r - l > 1) {
		int mid = (l + r) / 2;
		if ( f(mid) ) l = mid + 1;
			else r = mid;
	}
	cout << r - 1;
}