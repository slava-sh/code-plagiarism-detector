#include <bits/stdc++.h>

#define pb push_back

using namespace std;

int n,d,a[111111],fail[111111],ans,answer,res,mypos,New;
vector < int > vec;


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
	sort (a + 1,a + n + 1,greater < int >());

	int i = 1;
	if ( n >= 3 ) {
		int p = 0;
		while ( i <= n ) {
			if ( a[i] >= 3 * d )
				vec.pb(a[i]),i++;
			else 
				break;
		}
		int cnt = 0;
		while ( i <= n ) {
			if ( cnt == 2 ) break;
			if ( a[i] > d ) cnt++,vec.pb(a[i]),i++;
				else break;
		}
		for ( int  i = 0; i < vec.size(); i++ ) {
			if (i == 0 ) res = vec[i];
				else if ( i < vec.size() - 2 )
					res = res + vec[i] - 2 * d;
				else 	
					res = res + vec[i] - 2 * d;
			New = max(New,res);
		}

		cout << max(New,ans);
	}
	else {
		if ( n == 1 ) { 
			cout << a[1];
			return 0;
		}
		else {
			if ( a[1] > d && a[2] > d ) {
				cout << a[1] + a[2] - 2 * d;
			}
			else {
				cout << max(a[1],a[2]);
			}
		}
	}
} 
		
