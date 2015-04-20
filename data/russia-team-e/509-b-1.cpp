// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

int a[300001];

int main()
{
	freopen("sochi.in","r",stdin);
	freopen("sochi.out","w",stdout);
	int n, r, first, second;
	long long sum=0;
	cin >> n >> r;
	for(int i=0;i<n;i++)
	{
		cin >> a[i];
	}
	first=0;
	for(int j=0;j<n;j++)
	{
		int i=1;
		while(a[first+i]<=r+a[first] && i+first<n)
			i++;
		if(a[i+first]<=r+a[first])
			break;
		second=first+i;
		while(a[first]+r<a[second])
		{
			sum+=n-second;
			first++;
		}
	}
	cout << sum;
	return 0;
}