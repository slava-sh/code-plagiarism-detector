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
ll a[MAXN];

int main () {
	freopen(fname"in", "r", stdin);
	freopen(fname"out", "w", stdout);
	ll n,d,ans=0;
	cin>>n>>d;

	for(ll i=1;i<=n;i++)
		cin>>a[i];

	sort(a+1,a+n+1);

	ll k = d * 3;
	ll l=1;
	while(l<=n&&a[l]<k)
		l++;

	for(ll i=1;i<=n-2;i++){
		if(a[i]>=k){
			ans+=a[i]-(d*2);
		}
	}

	int cnt=0;
	if(n>=l){
		ans+=(a[n]-d);
		cnt++;	
	}
	if(n-1>=l){
		ans+=(a[n-1]-d);
		cnt++;
	}
	if((l-1)>0 && a[l-1]>(d*2)){
		if(cnt<2)
			ans += (a[l-1]-d);
		else 
			ans=ans-d+(a[l-1]-d);
	    cnt++;
	}
	if((l-2)>0 && a[l-2]>(d*2)){
		if(cnt<2)
			ans += (a[l-2]-d);
		else 
			ans=ans-d+(a[l-2]-d);
		cnt++;
	}
	cout<<ans<<endl;
	return 0;
}
