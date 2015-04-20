#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
long long n,m,a[100002],mn,i,s;
int main()
{
	fin>>n>>m;
	for(i=1;i<=n;i++)
	{
		fin>>a[i];
		if(a[i]<mn || i==1)
			mn=a[i];
	}
	if(mn<m/n)
		fout<<mn<<endl;
	else
		fout<<m/(n+1)<<endl;
	return 0;
}