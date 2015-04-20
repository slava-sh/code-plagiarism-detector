// 1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <algorithm>
#include <iostream>
using namespace std;

int a[300001];

int main()
{
	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);
	int n, r, first, second=0;
	long long sum=0;
	/*for(int i=0;i<300000;i++)
		cout << i << " ";*/
	scanf("%d%d", &n, &r);
	for(int i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	first=0;
	for(int j=0;j<n;j++)
	{
		int i=1;
		while(a[second+i]<=r+a[first] && i+second<n)
			i++;
		if(a[i+second]<=r+a[first])
			break;
		second+=i;
		while(a[first]+r<a[second])
		{
			sum+=n-second;
			first++;
		}
	}
	cout << sum;
	return 0;
}