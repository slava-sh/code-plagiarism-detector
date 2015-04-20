#include <bits/stdc++.h>

using namespace std;

int n,x,a[333333];
long long ans;

int main()
{
	ios_base :: sync_with_stdio(0);

	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);

	cin >> n >> x;
	for ( int i = 1; i <= n; i++ )
		cin >> a[i];
	
	for ( int i = 1; i <= n; i++) {
		int l = i,r = n;
		while ( r - l > 1 ) {
			int mid = (l + r) / 2;
			if (a[mid] - a[i] <= x)
				l = mid;
			else 	
				r = mid;
		}
		while ( r < n && a[r] - a[i] <= x ) r++;
		if ( a[r] - a[i] > x )	
			ans += (n - r + 1);
	}
	cout << ans;
}