#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main() {
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	long long mass[100001],n,i, d,ans = 9999999,z;
	cin >> n >> d;
	z = 0;
	for(i = 0; i < n; i++)
	{
		cin >> mass[i];
		z+=mass[i];
	}
	sort(mass, mass + n);
	if(z <= d)
	{
		cout << mass[0];
		return 0;
	}
	z = mass[0];
	ans = mass[0];
	for(i = 1; i < n; i++)
	{
		int t = (d-z)/(n-i);
		if((d-z)%(n-i)!=0)
			t++;
		if(t > mass[i]- z && t < mass[i] + z)
		{
			z+=t;
			if(t < ans)
				ans = t;
		}
		if(t > mass[i] + z)
		{
			z+=mass[i];
		}
		if(t < mass[i] - z)
		{
			z+=t;
			if(t < ans)
				ans = t;
		}
	}
	cout << ans;
}