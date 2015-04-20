#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("che.in");
ofstream fout("che.out");
int a[300002],r,n,i,k=0,j;
int main()
{
	fin>>n>>r;
	for(i=1;i<=n;i++)
		fin>>a[i];
	j=1;
	for(i=1;i<n;i++)
	{
		while(a[j]-a[i]<=r && j<=n)
			j++;
		k+=n-j+1;
	}
	fout<<k<<endl;
	return 0;
}