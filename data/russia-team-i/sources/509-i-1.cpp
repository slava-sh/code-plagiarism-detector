// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

int a[1001];
int maxi1=-1;

bool find_elem(int n, int d)
{
	bool flag=false;
	if(maxi1!=-1)
	{
		for(int i=0;i<n;i++)
		{
			if(a[i]>d && a[i]<3*d && a[i]>=a[maxi1])
			{
				flag=true;
				maxi1=i;
			}
		}
	}
	else
		return false;
	return flag;
}

int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	int n, d, c=0, z=0;
	long long sum=0, sum3=0;
	bool flag=false;
	cin >> n >> d;
	if(n==1)
	{
		cin >> c;
		cout << c;
		return 0;
	}
	if(n==2)
	{
		int x;
		cin >> z >> c;
		x=max((c+z-2*d), c);
		x=max(x, z);
		cout << x;
		return 0;
	}
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
		if(a[i]>=3*d)
		{
			sum+=a[i];
			c++;
		}
		else if(a[i]<3*d)
			maxi1=i;
	}
	if(find_elem(n, d))
	{
		sum+=a[maxi1];
		a[maxi1]=0;
		c++;
	}
	if(find_elem(n, d))
	{
		sum+=a[maxi1];
		a[maxi1]=0;
		c++;
	}
	if(c==0)
	{
		int maxs=-1;
		for(int i=0;i<n;i++)
		{
			maxs=max(maxs, a[i]);
		}
		cout << maxs;
		return 0;
	}
	cout << sum-(c-1)*2*d;
	return 0;
}

