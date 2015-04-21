#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf 2E+18
using namespace std;
long long binpow(long long a, int b){
	if(!b)
		return 1;
	if(b%2)
		return a*binpow(a,b-1);
	long long x=binpow(a,b/2);
	return x*x;
}
vector<long long>x;
int q;
long long ans=inf,bin=1;
void rec(int n, int m, long long cur){
	if(n==q || m==x.size()){
		ans=min(ans,cur);
		return;
	}
	for(int i=m;i<x.size();i++)
		rec(n+1,i+1,cur*((x[i]/x[m-1])/2+(x[i]/x[m-1])%2));
}
int main(){
	long long n;
	int k,col=0;
	scanf("%lld%d",&n,&k);
	vector<pair<long long,int> >f;
	for(long long i=2;i*i<=n;i++)
		while(n%i==0){
			if(f.empty() || f.back().first!=i)
				f.push_back(make_pair(i,0));
			f[f.size()-1].second++;
			n/=i;
		}
	if(n!=1)
		f.push_back(make_pair(n,1));
	int a=0,b=0;
	for(int i=0;i<f.size();i++)
		b+=f[i].second;
	if(f[0].first==2){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		a=f[0].second;
		b-=a;
	}
	vector<long long>t(k,1);
	int s=0;
	for(int i=0;i<k && a;i++,a--){
		t[i]=2;
		s=i+1;
	}
	bin=binpow(2,a);
	x.push_back(1);
	for(int i=0;i<f.size();i++)
		if(f[i].first!=2)
			for(int j=0;j<f[i].second;j++)
				x.push_back(f[i].first);
	for(int i=1;i<x.size();i++)
		x[i]*=x[i-1];
	q=k-s;
	rec(0,1,1);
	printf("%lld",ans*bin);
}