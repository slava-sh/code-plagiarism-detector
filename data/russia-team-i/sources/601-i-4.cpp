#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define TASK "sochi"
typedef long long ll;
vector<ll> a,b;

#define forn(i,n) for(int i=0;i<(int)n;i++)
int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	ll n;
	ll d;

	cin>>n;
	cin>>d;
	a.resize(n);
	forn(i,n)
		cin>>a[i];
	forn(i,n)
		if(d<=a[i]&&a[i]<3*d)
			b.push_back(a[i]);
	sort(b.rbegin(),b.rend());
	ll sum=0;
	ll j=0;
	forn(i,n)
		if(a[i]>=3*d)
			j++,sum+=a[i]-2*d;
	if(b.size()>=2)
		sum+=max(max(b[0]+b[1]-2*d,b[0]),min(j,1LL)*2*d);
	if(b.size()==1)
		sum+=max(b[0],min(j,1LL)*2*d);
	if(b.size()==0)
		sum+=min(j,1LL)*2*d;

	cout<<max(sum,*max_element(a.begin(),a.end()));
}