#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
int n,d;
long long b;
int j,r,k,maxim,i;
vector <int> a;
int main()
{
    freopen("prizes.in","r",stdin);
    freopen("prizes.out","w",stdout);
    scanf("%d%d",&n, &r);
	if(n>r)
	{
		k=n;
		n=r;
		r=k;
	}
	if(n==1)
	{
		printf("%d\n", (r+1)/4);
		return 0;
	}
	if(n==2)
	{
		printf("0\n");
		return 0;
	}
	if(n>=3)
		printf("1\n");
    return 0;
}