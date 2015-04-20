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
	if ( n == 1 ) swap(n,m);
	if ( n == 2 || m == 2 ) { cout << 0; return 0; }	

	cout << ( n - 3 ) / 4 + 1;

}