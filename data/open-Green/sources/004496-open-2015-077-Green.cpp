#include<iostream>
#include<stdio.h>
#include<vector>
#define inf 2E+18
using namespace std;
vector<long long>x(1,1);
int k;
long long ans=inf;
void rec(int n, int m, long long cur){
	if(n==k || m==x.size()){
		ans=min(ans,cur);
		return;
	}
	if(n==k-1){
		rec(n+1,x.size(),cur*((x.back()/x[m-1])/2+(x.back()/x[m-1])%2));
		return;
	}
	for(int i=m;i<x.size();i++)
		rec(n+1,i+1,cur*((x[i]/x[m-1])/2+(x[i]/x[m-1])%2));
}
int main(){
	long long n;
	scanf("%lld%d",&n,&k);
	if(n==1){
		printf("1");
		return 0;
	}
	for(long long i=2;i*i<=n;i++)
		while(n%i==0){
			x.push_back(i);
			n/=i;
		}
	if(n!=1)
		x.push_back(n);
	for(int i=1;i<x.size();i++)
		x[i]*=x[i-1];
	rec(0,1,1);
	printf("%lld",ans);
}