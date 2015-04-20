#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,d;
long long b;
int j,r,k,maxim,x,i;
vector <int> a;
int main()
{
	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);
	scanf("%d%d",&n, &r);
/*	if(n>r)
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
	for(i=0;i<n;i++)
	{
		scanf("%d",&x);
		a.push_back(x);
	}
	for(i=0;i<n && a[i]+r<=a[n-1];i++)
	{
		b+=n-(lower_bound(a.begin(),a.end(),a[i]+r+1)-a.begin());
	}
	cout<<b<<endl;
	return 0;
}