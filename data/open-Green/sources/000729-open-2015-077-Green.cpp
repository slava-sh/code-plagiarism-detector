#include<iostream>
#include<stdio.h>
#include<vector>
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
	int k;
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
	reverse(f.begin(),f.end());
	long long ans=1;
	for(int i=1;i<k;i++){
		ans*=((long long)f.back().first/2+f.back().first%2);
		if(f.back().second==1)
			f.pop_back();
		else
			f[f.size()-1].second--;
	}
	long long x=1;
	for(int i=0;i<f.size();i++)
		x*=binpow(f[i].first,f[i].second);
	x=x/2+x%2;
	printf("%lld",ans*x);
}