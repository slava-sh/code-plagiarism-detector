#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("sochi.in");
ofstream fout("sochi.out");
int n,d,a[100002],i,max0;
long long s;
int main()
{
	fin>>n>>d;
	for(i=0;i<n;i++)
	{
		fin>>a[i];
		if(a[i]>max0)
			max0=a[i];
		if(a[i]>=d)
		{
			i--;n--;
		}
		if(a[i]>=3*d)
		{
			s+=a[i]-(2*d);
			i--;n--;
		}
	}
	if(n==0)
	{
		if(s!=0)
			s+=2*d;
		if(s==0)
			s+=max0;
	}
	if(n==1)
		s+=a[0];
	if(n>1)
	{
		int max1i, max2i, max=-1, max1, max2;
		for (i=0; i<n; i++)
			if (a[i] > max) {
				max1i = i; max = a[i];
			}
		a[max1i] = -1;
		max1 = max; max = -1;
		for (i=0; i<n; i++)
			if (a[i] > max)
			{
				max = a[i]; max2i = i;
			}
		max2 = max;
		s+=max1+max2;
		s-=2*d;
	}
	fout<<s<<endl;
	return 0;
}