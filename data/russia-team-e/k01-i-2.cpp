#include <iostream>
#include <fstream>
#include<algorithm>

using namespace std;
#define fname "sochi"
typedef long long ll;

ll n,d,a[111111],l,r,b[111111],c[111111],calc,ans;

int main() {

	freopen(fname".in", "r", stdin);
	freopen(fname".out", "w", stdout);
	cin >> n >> d;
	for(ll i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>=3*d)
		l++,b[l]=a[i];
		else if(a[i]>=2*d)
		r++,c[r]=a[i];
	}
	sort(a+1,a+n+1);
	sort(c+1,c+r+1);
	reverse(c+1,c+r+1);
	calc=l;
	for(ll i=1;i<=l;i++)
	ans+=b[i];
	if(r>0)
	ans+=c[1],calc++;
	if(r>1)
	ans+=c[2],calc++;
	if(calc>0)
	ans=ans-2*d*(calc-1);
	cout<<max(ans,a[n]);
}