#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define TASK "sochi"
vector<int> a,b;
typedef long long ll;
#define forn(i,n) for(int i=0;i<(int)n;i++)
int main() {
	freopen(TASK".in", "r", stdin);
	freopen(TASK".out", "w", stdout);
	int n;
	int d;

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
	forn(i,n)
		if(a[i]>=3*d)
			sum+=a[i]-2*d;
	if(b.size()>=2)
		sum+=max(max(b[0]+b[1]-2*d,b[0]),2*d);
	if(b.size()==1)
		sum+=max(b[0],2*d);
	if(b.size()==0)
		sum+=2*d;
	cout<<sum;
}