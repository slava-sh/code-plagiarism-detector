#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue> 
#include <set>
#include <map>
#include <sstream>
#include <algorithm>
#define f first
#define s second
#define pb push_back
#define mp make_pair
#define inf 2000000000
#define Min(a,b) (a<b?a:b)
#define Max(a,b) (a>b?a:b)
#define For(i,s,n) for (int i=s;i<=n;i++)
#define FOR(i,s,n) for (int i=s;i<n;i++)
#define Ford(i,s,n) for (int i=s;i>=n;i--)
#pragma comment(linker, "/STACK:16777216")


#define MD 1000000007


typedef long long ll;

using namespace std;

int n,k,a[100005];

bool check(int x){
	int last=a[1];
	For(i,2,n){
		last=Max(a[i],last+x);
		if (last>k) return false;
	}
	return true;
}


int main(){
	freopen("fence.in","r",stdin);freopen("fence.out","w",stdout);
	scanf("%d%d",&n,&k);
	int l=0,r=k;
	For(i,1,n) scanf("%d",a+i),r=Min(r,a[i]);
	sort(a+1,a+n+1);
	while(r-l>1){
		int mid=(l+r)/2;
		if (check(mid)) l=mid;else r=mid-1;
	}
	if (check(r)) printf("%d\n",r);else printf("%d\n",l);
}