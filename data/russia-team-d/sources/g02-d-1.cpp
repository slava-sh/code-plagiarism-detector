#include <iostream>
#include <algorithm>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("fence.in");
ofstream fout("fence.out");
long long n,i,k,a[100005],m,t;
long long mini(long long a, long long b)
{
	if(a>=b)
		return b;
	return a;
}
long long maxi(long long a, long long b)
{
	if(a<=b)
		return b;
	return a;
}
int main()
{
	fin>>n>>k;
	for(i=0;i<n;i++)
		fin>>a[i];
	sort(a,a+n); m=a[0];
	for(i=0;i<n-1;i++)
	{
		t+=maxi(a[i]-t,m);
		m=mini((k-t)/(n-i-1),m);
	}
	fout<<m<<endl;
	return 0;
}