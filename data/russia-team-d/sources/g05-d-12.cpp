#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[100002];
int n,k;
int f(int x)
{
	int i,ret;
	ret=a[1];
	for(i=2;i<=n;i++)
		ret=max(a[i],ret+x);
	if(ret<=k)
		return 1;
	return 0;
}
void bin()
{
	int b,c,d;
	b=0;
	c=a[1];
	while(c-b>1)
	{
		d=(b+c)/2;
		if(f(d)==1)
			b=d;
		else
			c=d-1;
	}
	if (f(c)==1) cout<<c<<endl;
	else cout<<b<<endl;
}

int main()
{
	freopen("fence.in", "r", stdin);
	freopen("fence.out", "w", stdout);
	int i;
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	bin();
	return 0;
}


