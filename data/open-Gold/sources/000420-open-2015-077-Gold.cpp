#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf 2E+18
using namespace std;
vector<long long>l;
int n,k;
long long c,d;
long long solve(int x){
	long long res=0;
	int u=k-1;
	for(int i=0;i<n-1;i++)
		if(u)
			u--;
		else
			if(x && c<d*l[i]){
				u=k-1;
				x--;
				res+=c;
			}else
				res+=d*l[i];
	return res;
}
int main(){
	long long ans=0,mn=inf;
	scanf("%d%d%lld%lld",&n,&k,&c,&d);
	vector<long long>a(n),b(n);
	l.resize(n-1);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		ans+=d*(b[i]-a[i]);
	}
	for(int i=0;i<n-1;i++)
		l[i]=a[i+1]-b[i];
	sort(l.rbegin(),l.rend());
	int left=1,right=(n-1)/k+((n-1)%k?1:0);
	while(right-left>2){
		int m1=left+(right-left)/3,m2=right-(right-left)/3;
		if(solve(m2)>solve(m1))
			left=m1;
		else
			right=m2;
	}
	for(int i=left;i<=right;i++)
		mn=min(mn,solve(i));
	if(n-1)
		ans+=mn;
	printf("%lld",ans);
}