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
	long long n1=n;
	long long q=sqrt(double(n));
	vector <long long> v;
	for (long long i=3;i<=q+4;i++)
	{
			while ((n%i==0))
			{
				v.push_back(i);
				n/=i;
			}
	}
	reverse(v.begin(),v.end());
	int j=0;
	long long ans=n1;
	long long w=n1;
	if (k==0)
	{
		ans=(w+1)/2;
	}
	else
	{
	long long h=v.size()/k;
	long long qq=v.size()%k;
	int kol=0;
	
	long long z=1;
	for (int i=0;i<v.size();i++)
	{
		if (kol>=qq+h)
		{
			j=i;
			ans/=z;
			w/=z;
			ans*=(z+1)/2;
			break;
			
		}
		else
		{
			z*=v[i];
			kol++;
		}
	}
	kol=0;
	z=1;
	for (int i=j;i<v.size();i++)
	{
		z*=v[i];
		kol++;
		if (kol==h)
		{
			ans/=z;
			w/=z;
			ans*=(z+1)/2;
			z=1;
			kol=0;
		}
	}

	ans*=(w+1)/2;

	}
	cout<<ans<<endl;
	return 0;
}