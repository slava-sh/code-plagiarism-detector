#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
//int a[100008],n;
int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	int n=0;
	int ce,m,i,j,b,c,d,e;
	long long ans=0;
	scanf("%d%d",&m,&d);
	for(i=1;i<=m;i++)
	{
		scanf("%d",&b);
		if(b>2*d)
		{
			n++;
			ans=ans+b;
		}
	}
	if(n==0)
		ans=0;
	else
	ans=ans-(n-1)*2*d;
	printf("%I64d",ans);
	return 0;
}