#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("che.in");
ofstream fout("che.out");
int n,r,i,a[300000],j=1,k;
int main()
{
	fin>>n>>r;
	for(i=1;i<=n;i++)
		fin>>a[i];
	for(i=1;i<n;i++)
		for(;j<=n;j++)
		{
			if(a[j]-a[i]>r)
			{
				k+=(n-j)+1;
				break;
			}
		}
	fout<<k<<endl;
	return 0;
}