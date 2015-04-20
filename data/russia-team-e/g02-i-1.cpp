#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("sochi.in");
ofstream fout("sochi.out");
long long n,d,a[100002],s,i;
int main()
{
	fin>>n>>d;
	for(i=0;i<n;i++)
	{
		fin>>a[i];
		if(a[i]<=d)
		{
			i--;n--;
		}
		if(a[i]=>3*d)
		{
			s+=a[i]-(2*d);
			i--;n--;
		}
	}
	if(n==0)
		s+=2*d;
	if(n==1)
		s+=a[0];
	if(n>1)
	{
		sort (a, a+n);
		s+=a[n-1]+a[n-2];
		s-=2*d;
	}
	fout<<s<<endl;
	return 0;
}