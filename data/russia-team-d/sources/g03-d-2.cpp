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
	for(i=mn;i>=1;i--)
		if(i*(n+1)<=m)
		{
			fout<<i<<endl;
			return 0;
		}
	return 0;
}