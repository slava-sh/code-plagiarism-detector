#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("sochi.in");
ofstream fout("sochi.out");
long long n,d,a[100002],s,i,j,k;
int main()
{
	fin>>n>>d;
	for(i=1;i<=n;i++)
		fin>>a[i];
	if(n==1)
	{
		fout<<a[1]<<endl;
		return 0;
	}
	sort(a+1,a+n+1);
	i=1;
	while(a[i]<2*d)
		i++;
	k=i;
	for(i=k;i<=n;i++)
		s+=a[i];
	s-=(n-k)*d*2;
	fout<<s<<endl;
	return 0;
}