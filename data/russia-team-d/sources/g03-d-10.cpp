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
		fin>>a[i];
	sort(a+1,a+n+1);
	for(i=1;i<=n-1;i++)
		s+=a[i+1]-a[i];
	s+=m-a[n];
	if(s/(n-1)>a[1])
		fout<<a[1]<<endl;
	else
		fout<<s/(n-1)<<endl;
	return 0;
}