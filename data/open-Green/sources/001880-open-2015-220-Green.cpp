#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
#include <vector>

#define SC(x) scanf("%d",&x)

using namespace std;
const int inf=2147483647;

int n,m,i,j,k;
long long ans,a[29];
vector<long long> v;

void rec(int i){
	if (i>=v.size()){
		long long t=1;
		for (j=0; j<k; ++j)
			t*=((a[j]+1)/2);
		ans=min(ans,t);
		return;
	}
	for (int j=0; j<k; ++j){
		a[j]*=v[i];
		rec(i+1);
		a[j]/=v[i];
	}
}

int main(){
	//freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	SC(n); SC(k);
	v.clear();
	for (i=2; i*i<=n; ++i){
		while ((n%i)==0){
			v.push_back(i);
			n/=i;
		}
	}
	if (n>1) v.push_back(n);
	if (k==v.size()){
		ans=1;
		for (i=0; i<v.size(); ++i)
			ans*=((v[i]+1)/2);
		printf("%lld\n",ans);
		return 0;
	}
	for (i=0; i<k; ++i)
		a[i]=1;
	ans=inf;
	rec(0);
	printf("%lld\n",ans);
	return 0;
}
