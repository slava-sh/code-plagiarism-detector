#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,d;
long long b;
int a[300001],j,r,k,maxim,i;
int main()
{
	freopen("prizes.in","r",stdin);
freopen("prizes.out","w",stdout);
	scanf("%d%d",&n, &r);
	if(n>r)
	{
		printf("%d\n",(r+1)/4);
		return 0;
	}
	printf("%d\n", (n+1)/4);
/*	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n && a[i]+r<=a[n-1];i++)
	{

	}*/
	return 0;
}