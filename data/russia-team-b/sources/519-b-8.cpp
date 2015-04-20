#include<iostream>
#include<vector>
#include<stdio.h>

using namespace std;

int main()
{
	freopen("che.in","r",stdin);
	freopen("che.out","w",stdout);
	int n,hr,k=0;
	cin>>n>>hr;
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