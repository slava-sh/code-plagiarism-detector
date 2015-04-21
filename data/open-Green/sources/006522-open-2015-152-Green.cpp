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
	int n,k;
	cin>>n>>k;
	
	k--;
	int r=1;
	if (k==0)
	{
		cout<<(n+1)/2<<endl;
		return 0;
	}
	while ((k>0)&&(n%2==0))
	{
			k--;
			n/=2;
	}
	if (k==0)
	{
		cout<<(n+1)/2<<endl;
		return 0;
	}
	double v=pow(n,1.0/(k+0.8))+1;
	if (n>10000)
	{
		v+=(rand()%100-50;
	}
	int h=v;
	int ans=n;
	r=1;
	for (int i=0;i<n;i++)
	{
		if (k==0)
		{
			break;
		}
		int flag=0;
		int y1=h+i;
		int y=h-i;
		while (flag==0)
		{
			flag=1;
			if (y1>2)
			{
				if ((k>0)&&(n%y1==0))
				{
					flag=0;
					k--;
					r*=(y1+1)/2;
					n/=y1;
				}
			}

			if (y>2)
			{
				while ((k>0)&&(n%y==0))
				{
					flag=0;
					k--;
					r*=(y+1)/2;
					n/=y;
				}
			}
		}
	}
	if (n!=1)
	{
		
		r*=(n+1)/2;
		n=1;
	}
	cout<<r<<endl;
	return 0;
}