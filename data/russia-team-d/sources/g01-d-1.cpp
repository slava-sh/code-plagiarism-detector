#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,d,k,ans,s;
long long b;
int j,r,maxim,x,i,a[100009];
int main()
{
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
/*	scanf("%d%d",&n, &r);
	if(n>r)
	{
		if(r==1)
			printf("%d\n",(n+1)/4);
		else
					printf("%d\n",(r+1)/4);
		return 0;
	}
			if(n==1)
			printf("%d\n",(r+1)/4);
			else
	printf("%d\n", (n+1)/4);*/
	scanf("%d%d", &n, &k);
	for(i=1;i<=n;++i)
		scanf("%d", &a[i]);
	sort(a+1,a+n+1);
	ans=a[1];
	a[0]=0;
	for(i=0;i<n;++i)
	{
		if(ans>(k-a[i])/(n-i))
			ans=(k-a[i])/(n-i);
	}
	printf("%d\n", ans);
			cin>>x;
	return 0;
}