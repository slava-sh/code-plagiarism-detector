// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <iostream>
using namespace std;

int a[100001];

int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	int n,d,k=0,maxx=-1000000;
	cin >> n >> d;
	long long sum=0;
	int max=-100000,prevmax=-100000;
	bool f=false;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		a[i]-=3*d;
		if(a[i]+2*d>=0)
		{
			f=true;
		}
		if(a[i]+3*d>maxx)
			maxx=a[i]+3*d;
		if(a[i]>=0)
		{
			sum+=a[i]+d;
			k++;
		}
		else
		{
			if(a[i]>=max && a[i]+2*d>=0)
			{
				prevmax=max;
				max=a[i];
			}
		}
	}
	if(!f)
	{
		cout << maxx;
		return 0;
	}
	if(max!=-100000 && prevmax!=-100000)
	{
		sum+=max+prevmax+4*d;
		if(sum>maxx)
			cout << sum;
		else
			cout << maxx;
		return 0;
	}
	if(max!=-100000 && prevmax==-100000)
	{
		sum+=max+2*d;
		sum+=d;
		if(sum>maxx)
			cout << sum;
		else
			cout << maxx;
		return 0;
	}
	if(k>1)
		sum+=2*d;
	if(sum>maxx)
		cout << sum;
	else
		cout << maxx;
	return 0;
}