#include<iostream>
#include<fstream>
using namespace std;
ifstream fin("che.in");
ofstream fout("che.out");
long long a[300002],r,n,i,s,k,b,j;
int main()
{
	fin>>n>>r;
	for(i=1;i<=n;i++)
		fin>>a[i];
	j=1;
	for(i=1;i<n;i++)
	{
		while(a[j]-a[i]<=r)
			j++;
		k+=n-j;
	}
	fout<<k<<endl;
	return 0;
}