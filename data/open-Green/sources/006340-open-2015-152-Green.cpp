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
	if (k==0)
	{
		cout<<(n+1ll)/2<<endl;
		return 0;
	}
	while ((k>0)&&(n%2==0))
	{
			k--;
			n/=2ll;
	}
	if (k==0)
	{
		cout<<(n+1ll)/2ll<<endl;
		return 0;
	}
	double v=pow(n,1.0/(k+1ll))+1;
	long long h=v;
	long long ans=n;
	r=1ll;
	for (long long i=0;i<n;i++)
	{
		if (k==0)
		{
			break;
		}
		int flag=0;
		long long y1=h+i;
		long long y=h-i;
		while (flag==0)
		{
			flag=1ll;
			if (y1>2)
			{
				if ((k>0)&&(n%y1==0))
				{
					flag=0;
					k--;
					r*=(y1+1ll)/2;
					n/=y1;
				}
			}

			if (y>2)
			{
				while ((k>0)&&(n%y==0))
				{
					flag=0;
					k--;
					r*=(y+1ll)/2;
					n/=y;
				}
			}
		}
	}
	if (n!=1)
	{
		
		r*=(n+1ll)/2;
		n=1;
	}
	cout<<r<<endl;
	return 0;
}