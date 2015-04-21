#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#define inf 2E+18
using namespace std;
int main(){
	int n,k;
	long long c,d,ans=0;
	scanf("%d%d%lld%lld",&n,&k,&c,&d);
	vector<long long>a(n),b(n),l(n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
		ans+=d*(b[i]-a[i]);
	}
	for(int i=0;i<n-1;i++)
		l[i+1]=a[i+1]-b[i];
	l[0]=inf;
	sort(l.rbegin(),l.rend());
	int u=k-1;
	l[0]=0;
	for(int i=1;i<n;i++)
		l[i]+=l[i-1];
	for(int i=1;i<n;i++)
		if(u)
			u--;
		else
			if(c<d*(l[min(n-1,i+k-1)]-l[i-1])){
				u=k-1;
				ans+=c;
			}else{
				ans+=d*(l[n-1]-l[i-1]);
				break;
			}
	printf("%lld",ans);
}