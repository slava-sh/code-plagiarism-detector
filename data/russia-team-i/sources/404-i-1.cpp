#include <algorithm>
#include <vector>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <set>
#include <string>

using namespace std;

#define push_back pb
#define make_pair mp
#define first fr
#define second sc


int main(){
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	freopen("sochi.in", "r", stdin);
	freopen("sochi.out", "w", stdout);
	int n,d;
	vector<int>a(n);
	scanf("%d%d",&n,&d);
	for (int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a.begin(),a.end());
	reverse(a.begin(),a.end());
	if (n==1)
	{
		cout<<a[0];
		return 0;
	}
	int r=0;
	while (r<n&&a[r]>=d*3)r++;
	long long ans=0;
	if (r==n)
	{
		ans+=a[0]-d;
		ans+=a[1]-d;
		for (int i=2;i<n;i++)
			ans+=(a[i]-2*d);
	}
	else 
	if (r==0)
	{
		if (a[0]>2*d&&a[1]>2*d)
		{
			ans+=a[0]-d;
			ans+=a[1]-d;
		}
		else ans+=a[0];
	}
	else
	{
		int k=2;
		if (r<n&&a[r]>2*d)
		{
			k--;
			ans+=a[r]-d;
		}
		if (r+1<n&&a[r+1]>2*d)
		{
			k--;
			ans+=a[r+1]-d;
		}
		for (int i=0;i<k;i++)
			ans+=a[i]-d;
		for (int i=k;i<r;i++)
			ans+=a[i]-2*d;
	}
	cout<<ans;
}