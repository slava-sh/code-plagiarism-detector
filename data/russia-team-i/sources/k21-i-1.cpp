#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cmath>
#include <stack>
#include <set>
#include <vector>
#include <queue>
#include <deque>

#define goo(i,k,n) for(int i=k;i<n;i++)
#define go(i,n) goo(i,0,n)
#define ll long long
#define f first
#define s second

using namespace std;
ll n,d, a[100005],x=0, b[100005], k=0, m=0, c[100005];

int main(){
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	cin>>n>>d;
	go(i,n)
		cin>>a[i];
	go(i,n)
		if(a[i]>d){
			b[k]=a[i];
			k++;
		}
	go(i,k){
		if(b[i]-2*d>0)
			x+=(b[i]-2*d);
		else{
			c[m]=b[i];
			m++;
		}
	}
	if (k!=0)
		x+=2*d; 	
	if(m>=2){
		sort(c,c+m);
		ll maxlon=c[m-1], maxlon2=c[m-2];
		x-=4*d;
		x+=(maxlon+maxlon2);
	}
	if(m==1){
		x-=2*d;
		x+=c[0];
	}
	cout<<x;

	return 0;
}




