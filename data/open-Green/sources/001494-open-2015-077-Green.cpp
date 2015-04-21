#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
long long binpow(long long a, int b){
	if(!b)
		return 1;
	if(b%2)
		return a*binpow(a,b-1);
	long long x=binpow(a,b/2);
	return x*x;
}
int main(){
	long long n;
	int k,col=0;
	scanf("%lld%d",&n,&k);
	vector<pair<int,int> >f;
	for(int i=2;i*i<=n;i++)
		while(n%i==0){
			if(f.empty() || f.back().first!=i)
				f.push_back(make_pair(i,0));
			f[f.size()-1].second++;
			n/=i;
		}
	if(n!=1)
		f.push_back(make_pair(n,1));
	for(int i=0;i<f.size();i++)
		col+=f[i].second;
	if(col<=k){
		long long ans=1;
		for(int i=0;i<f.size();i++)
			for(int j=0;j<f[i].second;j++)
				ans*=(f[i].first/2+f[i].first%2);
		printf("%lld",ans);
		return 0;
	}
	int a=0,b=0;
	if(f[0].first==2)
		a=col-f[0].second;
	b=col-a;
	vector<long long>ans(k,1);
	for(int i=0;i<k && a;i++,a--)
		ans[i]=2;
	ans[0]*=binpow(2,a);
	for(int i=1;i<f.size();i++)
		ans[0]*=binpow(f[i].first,f[i].second);
	long long x=1;
	for(int i=0;i<k;i++)
		x*=(ans[i]/2+ans[i]%2);
	printf("%lld",x);
}