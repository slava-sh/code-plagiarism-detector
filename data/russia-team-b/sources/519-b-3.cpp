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
		for(int j=i;j<n;j++)
		{
			if(a[j]-a[i] >= r)
			{
				k=k+n-j;
			}
		}
	}
	cout<<k;
}