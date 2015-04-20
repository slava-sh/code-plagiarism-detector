#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);
	long long n,hr,k=0;
	cin>>n>>hr;
	vector<long long> a(n);
	for(long long i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(long long i=0;i<n;i++)
	{
		long long r = n;
		long long l = i;
		while(r - l > 1)
		{
			long long mid = (r + l)/2;
			if(a[mid]-a[i] > hr)
				r = mid;
			else
				l = mid;
		}
		if(r < n)
			k = k + n - r;
	}
	cout<<k;
}