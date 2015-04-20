#include <bits/stdc++.h>

using namespace std;

int n,m,ans;

int main()
{
	ios_base :: sync_with_stdio(0);

	freopen("prizes.in","r",stdin);
	freopen("prizes.out","w",stdout);

	cin >> n >> m;

	if ( n == 1 && m == 1 ) { cout << 0; return 0; }
	if ( n > m ) swap(n,m);

	if ( n == 1 ) n = max(n,m);

	if ( n == 2 ) { cout << 0; return 0; }

	if ( (n -2) % 4 == 0 ) cout << (n - 2) / 4;
		else cout << (n - 2) / 4 + 1;
}