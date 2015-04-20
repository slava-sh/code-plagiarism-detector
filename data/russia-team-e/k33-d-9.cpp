#include <bits/stdc++.h>

using namespace std;

int mn = 2000000000,mx,a[111111],n,k;

bool f(int x)
{
	if ( x > mn) return false;
	int pos = 2,i = a[2];
	while(pos <= n) {
		i = a[pos-1] + x;
		if (i < a[pos] ) i = a[pos];
		pos++;
	}
	if ( i > k ) return false;
	return true;
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

	sort(a + 1,a + n + 1);

	//if (n > k ) { cout << 0; return 0; }
	//if (mn > k ) { cout << 0; return 0; }

	int l = 0,r = k / n + 1;
	while (r - l > 1) {
		//cout << l << " " << r << endl;
		int mid = (l + r) / 2;
		if ( f(mid) ) l = mid;
			else r = mid;
	}
	cout << r - 1;
}