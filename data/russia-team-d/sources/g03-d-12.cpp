#include<iostream>
#include<algorithm>
#include <fstream>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
long long n,d,i,a[100002],s,mi;
int main()
{
	fin>>n>>d;
	for(i=1;i<=n;i++)
	{
		fin>>a[i];
		if(a[i]<mi || i==1)
			mi=a[i];
	}
	for(i=mi;i>=1;i--)
	{
		if(i*n<=d)
		{
			fout<<i<<endl;
			break;
		}
	}
	return 0;
}
