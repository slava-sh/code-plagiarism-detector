#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <ctime>
#include <cstdlib>

using namespace std;

#define fname "sochi."
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define sz size()
#define ll long long

const int MAXN = 100500;
const int INF = 1 << 30;
vector < ll > g;

int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	ll n,d,ans=0,max1=0;
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		ll x;
		cin>>x;
		max1 = max(max1,x);
		if(x > 2*d)
			g.pb(x);
	}
	if(max1 < (2*d)){
		cout<< max1 << endl;
		return 0;
	}
	int m = g.size();
	sort(g.begin(),g.end());
	ll l=0;
	while(l<m && g[l]<(3*d))
		l++;

	for(ll i=l;i<m;i++){
		if(ans==0)
			ans+=g[i];
		else 		
			ans=ans-d+g[i]-d;
	}
	if(l>0)
		ans = max(ans, (ans-d+g[l-1]-d));
	if(l>1)
		ans = max(ans, (ans-d+g[l-2]-d));
	cout<< ans <<endl;
    return 0;
}
