#include <iostream>
#include <fstream>

using namespace std;
#define fname "che"
typedef long long ll;

int n, a[1111111], r,l,ans;

int main() {

	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin >> n >> r;
	for(int i = 1; i <= n; i++)
		cin >> a[i];
	l=1;	
	for(int i = 1; i <= n; i++) {
		while(a[l]-a[i]<=r&&l<=n)
		l++;
		ans+=n-l+1;		
	}
	cout<<ans;
}