#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;
ifstream fin("sochi.in");
ofstream fout("sochi.out");
long long n,d,a[100002],s,i,j,k,mx;
int main()
{
	fin>>n>>d;
	for(i=1;i<=n;i++)
		fin>>a[i];
	sort(a+1,a+n+1);
	s=a[n];mx=a[n];
	for(i=n-1;i>=1;i--)
	{
		s+=a[i];s-=2*d;
		if(s>mx)
			mx=s;
	}
	fout<<mx<<endl;
	return 0;
}