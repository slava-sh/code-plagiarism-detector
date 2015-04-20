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

#define goo(i,k,n) for(int i=k;i<n;i++)
#define go(i,n) goo(i,0,n)
#define ll long long
#define f first
#define s second

using namespace std;
ll n,m,c,d[1000005];

int main(){
	freopen("prizes.in", "r", stdin);
	freopen("prizes.out", "w", stdout);
	cin>>n>>m;
	if(n>m) swap(n,m);
	if( n == 1){
		cout<<(m+1)/4;
		exit(0);
	}
	if( n == 2){
		cout<< 0;
		exit(0);
	}
	else{
		cout<< 1;
		exit(0);
	}
	return 0;
}




