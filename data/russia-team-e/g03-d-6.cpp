#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
long long n,m,a[100002],mn,i;
int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)
	{
		fin>>a[i];
		if(i==1)
			mn=a[i];
		else
		{
			if(a[i]<mn)
				mn=a[i];
		}
	}
	if(n==1)
	{
		fout<<a[1]<<endl;return 0;
	}
	if(m/n>mn)
		fout<<mn<<endl;
	else
	{
		if((m-mn)/(n-1)<=mn)
			fout<<(m-mn)/(n-1)<<endl;
		else
			fout<<mn<<endl;
	}
	return 0;
}