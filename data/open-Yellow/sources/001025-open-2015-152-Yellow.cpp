#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
long long a[112345];
long long n;
long long ch(long long i,long long j,long long col)
{
	if ((i<0)||(i>=n))
		return 0;
	if (a[i]!=a[j])
	{
		if (a[j]!=col)
			return 0;
		if (a[j]==col)
			return -1;
	}
	else
	{
		if (a[j]!=col)
			return 1;
		if (a[j]==col)
			return 0;
	}
}

long long ch2(long long i,long long col)
{
	if ((i<=0)||(i>=(n-1)))
		return 0;
	if (a[i-1]==a[i+1])
	{
		if ((a[i]!=col)&&(a[i-1]==col))
		{
			return -1;
		}
	}
}


int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	
	cin>>n;
	
	for (long long i=0;i<n;i++)
		cin>>a[i];
	long long ans=1;
	for (long long i=1;i<n;i++)
	{
		if (a[i]!=a[i-1])
		{
			ans++;
		}
	}
	long long q;
	cin>>q;
	for (long long qq=0;qq<q;qq++)
	{
		long long p,c;
		cin>>p>>c;
		p--;
		ans+=(ch(p,p-1,c)+ch(p,p+1,c));
		a[p]=c;
		cout<<ans<<endl;
	}
	return 0;
}