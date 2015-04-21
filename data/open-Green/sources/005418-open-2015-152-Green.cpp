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
	double v=pow(n,1.0/(k+1))+1;
	double sq=pow(n,.5))+1;
	int flag=1;
	long long z=1;
	while (flag==1)
	{
		if (k==0)
			flag=0;
		else
		{
			double sq=pow(n,.5))+1;
			int sq2=sq;
			for (int i=3;i<sq2;i++)
			{
				if (n%i==0)
				{
					while ((k>0)&&(n%i==0))
					{
						z*=i;
						n/=i;
						if (z>v)
						{
							ans/=z;
							
							r*=(z+1)/2;
							k--;
							z=1;
						}
					}
				}
			}
		}
	}
	if (n>1)
	{
		r*=(n+1)/2;
	}
	cout<<r<<endl;
	return 0;
}