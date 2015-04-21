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



int main()
{
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	long long n,k;
	cin>>n>>k;
	
	k--;
	long long r=1;
	while ((k>0)&&(n%2==0))
	{
			k--;
			n/=2;
	}
	double v=pow(n,1.0/k);
	long long h=v;
	long long ans=n;
	r=1;
	for (int i=0;i<n;i++)
	{
		if (k==0)
		{
			break;
		}
		long long y=h-i;
		if (y>2)
		{
			while ((k>0)&&(n%y==0))
			{
				k--;
				r*=(y+1)/2;
				ans/=y;
			}
		}
		y=h+i;
		if (y>2)
		{
			while ((k>0)&&(n%y==0))
			{
				k--;
				r*=(y+1)/2;
				ans/=y;
			}
		}
	}
	cout<<ans*r<<endl;
	return 0;
}