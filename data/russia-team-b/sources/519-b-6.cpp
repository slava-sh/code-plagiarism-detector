#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);
	int n,r,k=0;
	cin>>n>>r;
	vector<int> a(n);
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(int i=0;i<n;i++)
	{
		int r = n;
		int l = i;
		while(r - l > 1)
		{
			int mid = (r + l)/2;
			if(a[mid]-a[i] > r)
				r = mid;
			else
				l = mid;
		}
		if(r < n)
			k = k + n - r;
	}
	cout<<k;
}