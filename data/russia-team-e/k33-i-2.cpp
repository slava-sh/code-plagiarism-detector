#include <bits/stdc++.h>

using namespace std;

int n,d,a[111111],fail[111111],ans,answer,res;

int main()
{
	ios_base :: sync_with_stdio(0);

	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);

	cin >> n >> d;
	for ( int i = 1; i <= n; i++ ) {
		cin >> a[i];
		ans = max(ans,a[i]);
	}

	if ( n == 1 ) { cout << a[1]; return 0; }

	sort (a + 1,a + n + 1);

	int last = 1;
	for ( int i = 2; i <= n; i++ ) {
		if ( a[i] <= d ) { fail[i] = 1; continue; }	
		if ( a[last] <= d ) { fail[last] = 1; continue; }	
		if ( a[i] + a[last] - 2 * d < d ) { fail[i] = 1; continue; }
		a[i] -= d, a[last] -= d;
		last = i;
	}

	for ( int i =1 ; i <= n; i++ ) {
		if ( fail[i] == 1 ) res = 0;
		else res += a[i];
		answer = max(answer,res);
	}
	cout << max(answer,ans);	
	
}