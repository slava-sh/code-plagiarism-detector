#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,d;
long long b;
int a[100001],j,k,maxim,i;
int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	scanf("%d%d",&n, &d);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a,a+n);
	i=n-1;
	maxim=a[i];
	while(i>=0 && a[i]>=3*d)
	{
		b+=a[i];
		i--;
		k++;
	}
	if(i==0)
	{
		if(a[i]>=2*d)
		{
			b+=a[i];
			k++;
		}
	}
	if(i>=1)
	{
		if(a[i]>=2*d)
		{
			b+=a[i];
			k++;
		}
		if(a[i-1]>=2*d)
		{
			b+=a[i-1];
			k++;
		}
	}
	if(k>1)
		b-=(2*(k-1)*d);
	if(b>maxim)
	cout<<b<<endl;
	else
		cout<<maxim<<endl;
	return 0;
}