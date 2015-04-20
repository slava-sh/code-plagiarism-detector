#include <bits/stdc++.h>

using namespace std;

int n,d,a[111111],fail[111111],ans;

int main()
{
	ios_base :: sync_with_stdio(0);

	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);

	cin >> n >> d;
	for ( int i = 1; i <= n; i++ )
		cin >> a[i];

	if ( n == 1 ) { cout << a[1]; return 0; }

	sort (a + 1,a + n + 1);

	int last = 1;
	for ( int i = 1; i < n; i++ ) {
		if ( a[i] <=d || a[i+1] <= d ) { fail[i] =1 ; continue; }
		if ( a[i] + a[i+1] - 2 * d >= d ) fail[i] = 2,fail[i+1] = 2,a[i] -= d,a[i+1] -= d;	
			else fail[i] = 1;	
	}
	for ( int i = 1; i <= n; i++ )
		if ( fail[i] == 2 ) ans += a[i];

	cout << ans;
}