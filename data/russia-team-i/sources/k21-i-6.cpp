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
		if(a[i] >= 2*d){
			b[k] = a[i];
			k++;
		}
	if(k == 0){
		cout << a[n - 1];
		exit(0);
	}
	else{
		go(i,k){
			x+=(b[i]-2*d);
		}
		x+=2*d;
		cout << x;
		exit(0);
	}
	return 0;
}




