#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;

#define TASK "fence"
#define forn(i,n) for(int i=0;i<(int)n;i++)
typedef long long ll;
ll a[200000];
ll n; ll k;
bool check(ll x)
{
	forn(i,n)
		if(a[i]<x)
			return 0;
	return ((((ll)n)*x)<=k);
}
int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	cin>>n>>k;
	forn(i,n)
		cin>>a[i];
	ll l=0,r=k+1;
	while(r-l>1)
	{
		ll m=(l+r)/2;

		if(check(m))l=m;
		else r=m;
	}
	cout<<l;
	return 0;
}