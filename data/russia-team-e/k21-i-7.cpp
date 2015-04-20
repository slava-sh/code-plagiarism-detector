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
#include <cstdlib>

#define goo(i,k,n) for(long long i=k;i<n;i++)
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
	sort(a,a+n);
	go(i,n)
		if(a[i] >= 3 * d){
			b[k] = a[i];
			x+=(b[k]-2*d);
			k++;
		}
	if( k > 0){
		x+=2*d;
		go(i,n){
			if(a[i] > 2*d && a[i] < 3*d) {
				c[m]=a[i];
				m++;
			}
		}
		if(m>=2){
			x += (c[m-2] + c[m-1] - 4 * d);
		}
		if(m==1){
			x += (c[m - 1] - 2*d);
		}
		if (a[n - 1] > x){
			cout << a[n - 1];
			exit(0);
		}
		else {
			cout << x;
			exit(0);
		}
		
	}
	if (k == 0) {
		if(a[n-1]> 2*d && a[n-2]> 2*d){
			cout<<a[n-1]+a[n-2]-2*d;
			exit(0);
		}
		else{
			cout<<a[n-1];
			exit(0);
		}
	}
			
	return 0;
}




